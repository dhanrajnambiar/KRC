#include <stdio.h>

int c;

/*Below loop() simply does nothing for consecutive blanks and starts printing in a new line when non blank character occurs*/
void loop()
{
 while(((c = getchar()) == ' ') && (c != EOF))
     ;
 printf("\n");
 putchar(c);
}

int main()
{
 while((c = getchar()) != EOF){
     
     if (c == ' ')
	 loop();

     else if (c == '\t')
         putchar('\n');

     else
	 putchar(c);
 }
}
