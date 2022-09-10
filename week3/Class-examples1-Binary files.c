#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)

int main_1()
{
	//Example 1 
	int a = 190;
	int b = 290;
	int c = 390;

	FILE* f = fopen("data.bin", "w");

	if (f != NULL)
	{
		//הפקודה מקבלת ארבעה פרמטרים: מה הכתובת, כמה מהכתובת לקחת, ולאן לכתוב
		fwrite(&a, sizeof(int), 1, f); //Buffer - the address that he want to take from memory
		fwrite(&b, sizeof(int), 1, f);
		fwrite(&c, sizeof(int), 1, f);

		fclose(f);
	}
	else
	{
		printf("ERROR");
	}

	f = fopen("data.bin", "r");
	if (f != NULL)
	{
		int read = fread(&c, sizeof(int), 1, f); //כמה חבילות הוא קרא read מחזיר למשתנה 
		printf("%d\n", c);
		read = fread(&c, sizeof(int), 1, f);
		printf("%d\n", c);
		read = fread(&c, sizeof(int), 1, f);
		printf("%d\n", c);
		//קריאת הקובץ מתחילה מההתחלה שלו ומכניסה את הערך בהתאם. יש קפיצות של 4 בתים

		fclose(f);
	}
	else
	{
		printf("ERROR");
	}

	//Example 2 - with structers
	FILE* f1;
	struct Student
	{
		char name[100];
		int age;
	};

	f1 = fopen("struct.bin", "w");

	struct Student stu;
	strcpy(stu.name, "Shlomi");
	stu.age = 18;

	if (f != NULL)
	{
		fwrite(&stu, sizeof(struct Student), 1, f1);
		fclose(f1);
	}
	else
	{
		printf("ERROR");
	}


	struct Student newStu;
	f1 = fopen("struct.bin", "r");

	if (f1 != NULL)
	{
		int read1 = fread(&newStu, sizeof(struct Student), 1, f1);
		fclose(f1);
	}
	else
	{
		printf("ERROR");
	}



	return 0;
}