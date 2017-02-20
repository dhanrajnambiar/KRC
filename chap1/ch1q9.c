#include <stdio.h>

int c;

void loop_1(void)
{
 while (((c = getchar()) != EOF) && ((c == '\t') || (c == ' ')))
     ;
 putchar(' ');
 putchar(c);
}

int main()
{
 while((c = getchar()) != EOF)
     if ((c == '\t') || (c == ' '))
         loop_1();
     else
         putchar(c);
}
