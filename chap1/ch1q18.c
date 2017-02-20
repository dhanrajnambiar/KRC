#include <stdio.h>

int c;
/*loop1 reduces many spacesin a line to single space*/
void loop_1(void)
{
 while (((c = getchar()) != EOF) && ((c == '\t') || (c == ' ')))
     ;
 putchar(' ');
 putchar(c);
}
/*loop2 discards the empty lines*/
void loop_2(void)
{
 while (((c = getchar()) != EOF) && ((c == '\t') || (c == ' ') || (c == '\n')))
     ;
 putchar(c);
}

int main()
{
 while((c = getchar()) != EOF)
     if ((c == '\t') || (c == ' '))
         loop_1();
     else if (c == '\n')
         loop_2();
     else
         putchar(c);
}
