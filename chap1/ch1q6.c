/*normal characters outputs 1 whereas EOF Ctrl-D outputs 0*/
#include <stdio.h>
main()
{
 if (getchar() != EOF){
 printf("1\n");
 }
 else {
 printf("0\n");
 }
}
