#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void ClearScreen();
void PrintGameLine(int i);

int main()
{
    printf("Press - to go left or + to go right\n");
    printf("Press any key to start...");
    _getche();

    int i = 0;
    int endPoint = 5;

    ClearScreen();
    PrintGameLine(i);

    while (true)
    {
        char input = _getche();
        if (input == '+')
            i++;
        else if(input == '-')
            i--;
        else // Failed to read the key -> kill program
            return 1;

        if (i == endPoint)
        {
            ClearScreen();
            printf("The flea arrived to it's destination\n");
            return 0;
        }

        ClearScreen();
        PrintGameLine(i);
    }

    return 0;
}

void PrintGameLine(int i)
{
    printf("%d*****%d*****%d*****%d*****(( %d ))*****%d*****%d*****%d*****%d\n",
        i - 4, i - 3, i - 2, i - 1, i, i + 1, i + 2, i + 3, i + 4);
}

void ClearScreen()
{
#ifdef _WIN32
        system("cls"); //Check if windows OS
#else
        system("clear");
#endif
}
