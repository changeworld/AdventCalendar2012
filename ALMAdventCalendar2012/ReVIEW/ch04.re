= 4日目 TFSからAnt実行時に設定される変数の確認方法 @<href>{https://twitter.com/__Black,@__Black}
「@<href>{http://atnd.org/events/34118/,ALM Advent Calender}」４日目への参加記事になります。 

「Microsoft Visual Studio Team Foundation Server 2012 Build Extensions」を使ってAntのBuild.xmlを記述するときに、ビルドに関する情報を使いたい時があります。

（ビルド時のフォルダとか、ビルド時に採番された番号など）

Antの中でechoを使って出力してもいいのですが、ビルド実行時のパラメータを変更することで簡単にログへ出力することができます。

事前にAntを実行するビルド定義を作成し、作成したビルド定義をVisual Studio Shellから実行する時にパラメータを一部変更します。

「パラメータ」タブを選択し、「ログの詳細度」から"Detailed"か"Diagnostic"を指定してから実行します。（ここで指定した内容は１回だけ適用されます）
//image[1][ビルドパラメータの設定]

ビルドが終了すると、ログにAnt実行時のコマンドラインが出力されます。
//image[2][ビルド結果のログ出力]


コマンドライン引数の中で、「-D」で指定されているものがTFSからAntに渡される情報になります。（-D[パラメータ名]=[値]という形式です）

使用例としては、「BuildNumber」をJarファイルのメタ情報として埋め込んでおけば、後でどのビルドで生成したものかが簡単に判別できます。
//image[3][BuildNumberをJarファイルのメタ情報として埋め込む]

注意点ですが、残念ながらEclipse+Team Exploere Everywhere(TEE)からではこの手順が使えませんので、Visual Studio Shellから実行してください。

（Eclipseから実行した場合、「パラメータ」タブがありません。TEEを使用するためにVisual Studio Shellは必須ではありませんが、1環境に1台ぐらいはインストールしておいたほうが便利だと思います。）

