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
char **spliter(char *line);
void freeaos(char **arr);
int _execute(char **cmd, char **argv);

/**
* strcompar - Compare two strings
* @one: First string to compare
* @two: Second string to compare
*
* Description: This function compares two strings and returns an integer value
*              Indicating their comparison result.
*
* Return: 0 if the strings are equal, a negative value if one is less than two,
*         or a positive value if one is greater than two.
*/
int strcompar(char *one, char *two); /*compar*/
int _strlength(char *n);
char *_strcopy(char *dest, char *source);
char *_strconcat(char *dest, const char *source);

char *_getenviron(char *var);
char *_getpath(char *cmd);


void handle_cmd(int *stat, char **cmd, int index, char **argv);
void exit_sh(char **cmd, int *stat);
void show_env(int *stat, char **cmd);

#endif
