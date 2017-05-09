#include <stdio.h>

#define MAX 100
#define BUFFSIZE 100

void ungetch(int);
void ungets(char u[]);
void store(char v[]);
void print_array(char x[]);

int bufp = 0;
char buf[BUFFSIZE];
char s[MAX];
char c;

int main()
{
 ungets(s);
}

void ungets(char u[])
{
 int i = 0;
 store(u);

 while(u[i] != '\0')/*stores each value in s[] character wise to buf[] using ungetch*/
 {
     ungetch(u[i++]);
 }
 ungetch(u[i]);

 print_array(buf);
}

void store(char v[])
{
 int i = 0;
 while((c = getchar()) != EOF && (c != '\n'))
     v[i++] = c;
 v[i] = '\0';
}

void print_array(char x[])
{
 for (int k = 0;x[k] != '\0';++k)
 {
     c = x[k];
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
