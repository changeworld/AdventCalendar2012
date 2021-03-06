= 1日目 ALMってなに？ @<href>{https://twitter.com/kaorun55,@kaorun55}
このエントリは「@<href>{http://atnd.org/events/34118,ALM Advent Calendar}」1日目への参加記事です。

今日から12/24までALMでAdvent Calendarをみんなで書いていきます。初日は「そもそもALMってなに？」といあたりを書いてみようと思います。
@<br>{}@<br>{}
「ALM」とは「Application Life cycle Management」の略で、「アプリケーションの一生をマネジメント(考えること)」だと考えています。僕が外から見て感じることは、(特にここ最近の)Microsoft自身が自社が掲げるALMの考え方に則って製品群をリリースしていることです。もちろん開発ツールであるVisual StudioやTeam Foundation Serverにもこの考え方をベースにした製品となっており、これから先のソフトウェア開発の考え方自体の参考になると考えています。

== 背景

現在のソフトウェアは「生活により密着し」「ビジネスのキーポイントとなる」そんな立ち位置ではないでしょうか。さらに「環境の変化が速くなり」数年(もしくは数か月)という単位で自分の周りの環境含めて、ソフトウェアが作る環境が変わっているのではないでしょうか。

わかりやすい例が、iPhoneをはじめとするスマートフォンや、ソーシャルゲームでしょうか。ここ数年で急激にシェアを伸ばし、人々の環境を変え、ビジネスモデルを変え、企業の規模ですら変えてしまいました。ここまで極端ではなくとも、自分の周りのソフトウェア開発のありかたが変わっていることを少しでも感じているのではないでしょうか。

上手にソフトウェアを開発する

このような背景の中で、いかに上手にソフトウェアを開発するか。という一つの指針がMicrosoftの掲げるALMの考え方だと思っています。一枚絵にすると次の図になります。これは、Visual Studioの製品紹介に含まれている画像で、Microsoftのエバンジェリストである長沢さんの講演を聞いた方は見たことがあると思います。
//image[1][Microsoft の掲げる ALM の全体図]


要するに「ソフトウェアは作って終わり。ではなく、運用してそこから得られるフィードバックを元にどんどん良くして行こう」という考え方です。Visual Studio 2012のUpdate1や、時期Windowsと言われている「Blue」が、今までと比べて短い周期で更新された製品をリリースしていることは、まさに「フィードバックを元に、より良くする」ことだと感じています。もちろんこの動きはMicrosoftだけではなく、大きな企業だけで見ても、ベータから始まったGoogleのGMailや、一年ごとにOSが更新されているAppleのOSXやiOS、稼働させながら少しずつ変化しているFacebookなどが挙げられるでしょう。

いままでは(少なからず)「作ったら終わり」という意識だったソフトウェアが「サービス」として生活に浸透することで「運用する」ことがより重要になり、開発と運用をどのようなサイクルで回し続けるかということを考えることが重要になってきているのだと思っています。

== Visual Studio

ここでやっと本題のVisual Studioになるのですが、Visual StudioやTeam Foundation Server自体がALMの考え方をベースにしているので、ツールの機能もおのずとそれをサポートする形になります。実際に使う際には、これらの開発サイクルをベースに、自分たちがどの機能を使っていて、どの機能を使っていないかを考えてみると、強みや弱みが見えてくるのではないでしょうか。

また、ALMの考え方は開発プロセスも含めている(差し替え可能)と考えているので、日本でいえばウォーターフォールとアジャイルの対立がしばしば起こりますが、そのどちらでも利用可能だと考えています。ツールよりもプロセスよりも、どうやったら上手にソフトウェアが開発できるのかということを考えてみると、また違った見方ができるのではないでしょうか。

== まとめ

新しいVisual Studio 2012やTeam Foundation Server 2012には背景となる考え方があります。その考え方を理解することで、ツールをより上手に、効率的に使うことができるでしょう。

また「変化が速い世の中」という部分に着目すると、開発に限らず、生活含めて考え方が変わってきているのが今の自分の心境です。変化を受け入れ、楽しめる生き方ができるといいですね。