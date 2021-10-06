/*
Exercice 4
Construire un programme permettant, � partir de l'�ge d'un individu saisi en nombre de secondes, de d�terminer
celui-ci sur les diff�rentes plan�tes du syst�me solaire.
    1.Mercure : la p�riode orbitale vaut 0.2408467 ann�es terrestres
    2.Venus : la p�riode orbitale vaut 0.61519726 ann�es terrestres
    3.Terre : la p�riode orbitale vaut 1.0 une ann�e terrestre, 365.25 jours terrestres, ou 31557600 secondes
    4.Mars : la p�riode orbitale vaut 1.8808158 ann�es terrestres
    5.Jupiter : la p�riode orbitale vaut 11.862615 ann�es terrestres
    6.Saturne : la p�riode orbitale vaut 29.447498 ann�es terrestres
    7.Uranus : la p�riode orbitale vaut 84.016846 ann�es terrestres
    8.Neptune : la p�riode orbitale vaut 164.79132 ann�es terrestres
*/

#include <stdio.h>
#include <stdlib.h>

double YearsToSeconds(double ageInYears);
double SecondsToYears(double ageInSeconds);
double PlanetConverter(int planetId);

int main()
{
    long long ageInSeconds = 1000000000;
    printf("What is your age ? -> ");
    //scanf_s("%lld", &ageInSeconds);

    printf("\n\nSelect a planet : \n");
    printf("1.Mercure\n");
    printf("2.Venus  \n");
    printf("3.Terre  \n");
    printf("4.Mars   \n");
    printf("5.Jupiter\n");
    printf("6.Saturne\n");
    printf("7.Uranus \n");
    printf("8.Neptune\n");
    printf("-> ");

    int selectedPlanetId;
    scanf_s("%d", &selectedPlanetId);
    double finalPlanetAgeInYears = SecondsToYears(ageInSeconds) / PlanetConverter(selectedPlanetId);
    printf("\nYou would be %.2lf years old on the planet %d while being %.2lf years old on the Earth", finalPlanetAgeInYears, selectedPlanetId, SecondsToYears(ageInSeconds));

    return 0;
}

double PlanetConverter(int planetId)
{
    switch (planetId)
    {
    case 1: // Mercure
        return 0.2408467;
        break;
    case 2: //Venus
        return 0.61519726;
        break;
    case 3: //Terre
        return 1.0;
        break;
    case 4: //Mars
        return 1.8808158;
        break;
    case 5: //Jupiter
        return 11.862615;
        break;
    case 6: //Saturne
        return 29.447498;
        break;
    case 7: //Uranus
        return 84.016846;
        break;
    case 8: //Neptune
        return 164.79132;
        break;
    default:
        return 1.0;
        break;
    }
}

double YearsToSeconds(double ageInYears)
{
    return (double)ageInYears * (double)31557600;
}

double SecondsToYears(double ageInSeconds)
{
    return (double)ageInSeconds / (double)31557600;
}
