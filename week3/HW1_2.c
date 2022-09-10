#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)

int main_1_2()
{
	int arr1[4];
	int arr2[8];
	int sum1 = 0;
	int sum2 = 0;

	for (int i = 0;  i < 4;  i++)
	{
		int num;
		printf("Please enter a number to arr1 + ENTER\n");
		scanf("%d", &num);
		arr1[i] = num;
		sum1 = sum1 + num;
	}
	printf("The sum of arr1 is: %d", sum1);

	printf("\n");
	for (int i = 0; i < 8; i++)
	{
		int num;
		printf("Please enter a number to arr2 + ENTER\n");
		scanf("%d", &num);
		arr2[i] = num;
		sum2 = sum2 + num;
	}
	printf("The sum of arr2 is: %d", sum2);

	FILE* f = fopen("Q2.bin", "w");
	int written;
	if (f != NULL)
	{
		if (sum1 > sum2)
		{
			written = fwrite(arr1, sizeof(int), 4, f);
			fclose(f);
		}
		else
		{
			written = fwrite(arr2, sizeof(int), 8, f);
			fclose(f);
		}
	}
	else
	{
		printf("ERROR");
	}

	return 0;
}