/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	Kai OS Kernel&Main set
	Copyleft (C) α改 alpha_kai_NET 2012-2013 http://alpha-kai-net.info
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

#include "prototype.h"

void about(void){
	printf("Kai OS VERSION: %s\n", PT_VER);
	printf("Copyleft (C) α改 alpha_kai_NET 2012-2013 http://alpha-kai-net.info\n");
	printf("実装されているコマンドの一覧/使い方はhelpコマンドで確認できます\n");
}

void help(void){
	printf("実装されているコマンド\n");
	printf("cat 引数(ファイル名):　引数のファイルの中身を表示します\n");
	printf("rename 元ファイル名 新しいファイル名:　ファイル名変更\n");
	printf("echo 引数:　echoです まだリダイレクトは実装していません\n");
	printf("mkdir 引数:　ディレクトリを作成します\n");
	printf("rmdir 引数:　空のディレクトリを削除します\n");
	printf("cd 引数:　カレントディレクトリを変更します\n");
	printf("ls (引数):　引数のディレクトリのファイル/フォルダの一覧表示をします 引数がなければカレントディレクトリを対象とします\n");
	printf("rm 引数:　ファイルを削除します\n");
	printf("date:　時刻を表示します\n");
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

void rename_cmd(const char *cmdstr){
	char oldname[1000]={"\0"};
	char newname[1000]={"\0"};

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
}

void echo_cmd(const char *cmdstr){
	char echostr[1000];

	sscanf(cmdstr,"echo %s",echostr);
	printf("%s\n",echostr);
}

void mkdir_cmd(const char *cmdstr){
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
}

void rmdir_cmd(const char *cmdstr){
	char willdir[1000];
	
	sscanf(cmdstr,"rmdir %s",willdir);
#if _WIN32 || _WIN64
	if(_rmdir(willdir)==0){
		printf("ディレクトリ\"%s\"を正常に削除しました\n",willdir);
	}
	else if(_rmdir(willdir)==2){
		printf("ディレクトリ\"%s\"の削除に失敗しました\n",willdir);
		printf("可能性:\nパスが無効です。\n");
	}
	else if(_rmdir(willdir)==13){
		printf("ディレクトリ\"%s\"の削除に失敗しました\n",willdir);
		printf("可能性:\nプログラムでディレクトリへのハンドルを開いています。 権限などをご確認下さい\n");
	}
	else if(_rmdir(willdir)==41){
		printf("ディレクトリ\"%s\"の削除に失敗しました\n",willdir);
		printf("可能性:\n指定されたパスがディレクトリではないか、ディレクトリが空ではないか、現在の作業ディレクトリまたはルート ディレクトリです。\n");
	}
#endif
#if __unix || __linux || __FreeBSD__ || __NetBSD__
	if(rmdir(willdir)==NULL){
		printf("ディレクトリ\"%s\"を正常に削除しました\n");
	}
	else {
		printf("ディレクトリ\"%s\"の削除に失敗しました\n");
	}
#endif

}

void cd_cmd(const char *cmdstr){
	char newdir[1000];

	sscanf(cmdstr,"cd %s",newdir);
#if _WIN32 || _WIN64
	_chdir(newdir);
#endif
#if __unix || __linux || __FreeBSD__ || __NetBSD__
	chdir(newdir);
#endif
}

void ls_cmd(const char *cmdstr){

#if _WIN32 || _WIN64

	WIN32_FIND_DATA FindFileData;

	HANDLE hFind;

	char willdir[1000];
	char *wk="*";
	sscanf(cmdstr,"ls %s",willdir);
	
	SetCurrentDirectory(willdir);
	
	hFind = FindFirstFile(wk, &FindFileData);
	
	if (hFind == INVALID_HANDLE_VALUE) {

    printf ("エラー\nエラーコード: %d\n", GetLastError ());

	}
	else {
		printf("%s\n", FindFileData.cFileName);

		do{
			printf("%s\n", FindFileData.cFileName);
			
		} while(FindNextFile(hFind,&FindFileData));
	}

	FindClose(hFind);
#endif
#if __unix || __linux || __FreeBSD__ || __NetBSD__
	DIR* dir;
	int i;
	struct dirent* dp;
	char willdir[1000];
  	sscanf(cmdstr,"ls %s",willdir);
	
	if (NULL == (dir = opendir(willdir))){
		printf("ディレクトリを開けませんでした\n");
		exit(1);
	}
	for(i = 0; NULL != (dp = readdir(dir)); i++){
		printf("%s\n" , dp->d_name);
	}
	closedir(dir);
#endif
}

void rm_cmd(const char *cmdstr){
	char willfile[1000];
	sscanf(cmdstr,"rm %s",willfile);
	del(willfile);
}

char* pronpt(){

	if(getuid()==0){
		return "#";
	}
	else{
		return "%";
	}
}

char* uname(){
	struct passwd *pwd;
	uid_t uid;
	uid=getuid();
	pwd = getpwuid(uid);
	return pwd->pw_name;
}
