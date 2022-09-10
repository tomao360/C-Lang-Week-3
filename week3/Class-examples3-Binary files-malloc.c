#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)

int main_1_0_3()
{
	//Example 1
	struct Student
	{
		int age;
		char name[100];
		int classLevel;
	};

	struct Student s = { 20, "Amos", 1 };

	FILE* f = fopen("oneStudent.dat", "w");

	if (f != NULL)
	{
		fwrite(&s, sizeof(struct Student), 1, f);
		fclose(f);
	}
	else
	{
		printf("ERROR");
	}
	
	//Example 2
	
	//Prepare Memory
	struct Student* currentStudent;
	struct Student* list;
	
	int size = 4;
	currentStudent = malloc(sizeof(struct Student) * size);
	list = currentStudent; //list is original pointer

	currentStudent->age = 30;
	strcpy(currentStudent->name, "Matan");
	currentStudent->classLevel = 2;
	currentStudent++;

	currentStudent->age = 22;
	strcpy(currentStudent->name, "Amos");
	currentStudent->classLevel = 3;
	currentStudent++;

	currentStudent->age = 24;
	strcpy(currentStudent->name, "Amram");
	currentStudent->classLevel = 5;
	currentStudent++;

	currentStudent->age = 120;
	strcpy(currentStudent->name, "Yaacov");
	currentStudent->classLevel = 123;


	//Save Memory
	f = fopen("students.dat", "w");
	fwrite(list, sizeof(struct Student), size, f);
	fclose(f);

	//Free
	free(list);


	return 0;
}