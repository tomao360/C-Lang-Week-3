#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)

int main_3()
{
	time_t i = time(); //�������� ���� ����� �� ����� ������ ����� �� ���� (�����) �-1.1.1970 �� ���� ������� //called unix time
	srand(i); //(������� ������ ���� �������� �� ����� ���� ��� ����� ������  �� ����� ����� ������ �� ������� �� ����� ���� ����� (���� ���� ����� �� - 1.1.1970 �� ���� �������
	
	int sum = 0;
	for (int i = 0; i < 100000; i++)
	{
		int a = rand(); //���� ���� ������ 
		sum = sum + a;
	}

	printf("The average is: %d", sum / 100000);
	
	//����� ���� ����� ��� 1-9
	sum = sum % 10;
	printf("\nReandom number between 1-9: %d", sum);

	return 0;
}