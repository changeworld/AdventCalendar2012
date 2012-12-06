= 5日目 単体で使えるIntelliTrace Collector(1) @<href>{https://twitter.com/kkamegawa,@kkamegawa}
@<href>{http://atnd.org/events/34118/,ALM Advent Calender}5日目への参加記事になります。 


IntelliTraceはUltimateエディションでしか使えませんが、障害解析に強力な味方となってくれます。しかし、本番環境ではVisual Studioをインストールするなんてことはできません。IISでクラッシュするアプリケーションであれば、クラッシュダンプを採取するための@<href>{http://support.microsoft.com/kb/286350/ja,adplus}や@<href>{http://support.microsoft.com/kb/919791/ja,Debug Diag}を使用するという方法もありますが、マネージドコードであればIntelliTrace Collectorを使用する方法もあります。

IntelliTrace Collectorは単体で動作するIntellitrace収集ツールです。インストーラーを実行して、システムを変更することもありません。実行ファイルそのものはMicrosoftのダウンロードセンターから無料で入手できます。以下からダウンロードして順番に見ていきましょう。

@<href>{http://www.microsoft.com/ja-jp/download/details.aspx?id=30665,Download: Visual Studio IntelliTrace コレクター - Microsoft Download Center - Download Details}

実行すると、以下のライセンス確認の画面が表示されます。
//image[1][ライセンス確認画面]

展開先を選択すればIntelliTraceCollector.cabというファイルができます。OSのExpandコマンドで展開します。Explorerで展開するとフォルダが展開されないため、必ずコマンドプロンプトで行う必要があります。
//image[2][IntelliTraceCollector.cabの展開]

//emlist{
c:\temp>expand IntellitraceCollector.cab -F:* c:\temp
//}


IntelliTrace Collectorのいい点としては以下の点に尽きるでしょう。
 * 軽量(2MBのコンパクトサイズ)
 * 実行にVisual Studioのライセンスはいらない(ただし、解析にはUltimateが必要)
 * コマンドで開始/終了が指定できるため、タスクスケジューラーで特定の時間(発生しやすい時間など)のみ自動的に採取ということも可能(スナップショットをちょっと工夫する必要があるかも)

ただし、IISのアプリケーションプールはどんな権限で動いているかわからない(通常はIISAPPPOOL\DefaultAppPool)ので、IntelliTrace Collectorが採取データを格納するフォルダのアクセス権を適切に設定する必要があります。また、採取データによっては大量データ採取になるため、SSDやRAID0などの高速なドライブにしましょう。

通常設定ではIISのワーカープロセスが読み取れない可能性があるので、Intellitrace Collectorを展開したフォルダに対してデフォルトのアプリケーションプールの読み取り権限を付けます。もちろんアプリケーションプールが特定のアカウントで実行されている場合、そのアカウントに対して読み取り権限を付けてください。
//emlist{
c:\>icacls c:\temp /grant "IIS APPPOOL\DefaultAppPool":(RX)
//}


次に、データをD:\Collectorフォルダに格納する場合、以下のようにicaclsコマンドでNTFSセキュリティを変更しておく必要があります。
//emlist{
c:\>icacls D:\Collector /grant "IIS APPPOOL\DefaultAppPool":(F)
//}

IntelliTraceはPowerShellもしくはIntelliTraceCPコマンドで制御することができます。PowerShellの場合、Set-ExecutionPolicy Remotesignedを忘れずに。x64用のIISでは64bitのPowerShellを、64bit OSでも32bitのアプリケーションプールを採取する場合は32bit版PowerShellを「管理者として起動」します。

Powershellのモジュールをインポートするとコマンドレットが使えるようになります。
//emlist{
PS c:\temp>import-module Microsoft.VisualStudio.IntelliTrace.PowerShell.dll
//}

どんなコマンドレットが追加されているか、get-commandで見てみましょう。
//emlist{
PS C:\temp>get-command *Intelli*
//}
//image[3][追加されたコマンドレット]


重要なのは以下の三つです。
//emlist{
ログ採取開始
Start-IntelliTraceCollection <アプリケーションプール名> <プラン名> <IntelliTraceログ出力先>
スナップショット採取
Checkpoint-IntellitraceCollection <アプリケーションプール名>
停止
Stop-IntelliTraceCollection <アプリケーションプール名>
//}
ログ採取開始して、必要だと思ったところで、スナップショットを採取、終わったら停止、という流れになります。Start-IntelliTraceCollectionで指定したフォルダにitraceファイルが生成されているので、Visual Studioで読み込んでください。シンボルもあれば自動的にわかります。

「プラン名」とはIntelliTraceが採取する情報の種類を定義したxmlファイルです。同じフォルダにcollection_plan.ASP.NET.default.xmlとcollection_plan.ASP.NET.trace.xmlの二種類のファイルがあります。

collection_plan.ASP.NET.default.xmlがVisual Studioでも設定されているIntelliTraceの初期状態です。collection_plan.ASP.NET.trace.xmlはより詳細に採取します。traceでは15%以上の性能低下があるとされています。本番環境で採取する場合、カスタマイズはほぼ必須と思ってください。

XMLをいちいちやるのは大変だ、と思っているあなた。codeplexに@<href>{http://intellitracecpconfig.codeplex.com/,IntelliTrace Plan Configurator}というソフトがあります。非常にシンプルなUIです。

起動すると、以下のような画面が表示されます。
//image[4][IntelliTrace Plan Configuratorの起動画面]

FileメニューのOpenから、collection_plan.ASP.NET.default.xmlを読み込んでください。こんな風に設定を変更することができます。見たことありますよね。そう、これはVisual StudioのIntelliTraceのダイアログと同じです。
//image[5][トレースできるイベントの一覧]

残念ながら日本語対応ではありませんが、Visual Studioと対比させればわかりやすいと思います。

最後にTIPSです。

 * 例外から原因がある程度分かっている場合、可能な限り採取イベントを絞りましょう。
 * 一つのアプリケーションプールで複数のアプリケーションを共存させている場合、解析しづらくなるので、可能であれば対象のアプリケーションを分割しましょう。
 * IntelliTraceのログの上限を小さくしましょう(100MBとか)。

Visual Studio 2012 update1でSharePointにも対応したそうです。また、System Center Operations Manager 2012 SP1にはIntelliTraceのitraceファイルを出力する、という機能もできたそうです。もちろんOperations Manager単独では無理で、Visual Studioは必須となります。インストールなどの序盤はこれで終了です。長くなったので、(2)に続きます。

