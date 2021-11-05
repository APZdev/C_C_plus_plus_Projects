#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    char sentence[50] = "SNVPC.";
    int sentenceLength = sizeof(sentence) / sizeof(sentence[0]);

    int verbCount = 0;

    if (sentence[0] != 'S')
    {
        printf("ERROR : Sentence should start using a subject\n"); return 1;
    }

    int endPointIndex = 0;
    for (int i = 0; i < sentenceLength; i++)
    {
        if (sentence[i] == '\0')
        {
            //Get the last non null character of the array, the ponctuation point
            endPointIndex = i - 1;
            break;
        }
    }

    if (sentence[endPointIndex] != '?' && sentence[endPointIndex] != '!' && sentence[endPointIndex] != '.')
    {
        printf("ERROR : The sentence should finish with a ponctuation point\n");
        return 1;
    }


    for (int i = 0; i < sentenceLength; i++)
    {
        if (i > 0 && sentence[i] == 'S')
        {
            printf("ERROR : Subject should be on the beginning of the sentence\n"); return 1;
        }

        if (verbCount == 0 && sentence[i] == 'V')
        {
            verbCount = 1;
            //Contain a verb
        }
        else if(verbCount == 1 && sentence[i] == 'V')
        {
            verbCount = 2;
            break;
        }

        if (sentence[endPointIndex] == '?')
        {

        }
        else
        {
            if (sentence[i] == 'N' && sentence[i + 2] != 'P')
            {
                printf("ERROR : The negation form is not correct\n"); return 1;
            }
        }

        if (i == endPointIndex) break; //Check end of sentence
    }

    if (verbCount == 0) printf("ERROR : Does not contain a verb\n");
    if (verbCount >= 2) printf("ERROR : Sentence contain two or more verbs\n");

    return 0;
}
