/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	Kai OS
	LICENSE GPLv3
	Copyleft (C) α改 alpha_kai_NET 2012-2013 http://alpha-kai-net.info
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

#include "prototype.h"


int main(){
	int lp;
	int error=0;
	
	lp=1;
	about();
	printf("\nShellもどき見習い\n");

	printf("このバイナリがコンパイルされた環境:%s\n\n",OS);
	printf("コンパイル日 %s\n",__DATE__);
	printf("コンパイル時刻 %s\n",__TIME__);
	
	while(1){
		error=ShellLine(lp,error);
		lp++;
	}
	return 0;
}

int ShellLine(int loop_count,int error){
	char *cmdstr;
	char *path;
	
	char *pcname;

	path=(char *)malloc(strlen(getenv("PATH")));
	getcwd(path,strlen(getenv("PATH")));

	pcname=(char *)malloc(15);
	ReturnStrings("/etc/hostname",1,pcname,15);
	
	pcname[strlen(pcname)-1]=NULL;
	
	if(error != 0){
		printf(" %d ", error);
	}
	printf("%s@%s %s %s ",uname(),pcname,path,pronpt());
	
	cmdstr=MyGetInfi(stdin);
	
	if(cmdstr == NULL){
			printf("メモリ確保に失敗しました もう一度入力してください\n");
			return 100;
	} else{
		parser(cmdstr);
	}

	free(pcname);
	free(path);

	printf("\n");

	return 0;
}
