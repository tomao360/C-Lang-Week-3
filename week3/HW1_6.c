#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)

int main_1_6()
{
	struct Student
	{
		int val;
		char name[100];
		short answer;
	};

	struct Student* currentStudent;
	struct Student* list;
	
	int num;
	printf("Please enter the number of structers that you need + ENTER\n");
	scanf("%d", &num);
	
	currentStudent = (struct Student*) malloc(sizeof(struct Student) * num);
	if (!currentStudent) //if there is no memory in heap, return
	{
		printf("ERROR");
		return;
	}

	list = currentStudent; //original pointer

	int value = 0;
	for (int i = 0; i < num; i++)
	{
		printf("Pleas enter value and name + ENTER\n");
		scanf("%d %s", &currentStudent->val, currentStudent->name);

		if (strlen(currentStudent->name) > 5 && currentStudent->val > 10)
		{
			currentStudent->answer = 1;
			value = value + 1;
		}
		else
		{
			currentStudent->answer = 0;
		}

		currentStudent++;
	}

	printf("The value of val is: %d", value);

	FILE* f = fopen("Q6.bin", "w");
	if (f != NULL)
	{
		fwrite(list, sizeof(struct Student), num, f);

		fclose(f);
	}
	else
	{
		printf("ERROR");
	}

	free(list);

	return 0;
}