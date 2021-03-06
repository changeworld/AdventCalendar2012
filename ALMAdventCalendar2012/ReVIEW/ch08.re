= 8日目 障壁のあるチームと障壁のないチーム @<href>{https://twitter.com/changeworlds,@changeworlds}
このエントリは「@<href>{http://atnd.org/events/34118,ALM Advent Calendar 2012 #TFSUG : ATND}」8日目への参加記事になります。@<br>{}昨日は @<href>{https://twitter.com/yasuohosotani,@yasuohosotani} さんの @<href>{http://yasuo.hatenablog.com/entry/2012/12/07/190222,TFS事件簿 - Yasuo&#39;s Notebook} でした。

@changeworldsこと、ちぇんわです。今回の記事は技術系の話ではございませんので、予めご容赦ください。

== ALMとは？
ALM とは Application Life cycle Management の略です。こちらには「アプリケーションソフトウェアを開発・運用するに当たり、そのライフサイクル全体を総合的に管理することでソフトウェアの品質や開発生産性、変化への対応力などを向上させようという考え方のこと。あるいはそのためのプラットフォームツールをいう。」と説明されていますが、「アプリケーションの一生をマネジメント」という@<href>{http://www.naturalsoftware.jp/blog/7926,中村薫@kaorun55}さんの説明が分かり易いと思います。

== ALMの関係者
//image[1][ALMの概要]
引用される際は日本語化されていますが、よくALMの説明として、上記画像が引用されます。

「アプリケーションの一生」と言うと、「作る(開発)」と「運用する(運用)」で考える方は多いと思います。「運用」と言うと、大抵の方がアプリケーション(コンテンツ、サービス)を開発した後のことを想定されています。しかし、アプリケーションを開発するには「要求」というフェイズもある通り、開発者、運用者以外に企画者も含まれます。

== 障壁のあるチームと障壁のないチーム
色々な場所の勉強会に参加し、ITSを使っている人に話を聞くと、TFSについてよく「GUIが良いだけであって、機能面は他のフリーのツールにも殆ど実装されている。GUIが他より優れているだけの為にお金をかけることはありえない」ということを良く聞きます。

しかし、「GUIが優れている」という要素は実はとても重要な要素なのだと私自身は認識しています。
 
 * チーム@<fn>{チーム}が同じツールを使う際にハードル(障壁)が高い
 * チーム@<fn>{チーム}が同じツールを使う際にハードル(障壁)が低い

この場合、どちらが良いと判断するでしょうか。もちろん、「如何なる状況においても、正しい答えが1つになる」というものではなく、人それぞれの考え方や現場次第、所謂「It depends(それは状況によるね).」というものだと思います。

ただ、チームの中に様々な立場@<fn>{チーム}の人が含まれるのであれば、私自身の考えではハードル(障壁)が低い方が良いのではないかと考えています。それは、ハードル(障壁)が低い方が様々な人の視点やアイデアを取り入れることが出来ると考えている為です。これはCUIではなく、GUIによる操作を行える様にした結果、PCを利用する人の数を莫大なものにしたWindowsの例でも分かると思います。

一方で、デザイナーやプランナーといった自分以外の立場の人たちに対して、使い易くない(GUIが優れていない)ツールを使うことを要求する(＝デザイナーやプランナーも○○というツールを使いこなせるべき)という態度を取る方も居られます。しかし、それを許容するという事は相手(この場合はデザイナーやプランナーといった自分以外の立場)の人も自分に対して○○すべきと要求してくることを許容しなければならないということを忘れないでください。

//footnote[チーム][デベロッパー、デザイナー、プランナー、マネージャー等]

== まとめ
あなたは“@<kw>{あなたの好み}”と“@<kw>{チームの成功}”ではどちらがより@<kw>{大事}でしょうか？

明日は@<href>{https://twitter.com/matsukawar,@matsukawar} さんです。よろしくおねがいします。