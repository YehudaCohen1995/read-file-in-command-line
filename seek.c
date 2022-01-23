/******************************************************************************

Welcome to my program .
creat by yeouda cohen 
date do day (16/01/2022)
this program doze: For each file in the transferred file list,
 the program prints a message to the standard output
Which contains the husky code of the character instead of the n in the file

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

enum {NO,YES};
int mount_word_in_file(FILE * file);

int main(int agrc,char *argv[])
{
    FILE * ifp; /* this for file */
	int n = 0;
 	int index = 2 ;/* from file */
 	char n_char = 'o';
	int mount = 0 ; 

    /* you have to put the neme of program --> seek number of partmer -->11 
    and list two parmater like file name  */
    if(agrc < 4){
        printf("Sory son ,you enter only %d you need to enter \n ",agrc);
        return NO;
    }

    /* n mean where to stop */ ;
    n = atoi(argv[1]);

    if(n< 1){
        printf("Sory my father ,you enter %d but is need to by great form ziro \n",n);
     return NO;
    }
   
    while(index < agrc){
       
        ifp = fopen(argv[index],"r");
       
        /* maby the number of word is list form n */
        
        if(ifp == NULL){
            printf("I can't  open this file sory --> %s  \n",argv[index]);
        }else if((mount = mount_word_in_file(ifp)) < n){
            printf("in this file %s the number of word %d and n %d so it lass!! \n",argv[index],mount,n);
        }else{
            fseek(ifp,n-1,SEEK_SET);
            n_char = fgetc(ifp);

            /* %d displays the integer value of a character
             %c displays the actual character */
            printf("ASCII value of %c = %d in the file: %s \n", n_char, n_char,argv[index]);
        }
        index++;
    }
    
    return 0;
    
}
/* this mothed return how many world in the file */
int mount_word_in_file(FILE * file){
    fseek(file,0,SEEK_END);
    return ftell(file);
    }
