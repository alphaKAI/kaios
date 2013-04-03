#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "my_lib.h"

void about(void);
void help(void);
int cat(const char *cmdstr);
void rename_cmd(const char *cmdstr);
void echo_cmd(const char *cmdstr);
void mkdir_cmd(const char *cmdstr);
void rmdir_cmd(const char *cmdstr);
void cd_cmd(const char *cmdstr);
void ls_cmd(const char *);
void rm_cmd(const char *cmdstr);

//マクロ
#define PT_VER "0.0.5_FIX alpha"

// UNIX
#if __unix
	#define OS "UNIX"
	#include <unistd.h>
	#include <sys/stat.h>
	#include <sys/types.h>
#endif

// Linux
#if __linux
	#define OS "Linux"
	#include <unistd.h>
	#include <sys/stat.h>
	#include <sys/types.h>
#endif

//Free BSD
# if __FreeBSD__
	#define OS "FreeBSD"
	#include <unistd.h>
	#include <sys/stat.h>
	#include <sys/types.h>
#endif

//NetBSD
#if __NetBSD__
	#define OS "NetBSD"
	#include <unistd.h>
	#include <sys/stat.h>
	#include <sys/types.h>
#endif

// Windows
#if _WIN32 || _WIN64
	#define OS "Windows"
	#include <windows.h>
	#include <direct.h>
#endif
