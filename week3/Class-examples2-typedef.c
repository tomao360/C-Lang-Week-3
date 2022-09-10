#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)

int main_3_0_1()
{
	typedef char LastName[200]; //כדי ליצור טיפוסים typedef - משתמשים ב 
	typedef unsigned char CarCount;

	struct Family
	{
		LastName name;
		int members;
		CarCount cars;
		char address[100];
	};

	LastName userInsertName;
	char userInsertAddress[100];

	//struct מטיפוס typedef יצירת  
	typedef struct 
	{
		LastName name;
		int members;
		CarCount cars;
		char address[100];
	} Family_S; //the name of the struct

	Family_S oneFamily;
	oneFamily.cars = 12;



	return 0;
}