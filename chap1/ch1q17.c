#include <stdio.h>
#define MAX 100 /*maximum number of charcters in line that can be managed by the program*/
#define LIMIT 80/*number of chara's above which line will be printed*/


int len_array(char s[])
{
 int i = 1;/*doesn't overwrites 0th field of array*/
 int c;
 while (((c = getchar()) != EOF) && (c != '\n')){
     s[i] = c;
     ++i;
 }
 return i;
}

int main()
{
 int len,x;
 while((x = getchar()) != EOF){
     char arr[MAX] = {0}; /*clears the array befor next sentence read in*/
     arr[0] = x;/*stores the first chara after checking if it's not a EOF*/
     if ((len = len_array(arr)) > LIMIT)
         printf("%s\n", arr);
 }
}
