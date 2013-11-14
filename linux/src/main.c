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
	
	lp=1;
	about();
	printf("\nShellもどき見習い\n");

	printf("このバイナリがコンパイルされた環境:%s\n\n",OS);
	printf("コンパイル日 %s\n",__DATE__);
	printf("コンパイル時刻 %s\n",__TIME__);
	
	while(1){
		ShellLine(lp);
		lp++;
	}
	return 0;
}

void ShellLine(int loop_count){
	char *cmdstr;
	char *path;
	
	char *pcname;

	path=(char *)malloc(strlen(getenv("PATH")));
	getcwd(path,strlen(getenv("PATH")));

	pcname=(char *)malloc(15);
	ReturnStrings("/etc/hostname",1,pcname,15);
	
	pcname[strlen(pcname)-1]=NULL;
		
	printf("%s@%s %s %s ",uname(),pcname,path,pronpt());
		
	cmdstr=MyGetInfi(stdin);

	parser(cmdstr);

	free(pcname);
	free(path);

	printf("\n");
}
