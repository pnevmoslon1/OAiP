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
		printf("Через %d лет: %.1f \n", i, n);
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
		printf("Выберите нужную вам операцию:\n");
		printf("1: Вывести числа от 1 до 10\n");
		printf("2: Вывести числа от 10 до 1\n");
		printf("3: Вывести 5 первых нечетных чисел начиная с 1\n");
		printf("11: Вывести числа от 100 до 10 с шагом 10\n");
		printf("12: Вывести числа от 1000 до 100 с шагом 100\n");
		printf("13: Вывести состояние счета\n");
		printf("20: От 1000 до 0 с шагом N\n");
		printf("\n");
		printf("0: Выйти из программы\n");
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
			
			printf("Кол-во денег = ");
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