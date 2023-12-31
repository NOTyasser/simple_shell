#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <aio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <ctype.h>
#include <signal.h>
#include <dirent.h>
#include <errno.h>

extern char **environ;
#define  DELIMITERS " \t\n"



char *rd_line(void);
char **tokenizer(char *line);
int _execute(char **command, char **argv, int xed);
void stringarrayfree(char **arr);

char *_strdup(const char *str);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _strlen(char *str);
char *_strcpy(char *dest, char *src);

char *_getenv(char *var);
char *_getpath(char *direct);

void print_error(char *horn, char *fok, int xed);
char *_itoa(int j);
void reverse_string(char *str, int len);


#endif
