#include <stdio.h>
#define MAX 50 /*should be even*/

int c,HALF;
char arr_store[MAX] = {0};

void reverse(char s[]){
 int j;
 for (j = 50;j >= 0;--j){
     printf("%c", s[j]);
 }
 /*printf("%s\n", s);*/
}

int main()
{
 int i = 0;
 while ((c = getchar()) != EOF){
     arr_store[i] = c;
     ++i;
 }
 reverse(arr_store);
}
