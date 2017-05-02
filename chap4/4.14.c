#include <stdio.h>

#define swap(t,x,y) { t temp;\
                      temp = x;\
                      x = y;\
                      y = temp; }

int main()
{
 int a,b;
 scanf("%d%d", &a, &b);
 printf("the values entered are a = %d & b = %d\n", a, b);
 swap(int,a,b);
 printf("After swapping a = %d & b = %d\n", a, b);
}
