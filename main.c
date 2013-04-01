/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	Kai OS
	LICENSE GPLv3
	Copyleft (C) α改 alpha_kai_NET 2012-2013 http://alpha-kai-net.info
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "os_s.h"
#include "my_lib.h"

#define VER "0.0.1 alpha"
//Prototype
void about(void);
void help(void);
//base64
int base64(int argc, char *argv1, char *argv2, char *argv3);

//Program
int main(int args,char *argv[]){

	int i,t;
	int lp;
	char cmdstr[10000];
	char path[1000];
	char filename[1000];
	char b64str[1000];
	char *b64opt;
	char *b64arg;
	char *b64optf;
	char *tok;
	char s2[] = " ";
	
#if _WIN32 || _WIN64
	LPTSTR pcname[100];
	LPSTR username[100];
	LPDWORD lpnSize;
#endif
#if __unix || __linux || __FreeBSD__ || __NetBSD__
	char pcname[100];
	char username[100];
#endif
	
	lp=1;
	t=0;
	about();
	printf("\nターミナルエミュレータ見習い\n");
	printf("このバイナリがコンパイルされた環境:%s\n\n",OS);
	printf("コンパイル日 %s\n",__DATE__);
	printf("コンパイル時刻 %s\n",__TIME__);
	
	while(1){
		
		//PC名 カレントディレクトリ&ユーザー名取得
		#if _WIN32 || _WIN64
			GetCurrentDirectory(1000,path);
			GetComputerName(pcname,&lpnSize);
			GetUserName(username,&lpnSize);
			if(lp!=1){
		#endif
		#if __unix || __linux || __FreeBSD__ || __NetBSD__
			getcwd(path,1000);
			username=getenv("USER");
			pcname=getenv("HOSTNAME");
		#endif
		//PC名@ユーザー名 ディレクトリ
		printf("[%s@%s]\n%s $ ",pcname,username,path);
		gets(cmdstr);
		
		if(strcmp(cmdstr,"osver")==0){
			about();
		}
		else if(strcmp(cmdstr,"date")==0){
			printf("%s\n",now_time_string());
		}
		else if(strstr(cmdstr,"cat")!=NULL){
			//kernel.cに関数を作成
			//ファイル名分解
			sscanf(cmdstr,"cat %s",filename);
			cat(filename);
		}
		else if(strstr(cmdstr,"base64")!=NULL){
			//分解
			tok = strtok(cmdstr,s2);
			while(tok!=NULL){
				tok = strtok(NULL,s2);
				t++;//区切りの数
			}
			if(t==3){
				sscanf(cmdstr,"base64 %s %s", b64opt, b64arg);
				b64optf="";
			}
			if(t==4){
				sscanf(cmdstr,"base64 %s %s %s", b64opt, b64arg,b64optf);
			}
			else{
				b64opt="";
				b64arg="";
				b64optf="";
			}
			printf("IN=>%d %s %s %s\n",t,b64opt,b64arg,b64optf);
			base64(t,b64opt,b64arg,b64optf);
		}
		else if(strcmp(cmdstr,"help")==0){
			help();
		}
		else if(strcmp(cmdstr,"")==0){
		
		}
		else if(strcmp(cmdstr,"exit")==0){
			printf("EXITING NOW\n");
			printf("ByeBye :-)\n");
			break;
		}
		else{
			printf("\"%s\"はKaiOSに対して有効なコマンドではありません\n\n", cmdstr);
		}
		#if _WIN32 || _WIN64
			}
		#endif
		printf("\n");
		lp++;
	}
	t=0;
	return 0;
}
