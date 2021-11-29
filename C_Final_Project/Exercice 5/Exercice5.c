#include <stdio.h>
#include <stdlib.h>

/*
    Exercice : 5
    Auteurs : SALHAB Charbel,POMPOSELLI Adam,MICHEL Louis
    Date : 12/11/2021
    Description : Construire un programme C complet, permettant d'indiquer le meilleur tarif T.T.C. à un client en
    fonction de la distance qu'il doit parcourir et de la durée de location.
*/

#include <stdio.h>
#include <math.h>

int main(int argc, char**argv)
{
    double distance = 0;//we use double because it's easier when we calculate
    double total_diesel = 0;//total price for diesel
    double total_essence = 0;//total price for essence
    double price_essence_location_TTC = 0;//price of essence location whithout insurance price's
    double price_diesel_location_TTC = 0;//price of essence location whithout insurance price's
    double duration = 0;
    int retry = 1;

    while (retry)
    {
        printf("\nTapez une distance:");
        scanf("%lf", &distance);
        printf("\nTapez une duree de location(min 1 jours):");
        scanf("%lf", &duration);

        if (duration==0) { printf("Erreur"); } else {

        if (distance >= 1000 / 13) //around 76 km distance from which the minimum km package is exceeded
            price_essence_location_TTC = (30 * duration + 0.13 * distance) * 1.20;
        else
            price_essence_location_TTC = (30 * duration + 10) * 1.20;
            // essence location with TVA based on duration and distance cost

        if (distance >= 800 / 11) //around 72km distance from which the minimum km package is exceeded
            price_diesel_location_TTC=(33.40 * duration + 0.11 * distance) * 1.20;
        else
            price_diesel_location_TTC=(33.40 * duration + 8) * 1.20;
            // diesel location with TVA based on duration and distance cost

        if ((price_essence_location_TTC*0.04) < 40)//take 4% of location TTC price's
            total_essence=price_essence_location_TTC + 40;
        else if ((price_essence_location_TTC*0.04) > 85)
            total_essence=price_essence_location_TTC + 85;
        else
            total_essence=price_essence_location_TTC * 0.04;
        //adding insurance for essence

        if ((price_diesel_location_TTC * 0.04) < 40)//take 4% of location TTC price's
            total_diesel=price_diesel_location_TTC + 40;
        else if ((price_diesel_location_TTC * 0.04) > 85)
            total_diesel=price_diesel_location_TTC + 85;
        else
            total_diesel = price_diesel_location_TTC * 0.04;
            //adding insurance for diesel


        printf("\nLe montant TTC pour une location essence :%.2lf euros", total_essence);
        printf("\nLe montant TTC pour une location diesel :%.2lf euros", total_diesel);

        if (total_diesel > total_essence)
            printf("\nLa formule essence est plus avantageuse.");
        else
            printf("\nLa formule diesel est la plus avantageuse."); }

        printf("\n__________________\n");
        printf("|            |     |\n");
        printf("|   Restart  |  1  |\n");
        printf("|   Quit     |  0  |\n");
        printf("|____________|_____|\n\n");

        printf("Choice -> ");
        scanf(" %d", &retry);
    }
    return 0;
}