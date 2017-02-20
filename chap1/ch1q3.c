/*converts temp in farenhiet to degree celcius*/

#include <stdio.h>
main()
{
 float fahr, celcius;
 float lower, upper, step;

 lower = 0;
 upper = 300;
 step = 20;

 fahr = lower;
 printf("temperature conversion table\n");
 while (fahr <= upper){
     celcius = (5.0/9.0) * (fahr - 32);
     printf("%3.0f fahr = %6.1f celcius\n", fahr, celcius);
     fahr = fahr + step;
     }
}
