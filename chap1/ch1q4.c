/*this converts celcius to fahrenheit*/
#include <stdio.h>
main()
{
 float fahr, celcius;
 printf("how much celcius\n");
 scanf("%f", &celcius);
 fahr = ((9.0/5.0) * celcius) + 32;
 printf("%.1f celcius is equal to %.1f farenhiet\n", celcius, fahr);
}
