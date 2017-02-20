#include <stdio.h>

int i,c,num_letter,ar_elmnt;
int array[15] = {0};

void printX_loop(i){
 int j;
 for (j = 1;j <= i;++j)
     printf("X");
 printf("\n");
}

int main(){
 num_letter = 0;
/*Below while loop goes through text stream and stores the number of letters in fields of array[15]*/
 while((c = getchar()) != EOF){
     num_letter = 1;
     while((c = getchar()) != EOF){
         if ((c != ' ') && (c != '\t') && (c != '\n'))
	     ++num_letter;
         else
             break;
     }
     ++array[num_letter - 1];/*number of 1 lettered word is stored in array[0] & so on*/
 }
 printf("\n");
 printf("----------------------------------------------------------------------\n");
 for (ar_elmnt = 0;ar_elmnt <= 14;++ar_elmnt){
     printf("%3d lettered :", ar_elmnt + 1);
     printX_loop(array[ar_elmnt]);
 }
 printf("----------------------------------------------------------------------\n");
}
