/*
Aufgabe		
Autor		Florian Bopp
Datum		

Kurzbeschreibung:	
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>


/******************functionsprototypes**********************/
void flashStandardInput(void);
void newline(void);
void ausgabe(int feld[9][9]);
int ist_loesung(int feld[9][9]);

/******************Main function********************/
int main(void) {
	int feld[9][9] = { 0 };
	int gelFeld[9][9] = { {1,2,3,4,5,6,7,8,9}, {4,5,6,7,8,9,1,2,3}, {7,8,9,1,2,3,4,5,6}, {2,3,4,5,6,7,8,9,1}, {5,6,7,8,9,1,2,3,4}, {8,9,1,2,3,4,5,6,7}, {3,4,5,6,7,8,9,1,2}, {6,7,8,9,1,2,3,4,5}, {9,1,2,3,4,5,6,7,8} };

	ausgabe(gelFeld);
	if (ist_loesung(gelFeld))
		printf("Das Sudoku Feld ist korrekt geloest!\n");
	else
		printf("Das Sudoku Feld ist nicht korrekt geloest!\n");
	newline();
	return 0;
}

/******************Functions*******************/
void ausgabe(int feld[9][9]) {
	for (int i = 0; i < 9; i++)
	{
		if (i%3==0 && i != 0)
		{
			printf("  = = =  = = =  = = =\n|");
		}
		else
			printf("|");
		for (int j = 0; j < 9; j++)
		{
			
			if (j % 3 == 0)
			{
				printf("|");
			}
			printf("%i|", feld[i][j]);
		}
		printf("|\n");
	}
}

int ist_loesung(int feld[9][9]) {

	for (int i = 0; i < 9; i++)
	{
		int zeile[9] = { 0 };
		int spalte[9] = { 0 };

		for (int j = 0; j < 9; j++)
		{
			switch (feld[j][i]){
			case 1:		spalte[0]++;
						if (spalte[0] > 1)
							return 0;
				break;
			case 2:		spalte[1]++;
						if (spalte[1] > 1)
							return 0;
				break;
			case 3:		spalte[2]++;
						if (spalte[2] > 1)
							return 0;
				break;
			case 4:		spalte[3]++;
						if (spalte[3] > 1)
							return 0;
				break;
			case 5:		spalte[4]++;
						if (spalte[4] > 1)
							return 0;
				break;
			case 6:		spalte[5]++;
						if (spalte[5] > 1)
							return 0;
				break;
			case 7:		spalte[6]++;
						if (spalte[6] > 1)
							return 0;
				break;
			case 8:		spalte[7]++;
						if (spalte[7] > 1)
							return 0;
				break;
			case 9:		spalte[8]++;
						if (spalte[8] > 1)
							return 0;
				break;
			default:
						return 0;
						break;
			}


			switch (feld[i][j]){
			case 1:		zeile[0]++;
						if (zeile[0] > 1)
							return 0;
				break;
			case 2:		zeile[1]++;
						if (zeile[1] > 1)
							return 0;
				break;
			case 3:		zeile[2]++;
						if (zeile[2] > 1)
							return 0;
				break;
			case 4:		zeile[3]++;
						if (zeile[3] > 1)
							return 0;
				break;
			case 5:		zeile[4]++;
						if (zeile[4] > 1)
							return 0;
				break;
			case 6:		zeile[5]++;
						if (zeile[5] > 1)
							return 0;
				break;
			case 7:		zeile[6]++;
						if (zeile[6] > 1)
							return 0;
				break;
			case 8:		zeile[7]++;
						if (zeile[7] > 1)
							return 0;
				break;
			case 9:		zeile[8]++;
						if (zeile[8] > 1)
							return 0;
				break;
			default:
						return 0;
						break;
			}
		}
	}
	
	return 1;
}

void flashStandardInput(void)
{
	int intCharacter;
	while ((intCharacter = getchar()) != '\n' && intCharacter != EOF);
}

void newline(void) {
	printf("\n");
}


/********************Sichere Abfrage*******************
do {
	printf("Bitte Dimension der Matrix eingeben (1, 2 oder 3 Dimensionen): ");
	check = scanf("%lf", &dimensionen);
	flashStandardInput();
	newline();
} while (check == 0 || dimensionen < 1 || dimensionen > 3 || dimensionen != (int)dimensionen); //sichere Abfrage
*/
