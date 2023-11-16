#include "main.h"

/**
 * freeaos - Frees memory allocated to an array of strings.
 * @arr: Array of strings to be freed.
 *
 * This function deallocates memory for each string in the array
 * and sets the array elements to NULL, then frees the array itself.
 */
void freeaos(char **arr)
{/* Function body remains unchanged */
int n;
if (!arr)
return;
for (n = 0; arr[n]; n++)
{
free(arr[n]);
arr[n] = NULL;
}
free(arr), arr = NULL;
}
