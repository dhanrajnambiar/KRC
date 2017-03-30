#include <stdio.h>

int binsearch(int x,int v[],int n)
{
 for (int i = 0;i < n;++i)
 {
     if (x == v[i])
        return(i);
 }
}

