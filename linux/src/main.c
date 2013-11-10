/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	Kai OS
	LICENSE GPLv3
	Copyleft (C) α改 alpha_kai_NET 2012-2013 http://alpha-kai-net.info
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

#include "prototype.h"

int main(main){

	int lp;
	char *cmdstr;
	char *path;
	
	char *pcname;
	
	lp=1;
	about();
	printf("\nShellもどき見習い\n");

	printf("このバイナリがコンパイルされた環境:%s\n\n",OS);
	printf("コンパイル日 %s\n",__DATE__);
	printf("コンパイル時刻 %s\n",__TIME__);
	
	while(1){
		
		getcwd(path,1000);
		pcname=(char *)malloc(15);
		ReturnStrings("/etc/hostname",1,pcname,15);
	
		pcname[strlen(pcname)-1]=NULL;
		
		printf("%s@%s %s %s ",uname(),pcname,path,pronpt());
		free(pcname);
		//gets(cmdstr);
		scanf("%s",&cmdstr);

		if(strcmp(cmdstr,"osver")==0){
			about();
		}
		else if(strstr(cmdstr,"echo")!=NULL){
			echo_cmd(cmdstr);
		}
		else if(strcmp(cmdstr,"date")==0){
			printf("%s\n",now_time_string());
		}
		else if(strstr(cmdstr,"cat")!=NULL){
			cat(cmdstr);
		}
		else if(strstr(cmdstr,"mkdir")!=NULL){	
			mkdir_cmd(cmdstr);
		}
		else if(strstr(cmdstr,"rmdir")!=NULL){
			rmdir_cmd(cmdstr);
		}
		else if(strstr(cmdstr,"cd")!=NULL){	
			cd_cmd(cmdstr);
		}
		else if(strstr(cmdstr,"rename")!=NULL){
			rename_cmd(cmdstr);
		}
		else if(strstr(cmdstr,"ls")!=NULL){
			if(strlen(cmdstr)==2){
				sprintf(cmdstr,"ls %s",path);
			}
			ls_cmd(cmdstr);
			#if _WIN32 || _WIN64
			SetCurrentDirectory(path);
			#endif
			#if __unix || __linux || __FreeBSD__ || __NetBSD__
			cd_cmd(path);
			#endif
		}
		else if(strstr(cmdstr,"rm")!=NULL){
			rm_cmd(cmdstr);
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
	return 0;
}
