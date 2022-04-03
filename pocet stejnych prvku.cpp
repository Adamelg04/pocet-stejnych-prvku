#include <stdio.h>
#include <math.h>

int pocet[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
int cisla[10];

int main() 
{
	int znak = 0;
	int cislo = 0;

	FILE* soubor = fopen("file.txt", "r");

	if (soubor == NULL)
	{
		printf("Chyba: Soubor nelze otevrit.\n");
		return;
	}

	while (!feof(soubor)) 
	{
		fscanf(soubor, "%d", &cisla[znak]);
		znak++;
	}
	for (int i = 0; i < 10; i++)
	{
		cislo = cisla[i];
		pocet[cislo]++;
	}
	for (int j = 0; j < 10; j++) printf("Cislo %d je v souboru %dx\n", j, pocet[j]);


	if (fclose(soubor) == EOF) 
	{
		printf("Chyba: Soubor nelze zavrit.\n");
		return;
	}
	return;
}