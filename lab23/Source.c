#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <string.h>

#define MAX_LEN 100
char s[MAX_LEN];

int getNextDelim(FILE * fp, char token[]);
int getNextWord(FILE * fp, char token[], int maxLen);
int isalpha_my(unsigned char ch);

void task1() 
{	
	printf("��23 ������ 1\n");
	FILE* fin = fopen("text1.txt", "rt");
	if (fin == NULL) 
	{
		printf("������� ���� �� ������");
		return;
	}

	// �������� ����
	FILE* fout;
	fout = fopen("out1.txt", "wt");
	if (fout == NULL) 
	{
		printf("�������� ���� �� ��������");
		return;
	}
	// � ����� ��� ���� �����
	while (!feof(fin)) 
	{
		// ��������� ������
		if (fgets(s, MAX_LEN - 1, fin) != NULL) 
		{
			// ���������� ����������� ������
			for (int i = 0; s[i] != '\0'; i++) 
			{

				if (s[i] == '\t') // ���� �������� ������
					s[i] = '%'; // �������� ��� �� '%�

			}
			// ��������� ������ � �������� ����
			fprintf(fout, "%s", s);
			printf(">>%s<<\n", s);
		}
	}
	// ������� �����
	fclose(fin);
	fclose(fout);

	printf("��23 ������ 1 FINISH\n");
}


void task2() 
{
	FILE* fin = fopen("text2.txt", "rt");
	if (fin == NULL) {
		printf("������� ���� �� ������");
		return;
	}

	// �������� ����
	FILE* fout;
	fout = fopen("out2.txt", "wt");
	if (fout == NULL) {
		printf("�������� ���� �� ��������");
		return;
	} 
	// � ����� ��� ���� �����
	while (!feof(fin)) {
		// ��������� ������
		if (fgets(s, MAX_LEN - 1, fin) != NULL) {
			// ���������� ����������� ������
			for (int i = 0; s[i] != '\0'; i++) {
				s[i] = toupper(s[i]);

			}
			// ��������� ������ � �������� ����
			fprintf(fout, "%s", s);

		}
	}
	// ������� �����
	fclose(fin);
	fclose(fout);

	printf("��23 ������ 2 FINISH\n");
}


void task3()
{

	FILE* fin = fopen("text3.txt", "rt");
	if (fin == NULL) {
		printf("������� ���� �� ������");
		return;
	}

	// �������� ����
	FILE* fout;
	fout = fopen("out3.txt", "wt");
	if (fout == NULL) {
		printf("�������� ���� �� ��������");
		return;
	}
	// � ����� ��� ���� �����
	while (!feof(fin)) {
		// ��������� ������
		if (fgets(s, MAX_LEN - 1, fin) != NULL) {
			// ���������� ����������� ������
			for (int i = 0; s[i] != '\0'; i++) {
				if (isalpha != 0)
				{
					s[strlen(s) - 1] = '#';
					s[strlen(s)] = '\n';
					break;
				}

			}
			// ��������� ������ � �������� ����
			fprintf(fout, "%s", s);
			printf(fout, "%s", s);

		}
	}
	// ������� �����
	fclose(fin);
	fclose(fout);

	printf("��23 ������ 3 FINISH\n");
}



int getNextWord(FILE* fp, char token[], int maxLen)
{
	int i = 0;
	int ch;
	while (((ch = getc(fp)) != EOF) && (i < maxLen - 1)) {
		if (!isalpha_my((unsigned char)(ch))) {
			break;
		}
		token[i++] = ch;
	}
	ungetc(ch, fp);
	token[i] = '\0';
	if (i == 0)
		return 0;
	return 1;
}


int getNextDelim(FILE* fp, char token[])
{
	int ch = getc(fp);
	if (ch == EOF) {
		return 0;
	}
	if (isalpha_my((unsigned char)ch)) {
		ungetc(ch, fp);
		return 0;
	}
	token[0] = (unsigned char)ch;
	token[1] = '\0';
		return 1;
}


int isalpha_my(unsigned char ch) {
	if (isalpha(ch))
		return 1;

	// ANSI ���������!!!
	if (ch >= 192 && ch <= 223)
		return 1;
	if (ch >= 224 && ch <= 255)
		return 1;

	/*
		if (ch >= '�' && ch <= '�') return 1;
		if (ch >= '�' && ch <= '�') return 1;
		if (ch >= '�' && ch <= '�')return 1;
		if (ch == '�' ) return 1;
		if (ch == '�') return 1;*/

	return 0;
}



void task4()
{
	

	char filename[] = "text4.txt";

	
	printf("BEGIN!!!\n");

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// ��������� ���� � �������
	FILE* fin = fopen(filename, "rt");
	if (fin == NULL) {
		// ���� ���� �� ������ ������� - �������� �� ����
		printf("File %s doesn't opened!\n", filename);
		return;
	}
	char token[MAX_LEN];
	int res;

	// ���� �� ����� �����
	while (!feof(fin)) {
		// ���� ���� ����������� - ����� ���
		while (getNextDelim(fin, token)) {
			// ������� ����������� � �������
			printf("<DELIM>%s</DELIM>\n", token);
		}
		// ���� ���� ����� - ����� ���
		if (getNextWord(fin, token, MAX_LEN)) {
			// ������� ����� � �������
			printf("<WORD>%s</WORD>\n", token);
		}
	}

	// ��������� ���� � �������
	fclose(fin);
	printf("END!!!\n");

	


	// ���������� 1 - ����  �� ����� �������� �����������.
	// � ���� ������ � token ������������ ������, ���������� 
	// ���� �����������.
	// ���� � ����� ��� �� ����������� - ���������� 0.
	// � ���� ������ ��������� token ������������.
	

}


void task6()
{

	FILE* fin = fopen("text6.txt", "rt");
	if (fin == NULL) {
		printf("������� ���� �� ������");
		return;
	}

	// �������� ����
	FILE* fout;
	fout = fopen("out6.txt", "wt");
	if (fout == NULL) {
		printf("�������� ���� �� ��������");
		return;
	}
	// � ����� ��� ���� �����
	while (!feof(fin)) {
		// ��������� ������
		if (fgets(s, MAX_LEN - 1, fin) != NULL) {
			// ���������� ����������� ������
			int kk = 0;
			for (int i = 0; s[i] != '\0'; i++) {
				if (s[i] == ';')
				{
					kk++;
				}

			}
			int h =strlen(s) - 1;
			for (int i = 0; i < kk; i++) 
			{
				s[h + i] = 'K';
				s[h + kk] = '\n';
			}
			// ��������� ������ � �������� ����
			fprintf(fout, "%s", s);
			printf(fout, "%s", s);

		}
	}
	// ������� �����
	fclose(fin);
	fclose(fout);

	printf("��23 ������ 6 FINISH\n");
}


int islowerGl(char c) 
{

	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y')
	{
		return 1;
		}
	return 0;
}


void task7()
{

	FILE* fin = fopen("text7.txt", "rt");
	if (fin == NULL) {
		printf("������� ���� �� ������");
		return;
	}

	// �������� ����
	FILE* fout;
	fout = fopen("out7.txt", "wt");
	if (fout == NULL) {
		printf("�������� ���� �� ��������");
		return;
	}
	// � ����� ��� ���� �����
	while (!feof(fin)) {
		// ��������� ������
		if (fgets(s, MAX_LEN - 1, fin) != NULL) {
			// ���������� ����������� ������
			int kk = 0;
			for (int i = 0; s[i] != '\0'; i++) {
				if (islowerGl(s[i]) != 0)
				{
					s[i] = '@';
				}

			}
			
			// ��������� ������ � �������� ����
			fprintf(fout, "%s", s);
			printf(fout, "%s", s);

		}
	}
	// ������� �����
	fclose(fin);
	fclose(fout);

	printf("��23 ������ 7(4) FINISH\n");
}


void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int c = 1;
	while (c != 0)
	{
		printf("�������� ������� �� 1 �� 7, ����� 5, ��� ��������� ��� ��������� ������ � ���� �� �����\n");
		scanf_s("%d", &c);
		switch (c)
		{
		case 1:
		{
			task1();
		}
		break;
		
		case 2:
		{
			task2();
		}
		break;
		
		case 3:
		{
			task3();
		}
		break;
		
		case 4:
		{
			task4();
		}
		break;
		
		
		case 6:
		{
			task6();
		}
		break;
		
		case 7:
		{
			task7;
		}
		break;

		default:
			break;
		}
	}
	
	
}
