/*
Aufgabe		Sudoku
Autor		Florian Bopp
Datum		7.5.18

Kurzbeschreibung:	Dieses Programm überprüft ob ein Sudoku Feld korrekt gelöst ist.
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
int spalten(int feld[9][9], int i, int j, int spalte[9]);
int zeilen(int feld[9][9], int i, int j, int zeile[9]);
int blocks(int feld[9][9], int i, int j, int block[9]);


/******************Main function********************/
int main(void) {
	
	int Feld[9][9] = { 0 }; //null feld
	//gelöstes Feld
	int gelFeld[9][9] = { {1,2,3,4,5,6,7,8,9}, {4,5,6,7,8,9,1,2,3}, {7,8,9,1,2,3,4,5,6}, {2,3,4,5,6,7,8,9,1}, {5,6,7,8,9,1,2,3,4}, {8,9,1,2,3,4,5,6,7}, {3,4,5,6,7,8,9,1,2}, {6,7,8,9,1,2,3,4,5}, {9,1,2,3,4,5,6,7,8} };
	//nichtgelöstes Feld
	int nichtgelFeld[9][9] = { { 1,2,3,4,5,6,7,8,9 },{ 4,5,6,7,8,9,1,2,3 },{ 7,8,9,1,2,3,4,5,6 },{ 2,3,4,5,6,7,8,9,1 },{ 5,6,7,8,9,1,2,3,4 },{ 8,9,1,2,3,4,5,6,7 },{ 3,4,5,6,7,8,9,1,2 },{ 6,7,8,9,1,2,3,4,5 },{ 9,1,2,3,4,5,6,7,8 } };

	ausgabe(gelFeld); //gelFeld steht für gelöstes Feld
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

void nullen(int array1[9]) {
	for (int i = 0; i < 9; i++)
		array1[i] = 0;
}

int ist_loesung(int feld[9][9]) { //lösungsfunktion
	int spalte[9] = { 0 };
	int zeile[9] = { 0 };
	int block[9] = { 0 };
	
	for (int i = 0; i < 9; i++)	{
		nullen(spalte);
		nullen(zeile);

		for (int j = 0; j < 9; j++)		{
			if (!spalten(feld, i, j, spalte)) //spaltenfunktion wird aufgerufen
				return 0;
			else if (!zeilen(feld, i, j, zeile)) //zeilenfunktion wird aufgerufen
				return 0;
			if ((i % 3 == 0 || i == 0) && (j % 3 == 0 || j == 0)) { //wenn an einer ecke eines 3x3 Block
				nullen(block);
				if (!blocks(feld, i, j, block)) //blockfunktion wird aufgerufen
 					return 0;
			}
		}
	}
	return 1;
}

int spalten(int feld[9][9], int i, int j, int spalte[9]) {
	//wenn in einer spalte eine zahl doppelt vorkommt wird 0 ausgegeben sonst 1
	//das Array Spalte speichert die Anzahl der vorkommenden zahlen
	switch (feld[j][i]) {	//i und j sind vertauscht damit die spalten durchgegangen werden und nicht die reihen
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
	return 1;
}

int zeilen(int feld[9][9], int i, int j, int zeile[9]) {
	//das Array Zeile speichert die Anzahl der vorkommenden zahlen
	switch (feld[i][j]) {
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
	default:	return 0;
		break;
	}
	return 1;
}

int blocks(int feld[9][9], int i, int j, int block[9]) {
	//zwei weitere vorloops um einen 3x3 block zu durchlaufen
	//das Array block speichert die Anzahl der vorkommenden zahlen
	for (int k = 0; k < 3; k++)	{
		for (int l = 0; l < 3; l++)	{
			switch (feld[i + k][j + l])	{
			case 1:		block[0]++;
				if (block[0] > 1)
					return 0;
				break;
			case 2:		block[1]++;
				if (block[1] > 1)
					return 0;
				break;
			case 3:		block[2]++;
				if (block[2] > 1)
					return 0;
				break;
			case 4:		block[3]++;
				if (block[3] > 1)
					return 0;
				break;
			case 5:		block[4]++;
				if (block[4] > 1)
					return 0;
				break;
			case 6:		block[5]++;
				if (block[5] > 1)
					return 0;
				break;
			case 7:		block[6]++;
				if (block[6] > 1)
					return 0;
				break;
			case 8:		block[7]++;
				if (block[7] > 1)
					return 0;
				break;
			case 9:		block[8]++;
				if (block[8] > 1)
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

void flashStandardInput(void){
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
