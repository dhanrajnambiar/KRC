/*converts fahrenhiet to celcius from 300 to 0*/
#include <stdio.h>
main()
{
 float fahr, celcius;
 float lower, upper, step;

 lower = 0;
 upper = 300;
 step = 20;

 fahr = upper;
 while (fahr >= lower){
     celcius = (5.0/9.0) * (fahr - 32);
     printf("%3.0f fahr = %6.1f celcius\n", fahr, celcius);
     fahr = fahr - step;
     }
}
