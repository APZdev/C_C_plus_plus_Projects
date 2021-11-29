/*
    Exercice : 2
    Auteur : SALHAB Charbel,POMPOSELLI Adam,MICHEL Louis
    Date : 26/11/2021
    Description : Il s'agit d 'un programme C permettant de saisir un nombre quelconque et de l'afficher en comptant chacun des chiffres qui le constitue
*/

#include <stdio.h>
#include <math.h>

int main(int argc,const char * argv[]) 
{
    unsigned long long next_input = 0;

    int retry = 1;
    while (retry)
    {
        unsigned long long input;
        int temp_number = 0;
        int final_input = 0;
        int number = 0;
        int next_number = 11;
        int n = 0; //Count the digit outputs
        int n0 = 0; //Count the number of excess 0
        short number_repetition_count = 1;

        if (next_input > 0)
            input = next_input;
        else
        {
            printf("Saisir un nombre : ");
            scanf("%llu", &input); //Register user input
        }

        next_input = 0;

         if (input < 0)
            input *= -1;

        while(input % 10 == 0) //Check if number finish with 0 before reverse
        {
            n0++; //Count number of excess 0
            input/=10;
        }

        temp_number = input;

        while (temp_number != 0) //Reverse user input
        {
            //Increase place value of reversed and add last digit to reversed
            final_input = (final_input * 10) + (temp_number % 10);
            temp_number /= 10; //Remove last digit from number
        }

        if (final_input!=0)
            input=final_input;

        printf("Output -> ");

        while (input!=0)
        {
            number = input % 10;
            next_number = input % 100 / 10;
            n++;
            input/=10;

            while(number==next_number)
            {
                number = input % 10;
                next_number = input % 100 / 10;
                n++;
                input /= 10;
            }

            printf("%d%d",n,number); //Display the number of digits and the digit itself

            //Get order of magnitude
            int num, mag = 0;
            num = n;
            while (num > 0)
            {
                mag++;
                num /= 10;
            }

            //Offset most left digits 
            if (next_input > 0)
                next_input *= (int)pow(10, mag + (double)1);


            //Add the remainder to the space created
            next_input += (long long)n * (long long)pow(10, mag) + number;

            n = 0;
        }
        
        if (n0 != 0)
            printf("%d""0", n0); //Display the excess 0

        printf("\n __________________\n");
        printf("|            |     |\n");
        printf("|  Recompute |  1  |\n");
        printf("|   Quit     |  0  |\n");
        printf("|____________|_____|\n\n");
    
        printf("Choice -> ");
        scanf(" %d", &retry);
    }
    return 0;
}