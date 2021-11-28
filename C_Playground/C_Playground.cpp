#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int retry = 1;
    while (retry)
    {
        unsigned long input;
        unsigned long finalInput = 0;
        short number = 0;
        short next_number = 10;
        short number_repetition_count = 0; /*variable pour compter le nombre de fois*/

        printf("Saisir un nombre : ");
        scanf_s("%d", &input); //Register user input

        int temp_number = input;
        while (temp_number != 0) //Reverse user input
        {
            /* Increase place value of reversed and add last digit to reversed */
            finalInput = (finalInput * 10) + (temp_number % 10);
            temp_number /= 10; // Remove last digit from number
        }

        while (finalInput >= 10) {
            number = finalInput % 10;
            next_number = finalInput % 100 / 10;
            number_repetition_count++;

            while(number == next_number) {
                number_repetition_count++;
                finalInput /= 10;
                number = finalInput % 10;
                next_number = finalInput % 100 / 10;
            }

            printf("%d%d", number_repetition_count, number);
            finalInput /= 10;
            number_repetition_count = 0; //Reset repetition count
        }
        printf("\n");
        printf(" __________________\n");
        printf("|            |     |\n");
        printf("|   Restart  |  1  |\n");
        printf("|   Quit     |  0  |\n");
        printf("|____________|_____|\n\n");

        printf("Choice -> ");

        scanf_s("%d", &retry);
    }
    return 0;
}
