#include <stdio.h>

unsigned setbits(unsigned x,int p,int n,unsigned y)
{
 unsigned int u,v;
 u = ((x >> (p - n + 1)) & ~(~0 << n));
 v = (y & (~0 << n));
 return(u | v); 
}

