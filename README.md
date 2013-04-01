kaios
==================
  
  
概要
------------------
OSとかかいてあるけどターミナルエミュレータもどきっぽいなにか  
ぜんぜん実装できてません
Cをコンパイルする環境があればうごくかと思われます  
ちなみに、この中のファイルだけじゃ動かないかもしれません(適当に作業ディレクトリからコピったので)  
  
    
機能
-----------------
実装されているコマンド
date:　時刻を表示します
cat 引数(ファイル名):　引数のファイルの中身を表示します
base64 引数:　未完成です 上手く動きません
help: この表示です
exit: 終了します
  
VERSION
-----------------
2013/4/2 0.0.1 alpha公開
  
  
注意事項
-----------------
機能の実装はまだまだなにもない  
  
  
LICENCE
-----------------
Sugarless<http://ishibasystems.ikaduchi.com/downloads/d_8/main.htmlSugarless>12 著作者 石橋祥太 / 藤代晴嵐 LICENSE: NYSL Version 0.9982  
Sugarless12はファイルを必要最低限にしてあります  
readme.txtがSugarless12フォルダにreadme.txtが入っていますのでそちらもお読みください  
本プログラムは GPLv3 LICENSEです
GPLv3については同梱のLICENSEフォルダのLICENSE(原文)/LICENSE_ja(日本語訳)をご覧ください  
COPYRIGHT (C) α改 @alpha_kai_NET 2012-2013 http://alha-kai-net.info  
  
  
つかいかた
-------------------
Windowsなら簡単です  
テキトーにSugarlessのフォルダの中のファイルをリンクなり何なりしてSugarless.libを作成して  
my_lib.cからmy_lib.libをつくってからSugarlessの中のcompiler.cmdをルートディレクトリにもってきて  
compile.batを実行すればコンパイルできます  
batなのはMakefileの書き方がわからないから  
因みに、その他のOSでは適当なコンパイラで上記の手順を踏めばできるかと(gccとかar rvなりなんなりで)    
  
  
動作環境及び開発環境
--------------------
開発及び動作確認は  
Windows8 Pro x64  
Visual Studio2012 Professional(cl.exe)  
 
  
作者 WEB SITE
-------------------
個人ブログ <http://blog.alpha-kai-net.info>  
HP <http://alpha-kai-net.info>  
Twitter <http://twitter.com/alpha_kai_net>  
Github <https://github.com/alphaKAI>  
Mail to <alpha.kai.net@alpha-kai-net.info>
  
  
COPYRIGHT (C) α改 @alpha_kai_NET 2012-2013 http://alha-kai-net.info  