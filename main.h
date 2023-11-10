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

/* strdup duplicates the string and returns a copy*/
char *_strdup(const char *string);
/* splits a string based on a custom delimiter*/
char **spliter (char *line);
void freeaos(char **arr);
int _execute(char **cmd, char **argv);

int strcompar(char *one, char *two); /*compar*/
int _strlength(char *n);
char *_strcopy(char *dest, char *source);
char *_strconcat(char *dest, const char *source);

char *_getenviron(char *var);
char *_getpath(char *cmd);


#endif
