#include <stdio.h>
#include <math.h>

double interestValue(double, double, int);
void printResultTable(double, double, int, double);

int main()
{
    double moneyAmount, taxFee, totalResult;
    int timeInYears;

    printf("Taper un captial : ");
    scanf_s("%lf", &moneyAmount);

    printf("Taper un taux en pourcentage : ");
    scanf_s("%lf", &taxFee);

    printf("Taper une duree : ");
    scanf_s("%d", &timeInYears);

    totalResult = interestValue(moneyAmount, taxFee / 100, timeInYears);

    printResultTable(moneyAmount, taxFee, timeInYears, totalResult);

    return 0;
}

void printResultTable(double capitalAmount, double taxFee, int timeInYears, double totalResult)
{
    printf("\033c"); //Clear terminal compatible only on windows
    printf(" ___________________________________________________________________\n");
    printf("|           Capital Accorde         |        %lf Euros         \n", capitalAmount);
    printf("|___________________________________|_______________________________\n");
    printf("|           Taux d'interet          |        %d %%             \n", (int)taxFee);
    printf("|___________________________________|_______________________________\n");
    printf("|               Duree               |        %d An             \n", timeInYears);
    printf("|___________________________________|_______________________________\n");
    printf("|      Prix a payer sous 10 ans     |        %lf Euros         \n", totalResult);
    printf("|___________________________________|_______________________________\n");

}

double interestValue(double _moneyAmount, double _taxFee, int _timeInYears)
{
    return  _moneyAmount + ((_moneyAmount * _taxFee) / (1 - pow((1 + _taxFee), -_timeInYears)));
}



