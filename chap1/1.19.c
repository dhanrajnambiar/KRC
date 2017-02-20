#include <stdio.h>
#define MAX 50

int c;
char arr[MAX] = {0};

void reverse(char s[]){
 int j = MAX - 1;
 while (j >= 0){
     printf("%c", s[j]);
     --j;
 }
}
int main()
{
 int i = 0,j;
 while ((c = getchar()) != EOF){
     arr[i] = c;
     ++i;
 }
 reverse(arr);
}
