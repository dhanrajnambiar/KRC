#include <stdio.h>

#define MAX 30

char arr[MAX];

void swap(char s[],int lm,int rm)
{
 int temp = 0;
 temp = s[lm];
 s[lm] = s[rm];
 s[rm] = temp;
 if (lm < rm)
 {
   ++lm;
   --rm;
   swap(arr,lm,rm);
 }
}

int main()
{
 int j = 0;
 int c;
 while ((c = getchar()) != EOF)
 {
     arr[j] = c;
     ++j;
 }
 swap(arr,0,j - 1);
 printf("%s\n", arr);
}
