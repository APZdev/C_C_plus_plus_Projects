/*
    Exercice : 2
    Auteur : SALHAB Charbel,POMPOSELLI Adam,MICHEL Louis
    Date : 26/11/2021
    Description : Il s'agit d 'un programme C permettant de saisir un nombre quelconque et de l'afficher en comptant chacun des chiffres qui le constitue
*/

#include <stdio.h>

int main(int argc,const char * argv) 
{
    int input ; //number of departure
    int temp_number = 0;
    int final_input = 0;
    int number = 0; //first taken number
    int next_number = 11; //the next number
    int nb1 = 0; //variable to count the number of times that one digit goes out
    int nb2 = 0; //variable to count the number of zero

    int retry = 1;
    while (retry)
    {

        printf("Saisir un nombre : ");
        scanf("%d",&input);

        if (input < 0) //if the input is negatif
            input *= -1;

        while (input % 10 == 0) //we check if the number finish with zeros before we reverse it
        {
            nb2++; //count the zeros only
            input /= 10;
        }

        temp_number = input;

        while (temp_number != 0) //Reverse user input
        {
            //Increase place value of reversed and add last digit to reversed
            final_input = (final_input * 10) + (temp_number % 10);
            temp_number /= 10; // Remove last digit from number
        }

        if (final_input != 0)
            input = final_input;
      
       while (input != 0)
        {
            number = input % 10;
            next_number = input % 100 / 10;
            nb1++;
            input /= 10; //if we only have the same number once

            while (number == next_number) //if we have the same number several times
            {
                number=input % 10;
                next_number=input % 100 / 10;
                nb1++;
                input /= 10;
            }

            printf ("%d%d", nb1, number); //display number of digits and the digit
            nb1 = 0;
        }

        if (nb2 != 0)
            printf("%d""0", nb2); //display the number of zero if not empty

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