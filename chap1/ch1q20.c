#include <stdio.h>
#define LOW 0

int c,let_cnt,space_req;

/*tabstop_val return the multiple of 8 just higher than the number of letters in previous word*/
int tabstop_val(int num_letter)
{
 int mul8 = 0;
 int i = 1;
 while (mul8 < num_letter)
 {
     mul8 = 8 * i;
     ++i;
 }
 return(mul8);
}

/*below func is executed when a newline and normal char appears*/
void newline_char_handle()
{
 if (c != '\n')
     {
         putchar(c);
         ++let_cnt;       
     }
     else
     {
         let_cnt = space_req = LOW;
	 putchar('\n');
     }
}

/*put_space function puts the number of space as decided in if part of main func*/
void put_space(int req_space)
{
    for(int i = 0;i < req_space;++i)
        putchar(' ');
}


void main()
{
 space_req = let_cnt = LOW;
 while ((c = getchar()) != EOF){
     if (c == '\t')
     {
         space_req = tabstop_val(let_cnt) - let_cnt;
         put_space(space_req);
         let_cnt = LOW;
     }
     else
         newline_char_handle();
 }
}
