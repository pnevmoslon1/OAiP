#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>



int a[100][100];
int n = 3, m = 4;
int minIndex;
void printElements()
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%3d ", a[i][j]);
		}
		printf("\n");
	}
}


void fillIx10() {
	printf("!!!! fillIx10() !!!!\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			a[i][j] = i * 10 + j;
		}
	}
}


void fillZero() {
	printf("!!!! fillZero() !!!!\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			a[i][j] = 0;
		}
	}
}



void keyboardInput()
{
	printf("n = ");
	scanf_s("%d", &n);
	printf("input %d values: ", n);
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &a[i]);
	}
}


void randFill0_9() {
	printf("!!!! randFill0_9() !!!!\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			a[i][j] = rand() % 10;
		}
	}
}


void save() {
	// �������� ����
	FILE* fout = fopen("save.txt", "wt");
	if (fout == NULL) {
		printf("�������� ���� �� ��������");
		return;
	}

	fprintf(fout, "%d ", n);
	fprintf(fout, "%d\n", m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			fprintf(fout, "%d ", a[i][j]);
		}
		fprintf(fout, "\n");
	}

	fclose(fout);
}


void oddx10() {
	printf("!!!! randFill0_9() !!!!\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] % 2 != 0)
			{
				a[i][j] *= 10;
			}
		}
	}
}


void del10() {
	printf("!!!! randFill0_9() !!!!\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] % 10 == 0)
			{
				a[i][j] /= 10;
			}
		}
	}
}


void load() {

	FILE* fin = fopen("save.txt", "rt");
	if (fin == NULL) {
		printf("������� ���� �� ������");
		return;
	}

	fscanf(fin, "%d", &n);
	fscanf(fin, "%d", &m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			fscanf(fin, "%d", &a[i][j]);
		}
	}

	fclose(fin);
}


void deleteRow(int delRow) {
	printf("!!!! deleteRow(%d) !!!!\n", delRow);
	for (int i = delRow; i < n - 1; i++) {
		for (int j = 0; j < m; j++) {
			a[i][j] = a[i + 1][j];
		}
	}
	n--;
}


void jx2() {
	int s;
	scanf_s("%d", &s);
	s--;
	for (int i = 0; i < n; i++) {
		for (int j = m; j > s; j--) {
			a[i][j] = a[i][j - 1];
		}
	}
	m++;
}


void input()
{
	printf("n, m = ");
	scanf_s("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf_s("%d", &a[i][j]);
		}
	}
}


void task9()
{
	int mn = a[0][0], mi = 0, mj = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] < mn)
			{
				mi = i;
				mj = j;
			}
		}
	}

	for (int i = mi +1; i < n; i++)
	{
		for (int j = 0; j < mj; j++)
		{
			if (a[i][j] % 2 != 0)
			{
				a[i][j] = 0;
			}
		}
	}

}


void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int item, g;
	do {
		printf("\n");
		printf("------------------------------\n");
		printf("���������� �������:\n");
		printElements();
		printf("�������� ������ ��� ��������:\n");
		printf("1: ��������� ���������� i * 10 + j\n");
		printf("2: ��������� ������\n");
		printf("3: ��������� ���������� ����������\n");
		printf("4: ��� �������� ��������� � 10 ���\n");
		printf("5: ��� ������� 10 ��������� � 10 ���\n");
		printf("6: ������ ����\n");
		printf("7: ������� ������\n");
		printf("8: �������������� �������\n");
		printf("9: ������ �������� ����� ����� �� ������������ �� 0(4�)\n");
		printf("20: ��������� ������ � ������\n");
		printf("21: �������� ������ �� �������\n");
		printf("\n");
		printf("-1: ����� �� ���������\n");
		printf("��������� �������� >>>>>> ");

		scanf_s("%d", &item);
		switch (item) {
		case 1:
			fillIx10();
			break;

		case 2:
			fillZero();
			break;

		case 3:
		{
			randFill0_9();
		}
		break;
		case 4:
		{
			oddx10();
		}
		break;
		case 5:
		{
			del10();
		}
		break;

		case 6:
		{
			input();
		}
		break;

		case 7:
		{
			scanf_s("%d", &g);
			deleteRow(g);
		}
		break;
		case 8:
		{
			jx2();
		}
		break;

		case 9:
		{
			task9();
		}
		break;

		case 20:
		{
			save();
		}
		break;

		case 21:
		{
			load();
		}
		break;
		}

	} while (item != -1);
}