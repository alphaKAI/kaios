/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	Kai OS Kernel&Main set
	Copyleft (C) α改 alpha_kai_NET 2012-2013 http://alpha-kai-net.info
	
	
	base64関数
	Sugarlessライブラリ  著作者 石橋祥太 / 藤代晴嵐　　　使用
	簡易Base64 エンコーダ/デコーダ
	LICENSE GPLv3
	copyright (C) α改 @alpha_kai_NET 2012-2013 alpha-kai-net.info 藤代晴嵐
	Special Thanks! ==> 隠しコマンド実装 : 藤城晴嵐氏 @FujishiroSeiran

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "os_s.h"
#include "base64.h"//b64
#define B64_VER 04//b64
#define PT_VER "0.0.3 alpha"

void pf(void);//b64

void about(void){
	printf("Kai OS VERSION: %s\n", PT_VER);
	printf("Copyleft (C) α改 alpha_kai_NET 2012-2013 http://alpha-kai-net.info\n");
	printf("実装されているコマンドの一覧/使い方はhelpコマンドで確認できます\n");
}

void help(void){
	printf("実装されているコマンド\n");
	printf("echo 引数:　echoです まだリダイレクトは実装していません\n");
	printf("mkdir 引数:　ディレクトリを作成します\n");
	printf("cd 引数:　カレントディレクトリを変更します\n");
	printf("date:　時刻を表示します\n");
	printf("cat 引数(ファイル名):　引数のファイルの中身を表示します\n");
	printf("rename 元ファイル名 当たらしいファイル名:　ファイル名変更\n");
	printf("base64 引数:　未完成です 上手く動きません\n");
	printf("help: この表示です\n");
	printf("osver: バージョンを知ることができます\n");
	printf("exit: 終了します\n");
}

int cat(const char *cmdstr){
	
	char name[1000];
	sscanf(cmdstr,"cat %s",name);
	
	//存在確認
	if(check(name)==1){
		if(result(name)==0){
			printf("申し訳ございません\nファイル名\"%s\"の読み込みに失敗しました\n",name);
			return 2;
		}
	}
	else{
		printf("カレントディレクトリにファイル名\"%s\"が見つかりませんでした\n",name);
		printf("ファイル名に間違えがないかご確認下さい\n");
		printf("例:example.txtをexample.ttxなどのようにしていないかご確認下さい\n");
		return 1;
	}
	
	return 0;
}

int rename_cmd(const char *cmdstr){
	char oldname[1000]={"\0"};
	char newname[1000]={"\0"};
	// char *oldname;
	// char *newname;

	sscanf(cmdstr,"rename %s %s",oldname, newname);

	if(check(oldname)==0){
		printf("エラー ファイル名\"%s\"がカレントディレクトリに存在しません\n",oldname);
	}
	else{
		if(rename(oldname,newname)==0){
			printf("%sから%sに名前を変更/移動しました", oldname, newname);
		}
		else{
			printf("名前の変更/移動に失敗しました");
		}
	}
	return 0;
}

int echo_cmd(const char *cmdstr){
	char echostr[1000];

	sscanf(cmdstr,"echo %s",echostr);
	printf("%s\n",echostr);
	return 0;
}

int mkdir_cmd(const char *cmdstr){
	char newdir[1000];

	sscanf(cmdstr,"mkdir %s",newdir);
#if _WIN32 || _WIN64
	if(_mkdir(newdir)==0){
		printf("ディレクトリ\"%s\"を作成しました\n",newdir);
	}
	else{
		printf("ディレクトリ\"%s\"の作成に失敗しました\n",newdir);
	}
#endif
#if __unix || __linux || __FreeBSD__ || __NetBSD__
	if(mkdir(newdir,777)==NULL){
		printf("%sを作成しました\n",newdir);
	}
	else {
		printf("%sを作成できませんでした\n",newdir);
	}
#endif
	return 0;
}

int cd_cmd(const char *cmdstr){
	char newdir[1000];

	sscanf(cmdstr,"cd %s",newdir);
#if _WIN32 || _WIN64
	_chdir(newdir);
#endif
#if __unix || __linux || __FreeBSD__ || __NetBSD__
	chdir(*(newdir+1));
#endif
	return 0;
}

int base64(int argc, char *argv1, char *argv2, char *argv3){

	int num;
	int sum;
	char *str;
	char *ind;
	int i;
	int rl;
	int sm;
	int za;
	int asma;
	asma=0;
	za=0;
	rl=0;
	if(argc==1){
		pf();
		return 1;
	}

	if(strcmp(argv1,"--help")==0 && argc!=2){
		sum=1;
		asma=1;
	}
	if(strcmp(argv1,"-fe")==0 || strcmp(argv1,"-fd")==0){
		if(argc!=4){
			sum=1;
			za=1;
		}
	}
	if(strcmp(argv1,"-e")!=0 && strcmp(argv1,"-d")!=0 && strcmp(argv1,"-t")!=0 && strcmp(argv1,"-v")!=0 && strcmp(argv1,"--help")!=0 && strcmp(argv1,"-fe")!=0 && strcmp(argv1,"-fd")!=0){
		sum=2;
		asma=1;
	}
	//-v
	if(strcmp(argv1,"-v")==0){
		printf("簡易base64エンコーダ/デコーダ VER:0.0%d\n", B64_VER);
		printf("作者:α改\n\n");
		return 0;
	}

	if(asma==1 || za==1){
		if(strcmp(argv1,"-e")==0 || strcmp(argv1,"-d") || strcmp(argv1,"-t")==0){
			sum=2;
		}
		if(argc!=0 && sum==1){
			printf("引数の数が不正です\n\n");
		}
		else if(argc!=0 && sum==2){
			printf("オプションが不正です\n\n");
		}
		//使い方
		pf();

		printf("終了します\n");
		return argc;
	}
	else{//-e
		if(strcmp(argv1,"-e")==0){
			str=c2b(argv2, strlen(argv2), 0);
			if(str==NULL){
				printf("文字列のエンコードに失敗しました\n");
				return 6;
			}
			num=1;
		}//-d
		else if(strcmp(argv1,"-d")==0){
			str=b2c(argv2, NULL);
			if(str==NULL){
				printf("文字列のデコードに失敗しました\n");
				return 3;
			}
			num=2;
		}//-t
		else if(strcmp(argv1,"-t")==0){
			str=malloc((strlen(argv2) * 4 + 24) * sizeof(char));
			sprintf(str, "＿");
			for(num = 0; num < strlen(argv2) / 2 + 2; num++) strcat(str, "人");
			sprintf(str, "%s＿\n＞　%s　＜\n￣Y", str, argv2);
			for(num = 0; num < strlen(argv2) / 2; num++) strcat(str, "^Y");
			strcat(str, "￣");
			ind=str;
			num=0;
		}//-fe
		else if(strcmp(argv1,"-fe")==0){
			sm=f2b(argv2,argv3);
			if(sm==0){
				printf("ファイルエンコードに失敗しました\n");
				return 7;
			}
			num=3;
		}//-fd
		else if(strcmp(argv1,"-fd")==0){
			sm=b2f(argv2,argv3);
			if(sm==0){
				printf("ファイルデコードに失敗しました\n");
				return 8;
			}
			num=4;
		}
		//ステータス
		switch(num){
			case 1:
				ind="STRING ENCODE";
			break;
			case 2:
				ind="STRING DECODE";
			break;
			case 3:
				ind="FILE ENCODE";
				rl=1;
			break;
			case 4:
				ind="FILE DECODE";
				rl=1;
			break;
		}
		if(rl==0){
			printf("INPUT FILE:%s\n", argv2);
			printf("MODE:\n%s\n", ind);
			printf("RESULT:\n%s\n", str);
			free(str);
		}
		else if(rl==1){
			printf("INPUT FILE:%s\n", argv2);
			printf("MODE:\n%s\n", ind);
			printf("RESULT FILE:%s\n", argv3);
		}
	}

	printf("COMPLETE\n");

	return 0;
}

void pf(void){

		printf("簡易base64エンコーダ/デコーダ VER:0.0%d\n", B64_VER);
		printf("作者:α改 @alpha_kai_NET\n\n");
		printf("使用方法:\n");
		printf("COMMAND : base64 [Option] [String] [OUTPUTFILENAME]\n");
		printf("[Option]:\n");
		printf("-e  :  文字列のエンコード\n");
		printf("-d  :  文字列のデコード\n");
		printf("-fe  :  ファイルのエンコード\n");
		printf("-fd  :  ファイルのデコード\n");
		printf("ファイルのエンデコのときのみOUTPUTFILENAMEはつかえます\n");
		printf("--help  :  使い方表示(現在の出力と同じです)\n");
		printf("-v  :  バージョン情報\n");
		
}

