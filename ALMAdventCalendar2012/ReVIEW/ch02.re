= 2日目 JavaScriptの開発、テストを効率化したい @<href>{https://twitter.com/atttakai,@atttakai}
「@<href>{http://atnd.org/events/34118/,ALM Advent Calender}」２日目への参加記事になります。

ソフトウェアを開発する際にテスト開発、実施、管理をもっと効率化したいとずっと考えています。
幸いにも自分たちの開発チームもTFSを導入することができたことで、Test Managerなどを利用して開発チームのテスト実施や管理が効率よく行えるようになってきています。
ありがたいことです。

そんな中、JavaScriptの開発はJSLintでコード検証、JsUnitでテストをしています。
悪くはないんですが、もう少し効率良くしたい、と考えていたときにChutzpahに出会いました。


== Chutzpahで単体テスト
Visual Studio 2012ではソリューションビルド時に使用可能なテストを検出し、「テスト エクスプローラー」に表示・実行してくれます。

@<href>{http://msdn.microsoft.com/ja-jp/library/vstudio/hh270865.aspx/,テスト エクスプローラーを使用した単体テストの実行}

Chtzupahを利用すると、ソリューション内のJasmine、QUnitのテストを検出、実行して、結果をテストエクスプローラーに表示してくれます。

@<href>{http://visualstudiogallery.msdn.microsoft.com/f8741f04-bae4-4900-81c7-7c9bfb9ed1fe/,Chutzpah Test Adapter for Visual Studio 2012}　


1. ChutzpahはVisual Studioの「拡張機能と更新プログラム」からもインストールできます。
//image[1][Chutzpahをインストールする]

2. ソリューションをビルドします。
//image[2][ソリューションをビルドする]



Visual Studio Ultimate を利用している場合「ビルド後にテストを実行」をオンにしておくと、ビルドする度にテストをしてくれるのでモチベーションを維持して開発できます。
細かいことかもしれませんが、実際に使ってみて思考を中断されないことがかなり良かった。

何度か使ってみましたが、ファイルパスに日本語が入っていると正しく動作しないようです。
ソフトウェアの保守をしていく上で、将来的にはJavaScriptのテストも自動ビルドに組み込みたいですね。


== JSLintでコード検証
JSLintも拡張機能としてVisual Studioにインストールできます。

今まで、Web上の @<href>{http://www.jslint.com/,JSLint} などでペタペタ貼り付けてチェックしていたんですが、徐々に利用頻度が落ちていきます。

入れておくとビルドするたびにチェックして、ダメ出しをしてくれるように設定できるのでとてもありがたいです。

開発も佳境に入った時期で入れると心をへし折られるので、開発の初期に入れておくことをお勧めします。

また他の開発者にも最低限の規約として守ってもらう意味でも重要です。

@<href>{http://jslint4vs2010.codeplex.com//,JSLint for Visual Studio 2010}

1. Visual Studioの「拡張機能と更新プログラム」のオンラインからJSLintをインストールします。
//image[3][JSLintをインストールする]


2. ツールの「JS Lint Options...」を選択します。
//image[4][オプション画面を表示する]


3. JSLintのオプションを設定します。

 *「Visual Studio Options」では以下のような設定ができます。
 ** チェック対象のファイル
 ** ビルド時にチェックする
 ** エラーがあった場合ビルドをキャンセル
 *「JSLint Options」ではWeb上のJSLintオプションと同じ設定ができます。
 ** evalを許可しない
 ** ==と!=を許可しない
//image[5][オプションを設定する]

4.設定したオプションはインポート、エクスポートして他の開発者と共有できます。


== まとめ
最近のアップデートでコードUIテストにクロスブラウザーのテストがサポートされるなど、継続的な品質向上にも力を入れているように感じます。

@<href>{http://www.microsoft.com/visualstudio/jpn/visual-studio-update/,Visual Studio 2012 Update 1}

今後はスレート、スマートフォンなどのモバイルのテストに対しても力を入れてほしいですね。
