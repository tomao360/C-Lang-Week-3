#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)

int main_1_0_12()
{
	//Exercises 1 + 2
	short num;
	printf("Please enter a number + ENTER\n");
	scanf("%hu", &num);

	FILE* f = fopen("binFile.bin", "w");
	if (f != NULL)
	{
		fwrite(&num, sizeof(short), 1, f);

		fclose(f);
	}
	else
	{
		printf("ERROR");
	}

	f = fopen("binFile.bin", "r");
	if (f != NULL)
	{
		int read = fread(&num, sizeof(short), 1, f);
		printf("%d", num * num);

		fclose(f);
	}
	else
	{
		printf("ERROR");
	}

	return 0;
}

int main_1_0_34()
{
	//Exercise 3 + 4
	FILE* f = fopen("binFileEx3.bin", "w");
	int num;

	for (int i = 0; i < 10; i++)
	{
		
		printf("Please enter a number + ENTER\n");
		scanf("%d", &num);

		if (f != NULL)
		{
			fwrite(&num, sizeof(int), 1, f);
		}
		else
		{
			printf("ERROR");
		}
	}
	fclose(f);

	f = fopen("binFileEx3.bin", "r");
	if (f != NULL)
	{
		int sum = 0;
		for (int i = 0; i < 10; i++)
		{
			int readFile = fread(&num, sizeof(int), 1, f);
			int a = num;
			printf("%d\n", a);
			sum = sum + a;
		}
		printf("%d", sum);
		
		fclose(f);
	}
	else
	{
		printf("ERROR");
	}


	return 0;
}

int main_1_0_5()
{
	//Exercise 5
	struct Item
	{
		int barcode;
		int price;
		char name[100];
		char color[100];
	};

	struct Item item1;
	item1.barcode = 123;
	item1.price = 1000;
	strcpy(item1.name, "computer");
	strcpy(item1.color, "black");

	FILE* f = fopen("binFileEx5.bin", "w");
	if (f != NULL)
	{
		fwrite(&item1, sizeof(struct Item), 1, f);
		fclose(f);
	}
	else
	{
		printf("ERROR");
	}

	//קריאת הקובץ שלי
	struct Item item2;
	f = fopen("binFileEx5.bin", "r");
	if (f != NULL)
	{
		int read = fread(&item2, sizeof(struct Item), 1, f);
		fclose(f);
	}
	else
	{
		printf("ERROR");
	}

	//קריאת קובץ של מישהו אחר
	struct Item item3;
	FILE* f1 = fopen("C:\\Users\\97252\\source\\repos\\week3\\struct (1).bin", "r");
	if (f != NULL)
	{
		int read1 = fread(&item3, sizeof(struct Item), 1, f1);
		fclose(f1);
	}
	else
	{
		printf("ERROR");
	}


	return 0;
}