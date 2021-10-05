// Exercice 3

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
    char searchedCharacter = 'x';
    char previousCharacter = ' ';

	for (size_t i = 0; i < 8; i++)
	{
		char inputString[] = "xxyxxxZZ";
		unsigned int chainSize = 0;

		int counter = 1;
		while (inputString[i] == inputString[counter])
		{
			printf("%c\n", inputString[counter]);
			counter++;
		}
	}

	//char dest[DEST_SIZE] = "";
	//strcat(dest, "Look Here");
	//printf(dest);

}


