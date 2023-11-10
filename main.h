#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h> /* strtok */


char *read_line(void);

/* strdup duplicates the string and returns a copy*/
char *_strdup(const char *string);
/* splits a string based on a custom delimiter*/
char **spliter (char *line);

#endif
