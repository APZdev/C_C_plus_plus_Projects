/*
    Exercise : 4
    Auteur : SALHAB Charbel,POMPOSELLI Adam,MICHEL Louis
    Date : 26/11/2021
    Description : This program request a single character and give it's z-air corresponding output.
    Ex : C | 01000011 -> zz z z z zz zzzz z zz

*/

#include <stdio.h>
#include <math.h>

int main(int argc,const char * argv[]) 
{
    int retry = 1;
    while (retry)
    {
        char input;
        short input_length = 7;
        short mask = pow(2, 7);
        short next_bit_mask = pow(2, 6);
        short current_bit;
        short next_bit;
        short repetition_counter = 0;
        short ignore_first_bits = 1;
    
        printf("Enter a letter to output it's z-air code : ");
        scanf(" %c", &input);
    
        printf("[ %c ] Z-air Code [ ", input);
    
        while (input_length >= 0)
        {
            current_bit = (input & mask) > 0; //Get the current bit
            next_bit = (input & next_bit_mask) > 0;
            
            mask >>= 1; //Decrement the mask bit by 1 for the next iteration
            next_bit_mask >>= 1;
            
            if(repetition_counter < 1) //Prevent the bit indicator to print twice for each bit
            {
                if(current_bit > 0)
                    printf("z ");
                else
                    printf("zz ");
            }
            
            //Check if current bit is similiar to the previous one && if we didn't evaluated all the bits
            if(current_bit == next_bit && mask > 0)
                repetition_counter++;
            else
            {
                //Print the repeated bits as "z" 
                for (int i = 0; i < repetition_counter + 1; i++) 
                    printf("z");
                
                repetition_counter = 0; //Reset repetition counter when we printed all the counted "z"
                printf(" ");
            }
            
            input_length--;
        }
        printf(" ]");
    
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