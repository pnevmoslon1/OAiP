#include <stdio.h>
#include<Windows.h>


void task1() 
{
	int n, m, i = 1, j = 1;
	printf("������� m � n\n");
	scanf_s("%d%d", &n, &m);

	while (i <= n)
	{
		j = 1;
		while (j <= m) 
		{
			printf("%d%d ", i, j);
			j++;
		}
		printf("\n");
		i++;
	}
}

void task2() 
{
	int i = 1, j = 1;
	while (i <= 10)
	{
		j = 1;
		while (j <= 10)
		{
			printf("%d ", i * j);
			j++;
		}
		printf("\n");
		i++;
	}
}




int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	printf("1: ������� 1\n");
	printf("2: T������ ��������\n");
	printf("4: �������\n");

	int n;
	scanf_s("%d", &n);
	switch (n)
	{
	case 1:
		task1();
		break;
	case 2:
		task2();
		break;
	}


	return 0;
}