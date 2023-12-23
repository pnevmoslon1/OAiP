#include <stdio.h>
#include<Windows.h>

void print1_10() 
{
	int i = 1;
	while (i <= 10)
	{
		printf("%d ", i);
		i++;
	}
}

void print10_1()
{
	int i = 0;
	while (i < 10)
	{
		printf("%d ", 10 - i);
		i++;
	}
}

void print5Odds()
{
	int i = 1;
	while (i < 10)
	{
		printf("%d ", i);
		i+=2;
	}
}
void print100_10()
{
	int i = 0;
	while (i < 10)
	{
		printf("%d ", (10 - i) * 10);
		i++;
	}
}
void print1000_100()
{
	int i = 0;
	while (i < 10)
	{
		printf("%d ", (10 - i) * 100);
		i++;
	}
}
void printCount(float n, float p)
{
	
	p = 1 + p / 100;
	int i = 0;
	while (i <= 10)
	{
		printf("����� %d ���: %.1f \n", i, n);
		n *= p;
		i++;
	}
}
void print1000_0()
{
	int n, i = 1000;
	scanf_s("%d", &n);
	while (i >= 0)
	{
		printf("%d ", i);
		i-=n;
	}
}
int main() 
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n;
	float s, p;
	do {
		s = 0;
		printf("\n");
		printf("\n");
		printf("�������� ������ ��� ��������:\n");
		printf("1: ������� ����� �� 1 �� 10\n");
		printf("2: ������� ����� �� 10 �� 1\n");
		printf("3: ������� 5 ������ �������� ����� ������� � 1\n");
		printf("11: ������� ����� �� 100 �� 10 � ����� 10\n");
		printf("12: ������� ����� �� 1000 �� 100 � ����� 100\n");
		printf("13: ������� ��������� �����\n");
		printf("20: �� 1000 �� 0 � ����� N\n");
		printf("\n");
		printf("0: ����� �� ���������\n");
		scanf_s("%d", &n);
		switch (n) 
		{
		case 1:
			print1_10();
			break;
		case 2:
			print10_1();
			break;
		case 3:
			print5Odds();
			break;
		case 11:
			print100_10();
			break;
		case 12:
			print1000_100();
			break;
		case 13:
			
			printf("���-�� ����� = ");
			scanf_s("%f", &s);
			printf("%% = ");
			scanf_s("%f", &p);
			printCount(s , p);
			break;
		case 20:
			print1000_0();
			break;
		}

	} while (n != 0);


	return 0;
}