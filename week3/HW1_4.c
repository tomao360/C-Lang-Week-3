#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)

int main_1_4()
{
	int arr[13] = {23, 11, 5, 160, 87, 90, 3, 13, 10, 34, 2, 64, 31};

	FILE* f = fopen("Q4.bin", "w");
	if (f != NULL)
	{
		int written = fwrite(arr, sizeof(int), 13, f);
		fclose(f);
	}
	else
	{
		printf("ERROR");
	}

	return 0;
}