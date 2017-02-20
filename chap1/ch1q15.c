#include <stdio.h>

float fahr_cel(float x){
 float y;
 y = (5.0/9.0) * (x -32);
 return(y);
}

int main()
{
 float fahr,celcius;
 float lower,upper,step;
 
 lower = 0;
 upper = 300;
 step = 20;
 
 fahr = lower;
 while (fahr <= upper){
     celcius = fahr_cel(fahr);
     printf("%3.0f fahr = %6.1f celcius\n", fahr, celcius);
     fahr = fahr + step;
 }
}
