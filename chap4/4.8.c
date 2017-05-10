#include <stdio.h>

#define SET 1
#define RESET 0

void ungetch(int);
int getch(void);
void ungets(void);

int buf;
int c;

int main()
{
 ungets();
}

void ungets(void)
{
 c = getch();
 ungetch(c);
 printf("%c\n", getch());
}


void ungetch(int x)
{
 if (buf != 0)
     printf("cannot ungetch\n");
 else
     buf = x;
}

int getch(void)
{
 int p;
 p = (buf != 0) ? buf:getchar();
 return p;
}
