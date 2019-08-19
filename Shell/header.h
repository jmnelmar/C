#ifndef _HEADER_
#define _HEADER_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include<dirent.h>

extern char **environ;

char **split(char *line, char *separators);
int execute_cmd(char **arguments, int len);
char **find_path(char *line);
//void free_buffer();
char *find_dir(char **path);
char *_strcpy(char *src);
int count_parts(char *line, const char *delim);

int _strlen(char *str);
#endif