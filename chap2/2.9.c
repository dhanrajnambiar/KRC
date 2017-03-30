#include <stdio.h>
/*Below func bitcount counts the number of 1's in bit pattern corresponding to the decimal we input.*/
unsigned bitcount(unsigned x)
{
 int i = 0;
 while (x > 0)
 {
     x &= (x - 1);/*This step reduces the number of 1's in binary of x by one, each time its executed*/
     ++i;
 }
 return(i);
}

void main()
{
 int p;
 printf("please input the decimal number\n");
 scanf("%d", &p);
 printf("%d\n", bitcount(p));
}
