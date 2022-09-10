#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)

int main_1_1()
{
	int arr[10];

	for (int i = 0; i < 10; i++)
	{
		int num;
		printf("Please enter a number + ENTER\n");
		scanf("%d", &num);
		arr[i] = num;
	}

	FILE* f = fopen("Q1.bin", "w");
	if (f != NULL)
	{
		int written = fwrite(arr, sizeof(int), 10, f);
		fclose(f);
	}
	else
	{
		printf("ERROR");
	}

	return 0;
}

