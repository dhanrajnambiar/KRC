#include <stdio.h>

#define LEN 100

int arr1[LEN] = {0};
int arr2[LEN] = {0};
int j = 0;/*its set to 0 initially and thereafter continues counting until 100*/

void expand(int s1,int s2)
{
 int i;
 i = s1;/*i used to increment values in the range to be expanded*/
 while ((i <= s2) && (j < LEN))/*bottom line here is arr2 shouldn't overflow*/
 {
     arr2[j] = i;
     ++i;
     ++j;
 }
}

int main()
{
 int c,k = 0;
 while (((c = getchar()) != EOF) && (c != '\n'))
 {
     arr1[k] = c;
     ++k;
 }

 for (k = 1;k < LEN;++k)
 {
     if (arr1[k] == '-')
         expand(arr1[k - 1],arr1[k + 1]);
 }
 for (k = 0;k < LEN;++k)
     printf("%c", arr2[k]);
 printf("\n");
}

