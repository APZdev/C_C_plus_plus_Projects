/*
Exercise 6
    Le jeu du perroquet consiste à prendre un nombre au hasard compris entre 10 et 99 et à en construire un autre
    formé du nombre initial répété 3 fois. Par exemple, 12 donnerait 121212, 53 donnerait 535353.
    Construire un programme C permettant de simuler ce jeu.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int rng, min = 10, max = 99;

    //Make rand() be based on time as seed
    srand(time(NULL));
    rng = rand() % (max - min + 1) + min;

    unsigned int finalResult = rng + rng * 100 + rng * 10000;
    printf("The parrot said : %d", finalResult);

    return 0;
}
