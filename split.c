#include "main.h"

char **spliter (char *line)
{
   int counter = 0;
   int n = 0;
   char *temp = NULL;
   char delimiter[] = " \t\n " ;
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
	cmd[n++] = _strdup(tk);
	tk = strtok(NULL, delimiter);
   }
   free(line);
   cmd[n] = NULL;

   return (cmd);
}
