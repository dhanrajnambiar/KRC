#include <stdio.h>

int c;

int main()
{
 while((c = getchar()) != EOF){
     switch(c){
         case '\t':
	     putchar('\\');
	     putchar('t');
	     break;
	 case '\\':
	     putchar('\\');
	     putchar('\\');
	     break;
	 case '\b':
	     putchar('\\');
	     putchar('b');
	     break;
	 default:
	     putchar(c);
     }
  }
}
