#include <stdio.h>

unsigned right_rot(unsigned x,int n)
{
 return((x << 32 - n) | (x >> n));
}
void main()
{
 printf("%d\n", right_rot(181,2));
}
