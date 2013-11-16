#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "my_lib.h"

#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <pwd.h>

int ShellLine(int loop_count,int error);
char* MyGetInfi(FILE *fp);
int match_c(char* str,char* pattern);
int parser(char* cmdstr);

void about();
void help();
int cat(const char *cmdstr);
void rename_cmd(const char *cmdstr);
void echo_cmd(const char *cmdstr);
void mkdir_cmd(const char *cmdstr);
void rmdir_cmd(const char *cmdstr);
void cd_cmd(const char *cmdstr);
void ls_cmd(const char *);
void rm_cmd(const char *cmdstr);

#define PT_VER "0.0.7 rv.002 alpha for " OS

#if __linux
	#define OS "Linux"
#endif

#if __unix && ! __linux
	#define OS "UNIX"
#endif

# if __FreeBSD__
	#define OS "FreeBSD"
#endif

#if __NetBSD__
	#define OS "NetBSD"
#endif
