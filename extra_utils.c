#include "main.h"
char *_itoa(int n)
{
    char buff[20];
    int i = 0;

    if (n == 0)
        buff[i++] = '0';
    else
    {
        while (n > 0)
        {
            buff[i++] = (n % 10) + '0';
            n /= 10;
        }
    }

    buff[i] = '\0';

    reversestr(buff,i);

    return (_strdup(buff));

}

void reversestr(char *string, int length)
    {
      char temp;
      int first = 0;
      int last = length - 1;

      while(first < last)
      {
        temp = string[first];
        string[first] = string[last];
        string[last] = temp;
        last--;
        first++;
      }


    }
