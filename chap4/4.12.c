#include <stdio.h>

#define MAX 20

char s[MAX];

void itoa(int n)
{
 int i = 0;
 if (n < 0)
 {
     n = -n;
     s[i++] = '-';
 }
 if (n / 10)
     itoa(n / 10);
 s[i++] = n % 10;
}

