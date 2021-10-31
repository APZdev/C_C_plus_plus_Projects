/*
Exercise 3
En cas de panne grave d'un v�hicule, la soci�t� d'assurance AXA pratique la m�thode de la franchise dite
variable. Le principe en est simple : le montant de la franchise laiss�e � la charge d'un assur� doit repr�senter
10% du montant des r�parations. Toutefois, cette franchise ne doit pas descendre en dessous de 50 euros ni
d�passer 800 euros.
Construire un programme C complet qui demande le montant des r�parations et affiche la franchise laiss�e � la
charge de l'assur�, ainsi que le montant qui lui sera rembours�.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

double CalculateDeductible(double value);
double ClampValue(double value, double minVal, double maxVal);

int main()
{
    double inputValue;
    printf("Price of repairs -> ");
    scanf_s("%lf", &inputValue);

    double deductibleAmount = CalculateDeductible(inputValue);
    printf("From the %.2lf Euros you will pay, we'll keep %.2lf Euros, and refund you %.2lf Euros", inputValue,  deductibleAmount, inputValue - deductibleAmount);

    return 0;
}

double CalculateDeductible(double value)
{
    return ClampValue(value * 0.1, 50, 800);
}

double ClampValue(double value, double minVal, double maxVal)
{
    if (value < minVal)
        return minVal;
    else if (value > maxVal)
        return maxVal;
    else
        return value;
}
