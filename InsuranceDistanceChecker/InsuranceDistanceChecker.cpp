/*
Exercice 2
    Construire un programme C complet permettant :
    • de calculer et d'afficher la distance d'arrêt sur route mouillée, connaissant la vitesse,
    • de calculer et d'afficher la distance d'arrêt sur route sèche, connaissant la vitesse,
    • de calculer et d'afficher l'écart entre les deux en valeur et en pourcentage (par rapport à la distance sur route sèche).
*/

#include <stdio.h>
#include <math.h>

double DistanceBasedOnFloor(bool roadIsWet, double speed);
double DistanceInterval(double a, double b);

int main()
{
    double speed = 65;
    double wetRoadDistance = DistanceBasedOnFloor(true, speed);
    double notWetRoadDistance = DistanceBasedOnFloor(false, speed);

    printf("Not wet road at %.3lf km/h, distance of %.3lf meters\n", speed, notWetRoadDistance);
    printf("Wet road at %.3lf km/h, distance of %.3lf meters\n", speed, wetRoadDistance);

    double distanceIntervalResult = DistanceInterval(wetRoadDistance, notWetRoadDistance);

    printf("The distance interval between wet and not wet road is %.2lf meters.\nIt's %d%% of the not wet road distance", 
           distanceIntervalResult, (int)(distanceIntervalResult / notWetRoadDistance * 100));

    return 0;
}

double DistanceBasedOnFloor(bool roadIsWet, double speed)
{
    return roadIsWet ? (3 * speed / 10 + pow(speed / 10, 2)) : (((double)3 / (double)4) * (3 * speed / 10 + pow(speed / 10, 2)));
}

double DistanceInterval(double a, double b)
{
    return a > b ? a - b : b - a;
}
