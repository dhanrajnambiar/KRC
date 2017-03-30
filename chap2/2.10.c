#include <stdio.h>

int lower(int c)
{
 return((c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c);
}

void main()
{
 int c;
 while (((c = getchar()) != EOF) && (c != '\n'))
     printf("%c", lower(c));
 printf("\n");
}
