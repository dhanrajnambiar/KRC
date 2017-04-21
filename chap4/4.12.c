#include <stdio.h>

#define MAX 20/*maximum lenght of int handled*/

int s[MAX];
static int i;/*'i' is used in the recursivly in itoa, hence need to maintain the value contained in it, hence declared static*/

void itoa(int n)
{
 if (n < 0)
 {
     n = -n;
     putchar('-');
     s[i++];
 }
 if (n / 10)
 {
     itoa(n / 10);
 }
 s[i++] = n % 10;
}

int main()
{
 int c = 0;
 printf("Plz input the integer\n");
 scanf("%d", &c);
 itoa(c);
 for (int j = 0;j < i;++j)/*here val of i used to print number of elements in s[]*/
     printf("%d", s[j]);
 printf("\n");
}
