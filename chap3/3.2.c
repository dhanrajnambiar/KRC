#include <stdio.h>

#define LEN 100

int c,u[LEN],v[LEN] = {0},i,j;

void replace(int s[],int t[])
{
 for (i = 0,j = 0;i < LEN;++i)
 {
     switch(u[i])
     {
         case '\t':
	     v[j] = '\\';
	     ++j;
             v[j] = 't';
             ++j;
	     break;
         case '\n':
	     v[j] = '\\';
             ++j;
             v[j] = 'n';
             ++j;
             break;
         default:
             v[j] = u[i];
	     ++j;
     }
 } 
}

int main()
{
 i = 0;
 while (((c = getchar()) != EOF) && (i < LEN))
 {
     u[i] = c;
     ++i;
 }
 replace(u,v);
 for (j = 0;j < LEN;++j)
 {
 printf("%c", v[j]);
 }
}
