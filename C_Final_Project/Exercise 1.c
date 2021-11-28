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
        int a,b, lines;

        printf("Enter the number of lines -> ");
        scanf(" %d", &lines);

        //printing top semi circular shapes of heart
        for(a = lines / 2; a <= lines; a += 2){
        //Printing Spaces
            for(b = 1; b < lines-a; b+=2)
                printf(" ");

            //printing stars for left semi circle
            for(b = 1; b <= a; b++)
                printf("*");

            //Printing Spaces
            for(b = 1; b <= lines-a; b++)
                printf(" ");

            //printing stars for right semi circle
            for(b = 1; b <= a; b++)
                printf("*");

            //move to next row
            printf("\n");
        }

        //printing inverted start pyramid
        for(a = lines; a >= 1; a--){
            for(b = a; b < lines; b++)
                printf(" ");

            for(b = 1; b <= (a*2)-1; b++)
                printf("*");

            //move to next row
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