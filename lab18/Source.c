#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>

int arr[10];

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int a, b, c, d, e;
	int p, s, n;
	FILE* fin;
	FILE* fout;
	//printf("������ 1\n");
	//scanf("%d%d%d", &a, &b, &c);
	//printf("�����: %d, %d, %d\n", a, b, c);
	//// ���������
	//p = a * b * c;
	//printf("p =  %d\n", p);



	printf("������ 2\n");

	fin = fopen("in2.txt", "rt");
	if (fin == NULL) {
		printf("������� ���� �� ������");
		return;
	}
	fscanf(fin, "%d%d%d", &a, &b, &c);
	fclose(fin);

		printf("�����: %d, %d, %d\n", a, b, c);

	// ���������
	p = a * b * c;

	// ����������� ������
	printf("p =  %d\n", p);


	// ������ � �������� ����

	// �������� ����
	fout = fopen("out2.txt", "wt");
	if (fout == NULL) {
		printf("�������� ���� �� ��������");
		return;
	}
	fprintf(fout, "%d", &n);
	fclose(fout);

	/*
	printf("������ 3\n");
	scanf_s("%d%d%d%d%d", &a, &b, &c, &d, &e);
	printf("����� %d %d %d %d %d\n", a, b, c, d, e);
	s = a + b + c + d + e;
	printf("����� = %d\n", s);
	*/

	printf("\n������ 4\n");
	fin = fopen("in4.txt", "rt");
	if (fin == NULL) {
		printf("������� ���� �� ������");
		return;
	}
	fscanf(fin, "%d%d%d%d%d", &a, &b, &c, &d, &e);
	fclose(fin);
	printf("����� %d %d %d %d %d\n", a, b, c, d, e);
	s = a + b + c + d + e;
	printf("����� = %d\n", s);

	fout = fopen("out4.txt", "wt");
	if (fout == NULL) {
		printf("�������� ���� �� ������");
		return;
	}
	fprintf(fout, "%d", s);
	fclose(fout);

	
	printf("\n������ 5\n");
	fin = fopen("in5.txt", "rt");
	if (fin == NULL) {
		printf("������� ���� �� ������");
		return;
	}
	fscanf(fin, "%d", &n);
	int sum = 0;
	for (int i = 0; i < n; i++) 
	{
		fscanf(fin, "%d", &arr[i]);
		
	}
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	fclose(fin);
	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
	}

	float srAr = (float)sum / n; 
	printf("\n������� �������������� = %.1f\n", srAr);

	for (int i = 0; i < n; i++)
	{
		if (arr[i] > srAr)
		{
			arr[i] *= 10;
		}
	}

	printf("������������ ������: ");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}

	fout = fopen("out5.txt", "wt");
	if (fout == NULL) {
		printf("�������� ���� �� ������");
		return;
	}
	for (int i = 0; i < n; i++)
	{
		fprintf(fout, "%d ", arr[i]);
	}
	fclose(fout);


printf("\n������ 6\n");
fin = fopen("in6.txt", "rt");
if (fin == NULL) {
	printf("������� ���� �� ������");
	return;
}
fscanf(fin, "%d", &n);
sum = 0;
for (int i = 0; i < n; i++)
{
	fscanf(fin, "%d", &arr[i]);

}
for (int i = 0; i < n; i++)
{
	printf("%d ", arr[i]);
}
fclose(fin);
for (int i = 0; i < n; i++)
{
	sum += arr[i];
}

srAr = (float)sum / n;
printf("\n������� �������������� = %.1f\n", srAr);

for (int i = 0; i < n; i++)
{
	if (arr[i] < srAr && arr[i] % 2 == 0)
	{
		arr[i] /= 2;
	}
}

printf("������������ ������: ");
for (int i = 0; i < n; i++)
{
	printf("%d ", arr[i]);
}

fout = fopen("out6.txt", "wt");
if (fout == NULL) {
	printf("�������� ���� �� ������");
	return;
}
for (int i = 0; i < n; i++)
{
	fprintf(fout, "%d ", arr[i]);
}
fclose(fout);
}


