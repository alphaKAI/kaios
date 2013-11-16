#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 	Copyleft (C) alphaKAI 2013 http://alpha-kai-net.info

	GPLv3 LICENSE
 */

//default
int MAX_WORD = 128;

char **split(char *str, char *sep){
	char *word = NULL;
	char *str_work = NULL;
	int last = 0;
	
	str_work = (char *)malloc(sizeof(char) * (strlen(str) + 1));
	strcpy(str_work, str);
	
	char **results = (char **)malloc(sizeof(char *) * MAX_WORD);
	
	last = 0;
	for(word = strtok(str_work,sep); word; word = strtok(NULL,sep),last++) {
		results[last] = word;
	}
	results[last] = NULL;

	return results;   
}

void split_free(char **words){   
    free(words[0]);
    free(words);
}

int match_c(char* str,char* pattern){
	int i,j;
	int count=0;
	int s_length = strlen(str);
	int p_length = strlen(pattern);
	char* tmp_s;

	for(i=0;i<=s_length;i++){
		tmp_s=(char*)malloc(sizeof(char)*(p_length+2));

		for(j=0;j<p_length;j++){
			tmp_s[j]=str[i+j];
		}

		if(strcmp(tmp_s,pattern)==0){
			count+=1;
		}
		free(tmp_s);
	}

	return count;
}
char* cmd_parser(char *cmdstr, char *path){
	//strtok(cmdstr," ");
}

int parser(char* cmdstr){
	char** array=NULL;
	char* tmp_s;
	int i;

	MAX_WORD=match_c(cmdstr," ")+2;
	printf("%d\n",match_c(cmdstr," "));

	array=split(cmdstr," ");
	for(i=0;array[i]!=NULL;i++){
		printf("%2d: %s\n",i,array[i]);
		
	}
//	printf("%s\n",tmp_s);
	//execute(array[0],tmp_s);

	split_free(array);
	array = NULL;
}
int execute(char* cmd, char* args){
	char* arg;
	int i = 0;
	int length;
	
	//arg=(char*)malloc(strlen((args[0])+1));
	printf("%s\n",cmd);

	printf("1\n");
	for(i = 0; args[i] != NULL; i++){
		printf("2\n");
		
		length += strlen(args[i]);
		arg = (char*)realloc(arg,length+1);

		strcat(arg," ");
		strcat(arg,args[i]);
	}
	
	printf("%s\n",arg);
}
/*
char* doccomand(char* command,char* args){
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
}*/

