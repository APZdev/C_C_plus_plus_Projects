/*
    Exercise : 1
    Auteur : SALHAB Charbel,POMPOSELLI Adam,MICHEL Louis
    Date : 26/11/2021
    Description : Request the number of rows then display a heart
*/

#include <stdio.h>  
   
int main(int argc,const char * argv[]) 
{
    int retry = 1;
    while (retry)
    {
        int i,j, rows;
        
        printf("Enter the number of rows -> ");
        scanf(" %d", &rows);  

        /* printing top semi circular shapes of heart */
        for(i = rows / 2; i <= rows; i += 2){ 
        /* Printing Spaces */
            for(j = 1; j < rows-i; j+=2)
                printf(" ");  

            /* printing stars for left semi circle */
            for(j = 1; j <= i; j++)
                printf("*");  

            /* Printing Spaces */
            for(j = 1; j <= rows-i; j++)
                printf(" ");  

            /* printing stars for right semi circle */
            for(j = 1; j <= i; j++)
                printf("*");  

            /* move to next row */
            printf("\n");  
        }  
        
        /* printing inverted start pyramid */
        for(i = rows; i >= 1; i--){  
            for(j = i; j < rows; j++)
                printf(" ");  

            for(j = 1; j <= (i*2)-1; j++)
                printf("*");  

            /* move to next row */
            printf("\n");  
        }  

        printf("\n __________________\n");
        printf("|            |     |\n");
        printf("|   Restart  |  1  |\n");
        printf("|   Quit     |  0  |\n");
        printf("|____________|_____|\n\n");
    
        printf("Choice -> ");
        scanf(" %d", &retry);
    }
   
    return 0;  
}  