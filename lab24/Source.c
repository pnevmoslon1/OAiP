#include <stdio.h>
#include <Windows.h>

void f1(int n);
void G3(int n);

long fuct2(int n) 
{
	if (n == 0) {
		return 1;
	}
	long res = fuct2(n - 1) * n;
	return res;
}

void recn1(int n) {
	printf(" %d", n);
	if (n > 1) {
		recn1(n - 2);
	}
}


void rec1n(int n) {
	if (n > 1) {
		rec1n(n - 2);
	}
	printf(" %d", n);
}


void recn1n(int n) {
	printf(" %d", n);
	if (n > 1) {
		recn1n(n - 2);
	}
	printf(" %d", n);
}



void recEGE1(int n) {
	if (n >= 1) {
		printf(" %d", n);
		recEGE1(n - 1);
		recEGE1(n - 1);
	}
}



void f2(int n) {
	printf("%d\n", n);
	if (n < 5) {
		f1(n + 1);
		f1(n + 3);
	}
}



void f1(int n) {
	if (n > 2) {
		printf("%d\n", n);
		f1(n - 3);
		f1(n - 4);
	}
}


void F3(int n) {
	if (n > 0) {
		G3(n - 1);
	}
}

void G3(int n) {
	printf("*");
	if (n > 1) {
		F3(n - 3);
	}
}



void main() 
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int n, c;

	do
	{
		printf("выберите номер задания ");
		scanf_s("%d", &c);

		switch (c)
		{
		case 1:
		{
			scanf_s("%d", &n); // задание 1
			printf("%ld", fuct2(n));
		}
		break;

		case 2:
		{
			printf("Вызов функции: 	f1(11)\nФормируемый вывод : ");
			recn1(11);
			printf("\nВызов функции: 	f2(11)\nФормируемый вывод : ");
			rec1n(11);
			printf("\nВызов функции: 	f3(11)\nФормируемый вывод : ");
			recn1n(11);
		}
		break;

		case 3:
		{
			recn1(7);
			printf(" rec1 FINISH\n");
			rec1n(7);
			printf(" rec2 FINISH\n");
			recn1n(7);
			printf(" rec3 FINISH\n");
		}
		break;

		case 4:
		{
			recEGE1(3);
		}
		break;

		case 5:
		{
			f1(10);
		}
		break;

		case 6:
		{
			f2(1);
		}
		break;

		case 7:
		{
			n = 11;
			F3(n);
			printf("\n");
		}
		break;
		default:
			break;
		}

		printf("\n\n");
	} while (c != 0);

	



}