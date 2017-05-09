#include <stdio.h>

#define MAX 100
#define BUFFSIZE 100

void ungetch(int);
void ungets(char s[]);

int bufp = 0;
char buf[BUFFSIZE];
char s[MAX];
char c;

int main()
{
 ungets(s);
}

void ungets(char s[])
{
 int i = 0;
 while((c = getchar()) != EOF && c != '\n')
 {
     s[i] = c;
     ++i;
 }
 s[i] = '\0';
 
 i = 0;
 while(s[i] != '\0')/*stores each value in s[] character wise to buf[] using ungetch*/
 {
     ungetch(s[i++]);
 }
 ungetch(s[i]);
 
 for (int k = 0;(k < i) && (buf[k] != '\0');++k)
 {
     c = buf[k];
     putchar(c);
 }
 printf("\n");
}

void ungetch(int c)
{
 if (bufp >= BUFFSIZE)
     printf("ungetch:too many characters\n");
 else
     buf[bufp++] = c;
}
