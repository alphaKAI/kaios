kaios
==================
  
  
概要
------------------
OSとかかいてあるけどターミナルエミュレータもどきっぽいなにか  
ぜんぜん実装できてません
Cをコンパイルする環境があればうごくかと思われます  
  
    
機能
-----------------
実装されているコマンド  
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
  
  
注意事項
-----------------
仕様としてechoはリダイレクト未対応ですしなおかつダブルクオーテーションで囲っても空白をシカトします　 
  
  
LICENCE
-----------------
本プログラムは GPLv3 LICENSEです  
GPLv3については同梱のLICENSEフォルダのLICENSE(原文)/LICENSE_ja(日本語訳)をご覧ください  
COPYRIGHT (C) α改 @alpha_kai_NET 2012-2013 http://alha-kai-net.info  
  
  
つかいかた
-------------------
Windowsの場合  
Sugarlessのフォルダの中のbase64.hとcompiler.cmdをkaiosのルートディレクトリにコピー  
そしてcmdを起動して展開したkaiosのディレクトリ(↑この時にいた場所)に移動して  
いっかいcompiler.batを実行してからcompile.batをそのcmdで実行すればコンパイルできます  
Linuxの場合  
展開したディレクトリにターミナルで移動してcmpile.shをchmod 777で権限を与え実行コンパイルできます  
  
  
動作環境及び開発環境
--------------------
開発及び動作確認は  
Windows8 Pro x64  
Visual Studio2012 Professional(cl.exe)  
UbuntuServer 12.10 x86_64  
gcc バージョン 4.7.2 (Ubuntu/Linaro 4.7.2-2ubuntu1)  
  
  
作者 WEB SITE
-------------------
個人ブログ <http://blog.alpha-kai-net.info>  
HP <http://alpha-kai-net.info>  
Twitter <http://twitter.com/alpha_kai_net>  
Github <https://github.com/alphaKAI>  
Mail to <alpha.kai.net@alpha-kai-net.info>
  
  
COPYRIGHT (C) α改 @alpha_kai_NET 2012-2013 http://alha-kai-net.info  
COPYLEFT (C) 石橋祥太 2013 http://ishibasystems.ikaduchi.com
