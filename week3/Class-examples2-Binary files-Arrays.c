#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)

int main_1_0_2()
{
	//Write array into file
	int arr[5] = { 23, 44, 56, 100, 1009 }; 

	//arr = &arr[0] -> arr = במיקום הראשון arr שווה לכתובת של 
	//מערך הוא פויינטר למקום בזיכרון

	FILE* f = fopen("array.dat", "w");
	if (f != NULL)
	{
		
		int written = fwrite(arr, sizeof(int), 5, f); 
		//5 because of the 5 cells in the array. We need 5 slices.
		//sizeof() -> גודל של פרוסה אחת
		//5 -> כמה פרוסות אני צריכה

		fclose(f);
	}
	else
	{
		printf("ERROR");
	}

	//Read array from file when you know the full size
	f = fopen("array.dat", "r");
	if (f != NULL)
	{
		int read = fread(arr, sizeof(int), 5, f);
		fclose(f);
	}
	else
	{
		printf("ERROR");
	}


	//Read from file when you dont know the array size
	f = fopen("array.dat", "r");
	if (f != NULL)
	{
		int item; //קולט כל פעם לתוך המשתנה חבילה אחת
		int read = 1;
		while (read != 0)
		{
			read = fread(&item, sizeof(int), 1, f);
			printf("%d\n", item);
		}

		fclose(f);
	}
	else
	{
		printf("ERROR");
	}
	//דרך מקוצרת לכתיבה הזאת
	f = fopen("array.dat", "r");
	if (f != NULL)
	{
		int item; //קולט כל פעם לתוך המשתנה חבילה אחת
		int read;
		while ((read = fread(&item, sizeof(int), 1, f)) > 0)
		{
			printf("%d\n", item);
		}

		fclose(f);
	}
	else
	{
		printf("ERROR");
	}


	//דרך נוספת לכתיבה

	//0 -> FALSE 
	//!=0 -> TRUE
	if (f) //if (f != NULL) -> אותו הדבר
	{
		//כל הקוד המטה יחזיר אמת במידה והוא הצליח לקרוא את הקובץ, במידה והוא לא הצליח הוא יחזיר שקר
		int item;
		//fread returns 0 when any byte was read
		while (fread(&item, sizeof(int), 1, f))
		{
			printf("%d", item);
		}

		fclose(f);
	}
	else
	{
		printf("ERROR");
	}
	
	
	return 0;
}