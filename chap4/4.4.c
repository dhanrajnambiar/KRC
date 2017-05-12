#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAXOP 100
#define NUMBER 0
#define MAXVAL 100
#define BUFFSIZE 100
#define NUM1 1
#define NUM2 2
#define NUM3 3

int getop(char s[]);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);

int sp = 0;
double val[MAXVAL];
int bufp = 0;
char buf[BUFFSIZE];

int main()
{
 int type;
 double op1,op2;
 char s[MAXOP];

 while ((type = getop(s)) != EOF)
 {
     switch (type){
     case NUMBER:
         push(atof(s));
         break;
     case '+':
         push(pop() + pop());
         break;
     case '*':
         push(pop() * pop());
         break;
     case '-':
         op2 = pop();
         push(pop() - op2);
         break;
     case '/':
         op2 = pop();
         if (op2 != '0')
             push(pop() / op2);
         else
             printf("error:zero divisor");
         break;
     case '\n':
         printf("\t%.8g\n", pop());
         break;
     case NUM1:
         printf("%f\n", pop());
         break;
     case NUM2:
         op1 = pop();
         op2 = pop();
	 push(op1);
	 push(op2);
         printf("values in stack are %f and %f\n", pop(), pop());
         break;
     case NUM3:
         op1 = pop();
         push(op1);
         push(op1);
         printf("values in stack are %f and %f\n", pop(), pop());
         break;
     default:
         printf("error:unknown commands %s\n", s);
         break;
     }
 }
 return 0;
}

int getop(char s[])
{
 int i,c;
 const char *show = "show";
 const char *swap = "swap";
 const char *dupe = "dupe"; 
 char *command;
 while((s[0] = c = getch()) == ' ' || c == '\t')
     ;
 s[1] = '\0';
 i = 0;
 if (isalpha(c))
 {
     while(isalpha(s[++i] = c = getchar()))
         ;
     s[i] = '\0';
     command = s;
     if (strcmp(show,command) == 0)
         return NUM1;
     else if(strcmp(swap,command) == 0)
         return NUM2;
     else if(strcmp(dupe,command) == 0)
         return NUM3;
 }
 if (!isdigit(c) && c != '.')
     return c;
 if (isdigit(c))
     while((isdigit(s[++i] = c = getch())))
         ;
 if (c == '.')
     while(isdigit(s[++i] = c = getch()))
         ;
 s[i] = '\0';
 if (c != EOF)
     ungetch(c);
 return NUMBER;
}

int getch(void)
{
 return (bufp > 0) ? buf[--bufp]:getchar();
}

void ungetch(int c)
{
 if (bufp >= BUFFSIZE)
     printf("ungetch:too many charactesr\n");
 else
     buf[bufp++] = c;
}

void push(double f)
{
 if (sp < MAXVAL)
     val[sp++] = f;
 else 
     printf("error: stack full can't push %g\n", f);
}

double pop(void)
{
 if (sp > 0)
     return val[--sp];
 else 
 {
     printf("error: stack empty\n");
     return 0.0;
 }
}
