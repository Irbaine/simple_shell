#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h> /* strtok */

#include <sys/types.h> /*for waitpid */
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>

extern char **environ;
char *read_line(void);

/* splits a string based on a custom delimiter*/
char **spliter (char *line);
void freeaos(char **arr);
int _execute(char **cmd, char **argv, int index);

/* UTILS */
char *_strdup(const char *string); /* strdup duplicates the string and returns a copy*/
int _strcompar(char *one, char *two); /*compar*/
int _strlength(char *n);
char *_strcopy(char *dest, char *source);
char *_strconcat(char *destination, char *source);
char *_itoa(int n);
void reversestr(char *string, int length);

char *_getenviron(char *var);
char *_getpath(char *cmd);
void err(char *cmd, char *shell, int index);


#endif
