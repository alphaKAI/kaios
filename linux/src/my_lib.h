#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
//#include <unistd.h>

int pause();
int check(const char *name);
int del(const char *name);
int result(const char *name);
int onkai();
int now_time();
char *now_time_string();
int how_line(const char *name);
int GetRandom(int const max);
int ReturnStrings(const char* path, const int num, char* buf, const int size);
int make_string(const char *filename, char *buf, const int size);
