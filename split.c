#include "main.h"

char **spliter(char *line)
<<<<<<< HEAD
{
int counter = 0;
int n = 0;
char *temp = NULL;
char delimiter[] = "\t\n";
char *tk = NULL;
char **cmd = NULL;
if (line == NULL)
return (NULL);
/* get the first token */
temp = _strdup(line);
tk = strtok(temp, delimiter);
/* if user entered whitespaces only*/
if (tk == NULL)
{
free(line);
line = NULL;
free(temp);
temp = NULL;
return (NULL);
}
/* walk through other tokens */
while (tk != NULL)
{
	counter++;
	tk = strtok(NULL, delimiter);
=======
{
int counter = 0;
int n = 0;
char *temp = NULL, delimiter[] = " \t\n ", *tk = NULL;
char **cmd = NULL;
if (line == NULL)
return (NULL);
temp = _strdup(line); /* get the first token */
tk = strtok(temp, delimiter);
if (tk == NULL) /* if user entered whitespaces only*/
{
free(line), line = NULL;
free(temp), temp = NULL;
return (NULL);
}
while (tk != NULL) /* walk through other tokens */
{
counter++;
tk = strtok(NULL, delimiter);
>>>>>>> 895d9dc485757c90d509207f2e7e3a1584bce11c
}
free(temp);
cmd = malloc(sizeof(char *) * (counter + 1));
if (cmd == NULL)
{
free(line), line = NULL;
return (NULL);
}
tk = strtok(line, delimiter);
while (tk != NULL)
{
<<<<<<< HEAD
	cmd[n++] = _strdup(tk);
	tk = strtok(NULL, delimiter);
}
free(line);
cmd[n] = NULL;

=======
cmd[n++] = _strdup(tk);
tk = strtok(NULL, delimiter);
}
free(line);
cmd[n] = NULL;
>>>>>>> 895d9dc485757c90d509207f2e7e3a1584bce11c
return (cmd);
}
