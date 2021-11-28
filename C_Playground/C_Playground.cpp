/*
    Exercice : 2
    Auteur : SALHAB Charbel,POMPOSELLI Adam,MICHEL Louis
    Date : 26/11/2021
    Description : Il s'agit d 'un programme C permettant de saisir un nombre quelconque et de l'afficher en comptant chacun des chiffres qui le constitue
*/

#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
    unsigned long long next_input = 0;

    int recompute = 1;
    while (recompute)
    {
        unsigned long long input;
        unsigned long long final_input = 0;
        short number = 0;
        short next_number = 10;
        short number_repetition_count = 1; //variable pour compter le nombre de fois

        if (next_input > 0)
            input = next_input;
        else
        {
            printf("Saisir un nombre : ");
            scanf_s("%I64u", &input); //Register user input
        }

        next_input = 0;

        while (input != 0) //Reverse user input
        {
            //Increase place value of reversed and add last digit to reversed
            final_input = (final_input * 10) + (input % 10);
            input /= 10; // Remove last digit from number
        }

        while (final_input != 0) 
        {
            number = final_input % 10;
            next_number = final_input % 100 / 10;

            while(number == next_number) 
            {
                number_repetition_count++;
                final_input /= 10;
                number = final_input % 10;
                next_number = final_input % 100 / 10;
            }

            printf("%d%d", number_repetition_count, number);

            //Get order of magnitude
            int num, mag = 0;
            num = number_repetition_count;
            while (num > 0)
            {
                mag++;
                num /= 10;
            }

            if (next_input > 0)
                next_input *= (int)pow(10, mag + (double)1);

            next_input += (long long)number_repetition_count * (long long)pow(10, mag) + number;

            final_input /= 10;
            number_repetition_count = 1; //Reset repetition count
        }

        printf("\n");
        printf("Recompute 1\n");
        printf("To Quit, Tap 0\n");

        printf("Choice -> ");
        scanf_s("%d", &recompute);
    }
    return 0;
}