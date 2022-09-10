#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)

int main_3()
{
	time_t i = time(); //הפונקציה פונה לשעון של המחשב ומבקשת להביא את השעה (שניות) מ-1.1.1970 עד לשעה הנוכחית //called unix time
	srand(i); //(פונקציה שמקבלת מספר והעירבוב של הטבלה יהיה לפי המספר שקיבלה  או מקבלת פרמטר והכמות של העירבוב של הטבלה יהיה אקראי (נקבל מספר אקראי מה - 1.1.1970 עד השעה הנוכחית
	
	int sum = 0;
	for (int i = 0; i < 100000; i++)
	{
		int a = rand(); //מביא מספר מהטבלה 
		sum = sum + a;
	}

	printf("The average is: %d", sum / 100000);
	
	//הגרלת מספר אקראי בין 1-9
	sum = sum % 10;
	printf("\nReandom number between 1-9: %d", sum);

	return 0;
}