#include <stdio.h>
/*This program counts the number of tabs spaces and newline charcters in an input stream of data*/
main()
{
 int blanks, tabs, newlines, chara;
 blanks = tabs = newlines = 0;
 while((chara = getchar()) != EOF){
     if (chara == ' ')
         ++blanks;
     if (chara == '\t')
	 ++tabs;
     if (chara == '\n')
	 ++newlines;
 }
printf("\nThe number of \nblanks   : %4d\ntabs     : %4d\nnewlines : %4d\n", blanks, tabs, newlines);
} 

