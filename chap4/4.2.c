#include <stdio.h>
#include <ctype.h>

#define MAX 50

int power_10(int p)
{
 int div = 1;
 for (int i = 0;i < p;++i)
     div *= 10;
 return(div);
}

double atof(char s[])
{
 double val,power;
 int i,sign,exp_sign,exponent;
 
 for (i = 0;isspace(s[i]);i++)
     ;
 sign = (s[i] == '-') ? -1:1;
 if (s[i] == '+' || s[i] == '-')
     i++;
 for (val = 0.0;isdigit(s[i]);i++)
     val = 10.0 * val + (s[i] - '0');
 if (s[i] == '.')
     i++;
 for (power = 1.0;isdigit(s[i]);i++)
 {
     val = 10.0 * val + (s[i] - '0');
     power *= 10;
 }
 val = sign * val / power;/*val becomes float equivalent to the value from string without considering the exponentila part and below if part handles exponential part*/
 if (s[i] == 'e' || s[i] == 'E')
 {
     i++;
     if (s[i] == '+')
     {
         exp_sign = 1;
         i++;
     }
     else
     {
         exp_sign = -1;
         i++;
     }
     for (exponent = 0;isdigit(s[i]);i++)
     {
         exponent = 10 * exponent + (s[i] - '0');
     }
     if (exp_sign == 1)
         return(val * power_10(exponent));
     else
         return(val / power_10(exponent));
 }
 else
     return val;
}

int main()
{
 char arr[MAX] = {0};
 int c,i = 0;
 while ((c = getchar()) != EOF)
 {
     arr[i] = c;
     ++i;
 }
 printf("%f\n", atof(arr));
}
