#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)

int main_1_3()
{
	struct Student
	{
		int val;
		char name[100];
		short answer;
	};

	struct Student studentsList[3];
	
	for (int i = 0; i < 3; i++)
	{
		printf("Pleas enter value and name + ENTER\n");
		scanf("%d %s", &studentsList[i].val, studentsList[i].name);

		if (strlen(studentsList[i].name) > 5 && studentsList[i].val > 10)
		{
			studentsList[i].answer = 1;
		}
		else
		{
			studentsList[i].answer = 0;
		}
	}

	FILE* f = fopen("Q3.bin", "w");
	if (f != NULL)
	{
		int written = fwrite(studentsList, sizeof(struct Student), 3, f);
		fclose(f);
	}
	else
	{
		printf("ERROR");
	}

	return 0;
}