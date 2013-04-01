// UNIX
#if __unix
#define OS "UNIX"
#include <unistd.h>
#endif
// Linux
#if __linux
#define OS "Linux"
#include <unistd.h>
#endif
//Free BSD
# if __FreeBSD__
#define OS "FreeBSD"
#include <unistd.h>
#endif
//NetBSD
#if __NetBSD__
#define OS "NetBSD"
#include <unistd.h>
#endif
// Windows
#if _WIN32 || _WIN64
#define OS "Windows"
#include <windows.h>
#endif
