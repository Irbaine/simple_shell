#include "main.h"

char **spliter (char *line)
{
   int counter = 0;
   int n = 0;
   char *temp = NULL;
   char delimiter[]= " \t\n";
   char *tk = NULL, **cmd = NULL;
      
   if(line == NULL)
   	return(NULL);
  temp = _strdup(line); /* get the first token */
   tk = strtok(temp, delimiter);
   if(tk == NULL) /* if user entered whitespaces only*/
   {
   free(line);
   line = NULL;
   free(temp);
   temp = NULL;
   
   return (NULL);
   }
   while(tk != NULL) /* walk through other tokens */
   {
	counter++;
	tk = strtok(NULL, delimiter);
   } 
   free(temp);

   cmd = malloc(sizeof(char *) * (counter + 1));
   if(cmd == NULL)
   {
   free(line), line =NULL;
   return (NULL);
   }
   
   tk = strtok(line, delimiter);
      while( tk != NULL )
      {
	cmd[n++] = _strdup(tk);
	tk = strtok(NULL, delimiter);
	}
   free(line);
   cmd[n] = NULL;

   return (cmd);
   
}
