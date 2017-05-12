#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAXOP 100
#define NUMBER 0
#define MAXVAL 100
#define BUFFSIZE 100
#define SHOW 1
#define SWAP 2
#define DUPE 3
#define SIN 4
#define COS 5
#define EXP 6
#define POW 7
#define LAST 8

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
 double op1,op2,last_pop;
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
	 last_pop = pop();
         printf("\t%.8g\n", last_pop);
         break;
     case SHOW:
         printf("%f\n", pop());
         break;
     case SWAP:
         op1 = pop();
         op2 = pop();
	 push(op1);
	 push(op2);
         printf("values in stack are %f and %f\n", pop(), pop());
         break;
     case DUPE:
         op1 = pop();
         push(op1);
         push(op1);
         printf("values in stack are %f and %f\n", pop(), pop());
         break;
     case SIN:
 	 push(sin(pop() * 3.14 / 180));
         break;        
     case COS:
         push(cos(pop() * 3.14 / 180));
	 break;
     case EXP:
         push(exp(pop()));
         break;
     case POW:
	 op1 = pop();/*power*/
 	 op2 = pop();/*base*/
         push(pow(op2,op1));
	 break;
     case LAST:
         printf("\t%.8g\n", last_pop);
	 break;
     default:
         printf("error:unknown commands %s\n", s);
         break;
     }
 }
 return 0;
}
/*The strings within double quotes assigned to const char pointers are commands to do things as their name suggests*/
int getop(char s[])
{
 int i,c;
 const char *show = "show";/*shows top element of stack*/
 const char *swap = "swap";/*swaps the top 2 elements of stack*/
 const char *dupe = "dupe";/*duplicates top 2 elements of the stack*/
 const char *sin = "sin";/*sine calculator command*/
 const char *cos = "cos";/*cosine calculator command*/
 const char *exp = "exp";/*e riased to calculator*/
 const char *pow = "pow";/*x y pow prints x raised to y times*/
 const char *lastval = "latest";/*prints the latest printed value*/
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
         return SHOW;
     else if(strcmp(swap,command) == 0)
         return SWAP;
     else if(strcmp(dupe,command) == 0)
         return DUPE;
     else if(strcmp(sin,command) == 0)
         return SIN;
     else if(strcmp(cos,command) == 0)
         return COS;
     else if(strcmp(exp,command) == 0)
         return EXP;
     else if(strcmp(pow,command) == 0)
         return POW;
     else if(strcmp(lastval,command) == 0)
         return LAST;
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
