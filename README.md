kaios
==================
  
  
概要
------------------
シェルもどきです  
mainの方にはマルチプラットフォームで動く以前のKaiOSが入っています  
現在はLinux向けのを開発していますのでlinuxのほうが最新です  
ただし、linux版は書き換え途中のため動作しません(mainの方もですが)  
Windowsでなら動きますので・・・  
Ruby版の実装をはじめました  
多分これがメインになる  
Ruby製なのでプラットフォームを選びません  
  
  
機能
-----------------
実装されているコマンド  
###ruby
    echo 引数: echoです　リダイレクトなどは未実装  
		cat 引数: catです リダイレクトなどは未実装  
		cd 引数: cdです  
		date 引数(オプション): 現在時刻を表示します 任意のフォーマットに出力を変えることも可能  
		ls 引数(オプション): 引数がある場合はそのディレクトリの中を一覧表示します ない場合はカレントディレクトリを表示します  
		pwd: カレントディレクトリの絶対パスを表示します  
		help: 実装されているコマンドの一覧を表示します  
		exit: KaiOSを終了させます  
###linux
    まだコマンドは何も何も実装してない  
###main
    echo 引数:　echoです まだリダイレクトは実装していません  
    mkdir 引数:　ディレクトリを作成します  
    cd 引数:　カレントディレクトリを変更します  
    date:　時刻を表示します  
    cat 引数(ファイル名):　引数のファイルの中身を表示します  
    rename 元ファイル名 当たらしいファイル名:　ファイル名変更  
    base64 引数:　未完成です 上手く動きません  
    help: この表示です  
    osver: バージョンを知ることができます  
    exit: 終了します  
  
  
VERSION
-----------------
2013/4/2 0.0.1 alpha - 公開  
2013/4/2 0.0.3 alpha - echo mkdir cd rename実装  
2013/4/2 0.0.3FIX alpha - Linuxで動かなかったから修正  
2013/4/2 0.0.5 alpha - ls rm rmdirの実装  
2013/4/2 0.0.5_FIX alpha - 石橋氏からのプルリクエストをマージ&READNEの表記を修正&cpmile.(bat|sh)の修正改行コードをLFに統一  
2013/11/10 0.0.7 alpha - Linux向け開発を重点的にすることに ディレクトリ構造を変えた 無駄なメモリ確保を省くように切り替え 
2013/11/14 0.0.7 rv.002 alpha - 各種関数の追加(シェルの入力関連の実装)  
2013/11/16 Ruby版の実装を開始 - C言語めんどくさくなったからとりあえず先にRubyで実装することにした  
2013/11/16 Ruby版をちょっといじってcd実装したり マルチプラットフォーム向けとか言ってるのにlsの式展開してたのを修正(まだlinux依存あるけど)  
2013/11/17 KaiOS in Ruby 0.0.2 rb公開 - 様々なコマンドを実装した ただし、中途半端  
  
  
注意事項
-----------------
機能はほとんど不完全な実装です(ruby/main/linux)  
例えば、リダイレクトなど未対応ですし・・・  
  
  
LICENCE
-----------------
本プログラムは GPLv3 LICENSEです  
GPLv3については同梱のLICENSEフォルダのLICENSE(原文)/LICENSE_ja(日本語訳)をご覧ください  
Copyleft alphaKAI 2012-2013 http://alha-kai-net.info  
linux/lib/getinf.cは陰羽氏によるものでNYSLによって提供されています  
  
  
つかいかた
-------------------
####ruby
    ruby main.rbでいけます  
####main/linux
    Windowsの場合:  
    .cファイルを全部オブジェクトファイルにしてそれをリンクすれば動きます  
    Linux等の場合:  
    適切な権限をcompile.shに与えて実行すればコンパイルできます  
  
  
動作環境及び開発環境
--------------------
開発及び動作確認は  
ruby:  
Arch Linux 3.11.6-1-ARCH x86_64  
ruby 2.0.0p247 (2013-06-27 revision 41674) [x86_64-linux]  
linux,main:  
Arch Linux 3.11.6-1-ARCH x86_64  
gcc バージョン 4.8.2 (GCC)  
main:  
Windows8.1 Pro x64  
Visual Studio2012 Professional(cl.exe)  
  
   
WEB SITE
-------------------
Blog <http://blog.alpha-kai-net.info>  
HP <http://alpha-kai-net.info>  
Twitter <http://twitter.com/alpha_kai_net>  
Github <https://github.com/alphaKAI>  
Mail to <alpha.kai.net@alpha-kai-net.info>  
  
  
Copyleft (C) α改 @alpha_kai_NET 2012-2013 http://alha-kai-net.ino  
Copyleft (C) 石橋祥太 2013 http://ishibasystems.ikaduchi.com  
Copyleft (C) kagehaq 2013 kg9h.net  
