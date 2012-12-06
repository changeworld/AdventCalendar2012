= 3日目 Windows Server 2012にTeam Foundation Server 2012をシングルサーバー構成で構築する @<href>{https://twitter.com/libaty,@libaty}
「@<href>{http://atnd.org/events/34118/,ALM Advent Calender}」３日目への参加記事になります。 


ALMを実現するためには何かしらのツールが必要なことは言うまでもありません。 

世の中には数多のツールが存在していますが、私の得意分野はVisual StudioやEclipse等の開発環境と シームレスに連携可能なTeam Foundation Serverです。 


Team Foundation ServerはWindows Server１台（状況によりWindows Clientでも可能）あれば構築できるため、 ALMを実践していくためには非常に簡単に利用し始めることができます。 


※TFSについては「一人きままにAdvent Calender」をしているこちらのブログの記事が詳しいのでそちらを参照ください。 

@<href>{http://softwareengineeringplatform.com/articles/author/tomohn/,長沢智治のブログ}


Team Foundation Server 2012もWindows Server 2008やWindows Server 2008 R2であれば 「標準構成」と言われる構成（TFS 2012のウィザードメニュー名では「標準の単一サーバー」）を行うことで SharePoint Foundation,SQL Server Reporting Servicesなどを利用したフルセットの環境を構築することができますが、Windows Server 2012にインストールする場合にはちょっとひと手間をかけてあげる必要があります。 

これは、Windows Server 2012には、Team Foundation Server 2012のインストールメディアに含まれている SharePoint Foundation 2010をインストールすることができないために発生します。 

※Team Foundation Server 2012 RTMのインストールイメージでの話となります。 

今後、インストールイメージのアップデート等によって状況が変更される可能性はあります。 


では、Windows Server 2012にTeam Foundation Server 2012をシングルサーバー構成でセットアップする方法をご紹介します。 


== 必要なソフトウェア 
Windows Server 2012にTeam Foundation Server 2012をセットアップするには以下のソフトウェアが必要となります。 

 * Windows Server 2012（Standard Edition, Enterprise Edition問わず） 
 * SQL Server（2008 or 2008 R2 or 2012、レポート機能を利用する場合にはExpress Edition以外） 
 * SharePoint Foundation 2013 
 * Team Foundation Server 2012 


この中で、SharePoint Foundation 2013は執筆日現在（2012/12/03）では、ダウンロード場所の発見が少々難しいので こちらからダウンロードしてください。「@<href>{http://www.microsoft.com/ja-jp/download/details.aspx?id=35488,Microsoft Download Center : SharePoint Foundation 2013のダウンロード}」 


== Windows Server 2012のセットアップ 
OSのインストール後に必要な作業だけピックアップします。 

SQL Server Reporting Servicesを利用する場合には、おおむね以下のような追加機能が必要となります。 

 * .NET Framework 3.5 
 * Internet Information Services 
 * ASP.NET 3.5 
 * ASP.NET 4.5（TFS 2012で利用） 


各製品のインストール時に自動構成してくれるものもありますが、これらについては事前に機能を追加しておいた上で Windows Updateによりすべてを最新化しておくことをお勧めします。 


== SQL Serverのセットアップ 
TFS 2012を利用するためには、SQL Serverでは最低限以下の機能がセットアップされている必要があります。 

 * データベースエンジンサービス 
 * フルテキスト検索（SQL Server 2008またはSQL Server 2008 R2の場合） 
 * 検索のためのフルテキスト抽出とセマンティック抽出（SQL Server 2012の場合） 
 * Analysis Services 
 * Reporting Services（SQL Server 2008またはSQL Server 2008 R2の場合） 
 * Reporting Services - ネイティブ（SQL Server 2012の場合） 
 * クライアントツール接続 
 * 管理ツール（完全） 

※管理ツールはTFS 2012をインストールしたサーバーでSQL Server Management Studioを利用しない場合には必要ありません。 

※TFS 2012をインストールしたサーバーでSQL Server Analysis Servicesに接続しない場合は「管理ツール（基本）」でも問題ありません。 

//image[1][セットアップする SQL Server 2012 の機能 1/2]
//image[2][セットアップする SQL Server 2012 の機能 2/2]

また、SQL Serverの照合順序は「@<em>{CI_AS系}」または「@<em>{BIN系}」のものを選択するようにしましょう。 

下記の図はJapanese_XJIS_100を選択した場合のものです。
//image[3][SQL Server 2012 の照合順序]

レポーティングサービスの構成では「Reporting Services ネイティブモードでインストールと構成」を選択しておきます。
//image[4][Reporting Services の構成]

== SharePoint Foundation 2013のセットアップ 
TFS 2012をインストールする前にSharePoint Foundation 2013を @<em>{事前インストール} しておきます。 

TFS 2012をWindows Server 2012上でシングルサーバー構成にするためには一番のポイントとなる部分です。 

※事後インストールでも構成ができないわけではありませんが、 TFS 2012のセットアップを最短ルートで終わらせるために事前インストールすることをお勧めします。 


SharePoint Foundation 2013のインストーラーを立ち上げた後、まずはじめに「ソフトウェア必須コンポーネントのインストール」を選択します。 

SharePoint Foundation 2013を動作させるために必要なソフトウェアを「@<em>{ダウンロード}」してインストールを行ってくれますが、 実に様々なソフトウェアが必要となるため、多少時間がかかります。 

また、途中何回か再起動を求められますので（私の環境では２回）、都度再起動を行ってインストールを継続してください。 

なお、必須コンポーネントがすべて入っていない場合には、ウィザードの最後にでる画面をよくよく見ると 「インストールを完了するにはコンピュータを再起動する必要があります」といったメッセージが表示されていますのでよく確認を行うようにしてください。 
//image[5][コンピュータを再起動する場合がある]

必須コンポーネントのインストールが終了したら続けて「SharePoint Foundationのインストール」を選択します。 

SharePoint Foundation 2013のセットアップでサーバーの種類は「完全」を選択してインストールを行います。 
//image[6][SharePoint Foundation 2013のセットアップ]

インストールは数分で完了します。その後は引き続き、「構成ウィザードの実行」を行います。 

SharePoint 製品構成ウィザードでは以下の設定を行っていきます。 

 * サーバーファームへの接続 ： 新しいサーバーファームの作成 
 * 構成データベースの設定 ： データベースサーバーに自身のコンピュータ名を設定 
 * データベースアクセスアカウントの設定 ： TFSを実行する予定のユーザー名（tfsserviceなど）を設定 

これら以外はデフォルトのままで構いません。 

製品構成ウィザードが終了すると続けて「ファーム構成ウィザード」がブラウザで表示されます。 

ここでは、「このウィザードを使用してファームを構成する」の「ウィザードの開始」を実行します。 
//image[7][ファーム構成の初期設定ウィザード]

サービスの設定ページは以下のように設定します。 

 * サービスアカウント ： 既存の管理アカウントを使用する 
 * 利用するサービス ： 必要なものを選択する 

ウィザードが終了すると「サイトコレクションの作成」画面が表示されますが、ここで処理を終了してブラウザを閉じてしまって構いません。 

以上で、SharePoint Foundation 2013のインストールと設定は終了です。 


== Team Foundation Server 2012のセットアップ 
最後にようやくTFS 2012のセットアップです。 

インストールはすぐに終了して、「Team Foundation Server 構成センター」が立ち上がります。 

@<em>{順番通りに行う場合はここもポイントです。}

はじめに「SharePoint 製品用の拡張機能の構成」を選択してウィザードを開始しましょう。 
//image[7][SharePoint 製品用の拡張機能の構成]

特に設定することはないので、ウィザードの通りに設定を進めていきます。 

設定作業もすぐに終了します。 


SharePoint 製品用の拡張機能の構成が終了したらいよいよTFSそのものの構成を行います。 

もう一度、Team Foundation Server 構成センターで今度は標準の単一サーバーではなく「詳細」を選択して「ウィザードの開始」を行います。 

※通常、シングルサーバー構成の場合は「標準の単一サーバー」を選択しますが、セットアップ済みのSharePoint Foundation 2013を利用するためには今回のウィザードが必要です。 


詳細構成ウィザードでは以下のように選択していきます。 

 * データベース ： SQL Serverインスタンスを自身のコンピュータ名に設定します。 
 * アカウント ： サービスアカウントはユーザーアカウントを使用するをチェックし、TFSのサービスを実行するアカウント（tfsserviceなど）を設定します。 
 * プロジェクトコレクション ： 新しいプロジェクトコレクションの作成をチェックし、チームプロジェクトコレクション名（DefaultCollectionなど）を設定します。 

これ以外についてはデフォルト値のまま、どんどん次に流してしまって構いません。 

※レポートリーダーアカウントは、チェックしないままユーザーを指定しないで進めると警告が出されますが、そのまま進めてしまっても大丈夫です。 


ウィザードに従って構成を実行すれば設定は完了です。 


以上、長々と進めてきましたが、この手順でWindows Server 2012にTeam Foundation Server 2012をシングルサーバー構成でセットアップして利用することができるようになりました。 
少人数開発であれば多くのサーバー台数は割きたくはないものです。ぜひ最新OS、最新ミドルウェアを利用した楽しいTeam Foundation Serverライフをお送りください。
