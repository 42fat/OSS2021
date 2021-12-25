#include <stdio.h>
#include <stdlib.h>

extern char **environ;

int main(int argc, char *argv[])
{
 if (argc < 2)
 return -1;
 int count = atoi (argv[1]);
 char **p;
 for (p = environ; *p != NULL && p - environ < count; p++)
     {
           printf ("%d %s\n", p - environ, *p);
     }
     return 0;
}
