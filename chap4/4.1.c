#include <stdio.h>
#define MAX 100

int arr1[MAX] = {0};
int arr2[MAX] = {0};

int strindex(int s[],int t[])
{
 int i,j,k;
/*below while loops counts the number of letters in s[] & t[]*/
 int len_t = 0;
 while (t[len_t] != '\0')
     ++len_t;
 int len_s = 0;
 while (s[len_s] != '\0')
     ++len_s;
 for (i = len_s - 1;i > 0;--i)
     for (j = i,k = len_t - 1;k >= 0 && s[j] == t[k];--k,--j)
         if (k == 0)
             return(i - len_t + 2);
 return(-1);
}

int main()
{
 int c;
 int i = 0;
 printf("plz enter the text to be searched in\n");
 while (((c = getchar()) != EOF) && (c != '\n'))
 {
     arr1[i] = c;
     ++i;
 }
 printf("please enter the regex\n");
 i = 0;
 while ((c = getchar()) != '\n')
 {
     arr2[i] = c;
     ++i;
 }
 printf("%d\n", strindex(arr1,arr2));
}
