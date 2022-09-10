#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)

int main_1_5()
{
	FILE* f = fopen("C:\\Users\\97252\\source\\repos\\week3\\week3\\ques4.bin", "r");

	if (f)
	{
		int item;
		int sum = 0;
		int numbers = 0;

		while (fread(&item, sizeof(int), 1, f))
		{
			printf("The numbers in the array: %d\n\n", item);
			sum = sum + item;
			numbers++;
		}
		printf("The sum is: %d\n", sum);
		printf("There were %d cells in the array\n", numbers);

		fclose(f);
	}
	else
	{
		printf("ERROR");
	}


	//Another way
	/*
	FILE* f1 = fopen("C:\\Users\\97252\\source\\repos\\week3\\week3\\ques4.bin", "r");
	int buffer;

	if (f)
	{
		int read = 0;
		int count = 0;
		int sum = 0;
		while ((read = fread(buffer, sizeof(int), 1, f)) > 0)
		{
			count++;
			sum += buffer;
		}

		fclose(f);
	}
	else
	{
		printf("ERROR");
	}*/

	return 0;
}