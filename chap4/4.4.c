#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define MAXOP 100
#define NUMBER 0
#define MAXVAL 100
#define BUFFSIZE 100

int getop(char s[]);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);

int sp = 0;
double val[MAXVAL];
int bufp = 0;
char buf[BUFFSIZE];

int main(int argc,char *argv[])
{
 int type;
 double op2;
 char s[MAXOP];

 double swap_var,duplct_var;
 const char *arg1 = "show";
 const char *arg2 = "swap";
 const char *arg3 = "duplicate";

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
     default:
         printf("error:unknown commands %s\n", s);
         break;
     }
 }
 if (argc == 0)/*if no arg given*/
     printf("no args provided\n");
 else if (strcmp(arg1,argv[1]) == 0)/*when show arg is passed*/
 {
     printf("%f\n", val[sp]);
 }
 else if (strcmp(arg2,argv[1]) == 0)/*when swap is the arg passed*/
 {
     printf("Before swap; topmost value is %f and below it is %f\n", val[sp], val[sp - 1]);
     swap_var = val[sp];
     val[sp] = val[sp - 1];
     val[sp - 1] = swap_var;
     printf("After swap; topmost value is %f and below it is %f\n", val[sp], val[sp - 1]);
 }
 else if (strcmp(arg3,argv[1]) == 0)/*when duplication is to be done*/
 {
     printf("Before duplicating; topmost value is %f and below it is %f\n", val[sp], val[sp - 1]);
     val[sp - 1] = val[sp];
     printf("After duplicating; topmost value is %f and below it is %f\n", val[sp], val[sp - 1]);
 } 
 else/* any other above 3 args passed*/
     printf("invalid argument\n");
 return 0;
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

int getop(char s[])
{
 int i,c;
 while((s[0] = c = getch()) == ' ' || c == '\t')
     ;
 s[1] = '\0';
 if (!isdigit(c) && c != '.')
     return c;
 i = 0;
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

