/*
    Exercise : 3
    Auteur : SALHAB Charbel,POMPOSELLI Adam,MICHEL Louis
    Date : 27/11/2021
    Description : this program lets read sentence and determined mistake.
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc,const char * argv[])
{
    int restart = 1;

    while (restart)
    {
            char previous_word;
            char current_word;
            int continue_sentence = 1;
            int negation = 0;
            int subject = 0;
            int verb = 0;
            int punctuation = 0;
            int question = 0;
            char error = '0';

            printf("Type the order of the words in your sentence\n Ex : (S = Subject, V = Verb, C = Complement, et P = Ponctuation) : \n\n");
            printf("Type '0' to know if the sentence is correct -> ");

            while(continue_sentence && error == '0')
            {
                scanf(" %c", &current_word);
                previous_word = current_word;

                switch(current_word)
                {

                    case('0'):
                        continue_sentence = 0;
                        break;

                    case('S'):
                        if(punctuation)
                            error = 'P';
                        if(verb)
                            subject = 2;
                        else
                            subject = 1;
                            break;

                    case('V'):
                        if(punctuation)
                            error = 'P';
                        if(subject)
                            verb = 2;
                        else
                            verb = 1;
                            break;

                    case('C'):
                        if(punctuation)
                            error = 'P';
                        break;

                    case('N'):
                        negation = 1;
                        break;

                    case('P'):
                        if(punctuation)
                            error = 'P';
                        if(negation)
                            negation = 0;
                        else
                            error = 'N';
                            break;

                    case('.'):

                    case('!'):
                        if(punctuation)
                            error = 'p';
                        else
                            punctuation = 1;
                            break;

                    case('?'):
                        punctuation = 1;
                        question = 1;
                        break;
                }


                if(error == '0')
                {
                    if(question)
                    {
                        if(verb == 0)
                            error = 'V';
                        else if(subject == 0)
                            error = 'S';
                        else if(verb == 2)
                            error = 'Q';
                    }
                }
                else
                {
                    if(subject == 0)
                        error = 'S';
                    else if(verb == 0)
                        error = 'V';
                    else if(verb == 1)
                        error = 'Q';
                }

                if(error == 'O')
                {
                    if(punctuation == 0)
                        error = 'P';
                }


                if(error == 'O')
                {
                    if(negation == 1)
                    error = 'N';
                }
            }

            switch(error)
            {
                case('p'):
                printf("\nThis sentence contain more than one ponctuation element.");break;

                case('P'):
                printf("\nThis sentence need at least one ponctuation element.");break;

                case('S'):
                printf("\nA sentence must contain a subject.");break;

                case('V'):
                printf("\nA sentence must contain a verb.");break;

                case('Q'):
                printf("\nYou should inverse the subject and the verb.");break;

                case('N'):
                printf("\nThe negation should be rephrased.");break;

                case('O'):
                printf("\nThe sentence is correct.");break;
            }

        printf("\n __________________\n");
        printf("|            |     |\n");
        printf("|   Restart  |  1  |\n");
        printf("|   Quit     |  0  |\n");
        printf("|____________|_____|\n\n");

        printf("Choice -> ");
        scanf(" %d", &restart);
    }
}
