/*
Exercise 5
    Une dr�le d'imprimante circulaire a �t� invent�e r�cemment. Elle poss�de un pointeur sur la lettre A lorsqu�on
    l'allume, et d�placer ce pointeur d'une lettre (par exemple de A vers B ou de A vers Z) prend exactement une
    seconde.
    a) Construire un programme permettant de savoir combien de temps il faut pour d�placer le pointeur de la lettre
    A � une lettre quelconque.
    b) Construire un programme permettant de savoir combien de temps il faut pour d�placer le pointeur d'une lettre
    quelconque � une autre lettre quelconque
*/

#include <stdio.h>

int GetMovementStepAmount(char startingCharacter, char destinationCharacter);

int main()
{
    char startingCharacter = 'R';
    char destinationCharacter = 'K';

    printf("From letter %c to letter %c would take %d steps\n", startingCharacter, destinationCharacter, GetMovementStepAmount(startingCharacter, destinationCharacter));

    return 0;
}

int GetMovementStepAmount(char startingCharacter, char destinationCharacter)
{
    //Get the clockwise steps
    int clockwiseCount = (destinationCharacter - 65) % 26 - (startingCharacter - 65) % 26;

    //Get the anti-clockwise steps
    int antiClockwiseCount = 26 - clockwiseCount;

    //Get the smallest step choice and specify rotating direction using +-
    int finalSteps = clockwiseCount > antiClockwiseCount ? -antiClockwiseCount : clockwiseCount;

    return finalSteps;
}

