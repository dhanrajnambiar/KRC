#include <stdio.h>

int c,k,u,v;
char ch;
char char_ar[26] = {0};
int num_ar[10] = {0};


void printX_loop(i){
 int j;
 for (j = 1;j <= i;++j)
     printf("X");
 printf("\n");
}

int main()
{
 while((c = getchar()) != EOF){
     for (ch = 'a',k = 0;ch <= 'z',k <= 25;++ch,++k)
         if (c == ch){
	     ++char_ar[k];
         }
 }
 printf("\n");
 printf("----------------------------------------------------------------------\n");
 for (ch = 'a',u = 0;ch <= 'z',u <= 25;++ch,++u){
     printf("letter '%c' :", ch);
     printX_loop(char_ar[u]);
 }
 printf("----------------------------------------------------------------------\n");
} 
