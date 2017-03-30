#include <stdio.h>
#include <limits.h>

void main()
{
 printf("The range of unsigned char is 0 to %d\n", UCHAR_MAX);
 printf("The range of signed char is %d to %d\n", SCHAR_MIN, SCHAR_MAX);
 printf("The range of unsigned short is from 0 to %d\n", USHRT_MAX);
 printf("The range of signed short is from %d to %d\n", SHRT_MIN, SHRT_MAX);
 printf("The range of unsigned int is from 0 to %d\n", UINT_MAX);
 printf("The range of signed int is from %d to %d\n", INT_MIN, INT_MAX);
 printf("The range of unsigned long is from 0 to %d\n", ULONG_MAX);
 printf("The range of signed long is from %d to %d\n", LONG_MIN, LONG_MAX);
}
