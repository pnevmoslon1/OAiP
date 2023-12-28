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
	printf("ЛР23 Задача 1\n");
	FILE* fin = fopen("text1.txt", "rt");
	if (fin == NULL) 
	{
		printf("Входной файл не найден");
		return;
	}

	// Выходной файл
	FILE* fout;
	fout = fopen("out1.txt", "wt");
	if (fout == NULL) 
	{
		printf("Выходной файл не создался");
		return;
	}
	// в цикле для всех строк
	while (!feof(fin)) 
	{
		// загрузить строку
		if (fgets(s, MAX_LEN - 1, fin) != NULL) 
		{
			// обработать загруженную строку
			for (int i = 0; s[i] != '\0'; i++) 
			{

				if (s[i] == '\t') // Если прочитан пробел
					s[i] = '%'; // Заменяем его на '%’

			}
			// сохранить строку в выходной файл
			fprintf(fout, "%s", s);
			printf(">>%s<<\n", s);
		}
	}
	// закрыли файлы
	fclose(fin);
	fclose(fout);

	printf("ЛР23 Задача 1 FINISH\n");
}


void task2() 
{
	FILE* fin = fopen("text2.txt", "rt");
	if (fin == NULL) {
		printf("Входной файл не найден");
		return;
	}

	// Выходной файл
	FILE* fout;
	fout = fopen("out2.txt", "wt");
	if (fout == NULL) {
		printf("Выходной файл не создался");
		return;
	} 
	// в цикле для всех строк
	while (!feof(fin)) {
		// загрузить строку
		if (fgets(s, MAX_LEN - 1, fin) != NULL) {
			// обработать загруженную строку
			for (int i = 0; s[i] != '\0'; i++) {
				s[i] = toupper(s[i]);

			}
			// сохранить строку в выходной файл
			fprintf(fout, "%s", s);

		}
	}
	// закрыли файлы
	fclose(fin);
	fclose(fout);

	printf("ЛР23 Задача 2 FINISH\n");
}


void task3()
{

	FILE* fin = fopen("text3.txt", "rt");
	if (fin == NULL) {
		printf("Входной файл не найден");
		return;
	}

	// Выходной файл
	FILE* fout;
	fout = fopen("out3.txt", "wt");
	if (fout == NULL) {
		printf("Выходной файл не создался");
		return;
	}
	// в цикле для всех строк
	while (!feof(fin)) {
		// загрузить строку
		if (fgets(s, MAX_LEN - 1, fin) != NULL) {
			// обработать загруженную строку
			for (int i = 0; s[i] != '\0'; i++) {
				if (isalpha != 0)
				{
					s[strlen(s) - 1] = '#';
					s[strlen(s)] = '\n';
					break;
				}

			}
			// сохранить строку в выходной файл
			fprintf(fout, "%s", s);
			printf(fout, "%s", s);

		}
	}
	// закрыли файлы
	fclose(fin);
	fclose(fout);

	printf("ЛР23 Задача 3 FINISH\n");
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

	// ANSI кодировка!!!
	if (ch >= 192 && ch <= 223)
		return 1;
	if (ch >= 224 && ch <= 255)
		return 1;

	/*
		if (ch >= 'А' && ch <= 'Я') return 1;
		if (ch >= 'а' && ch <= 'п') return 1;
		if (ch >= 'р' && ch <= 'я')return 1;
		if (ch == 'ё' ) return 1;
		if (ch == 'Ё') return 1;*/

	return 0;
}



void task4()
{
	

	char filename[] = "text4.txt";

	
	printf("BEGIN!!!\n");

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// открываем файл с текстом
	FILE* fin = fopen(filename, "rt");
	if (fin == NULL) {
		// если файл не смогли открыть - сообщаем об этом
		printf("File %s doesn't opened!\n", filename);
		return;
	}
	char token[MAX_LEN];
	int res;

	// пока не конец файла
	while (!feof(fin)) {
		// пока есть разделитель - берем его
		while (getNextDelim(fin, token)) {
			// выводим разделитель в консоль
			printf("<DELIM>%s</DELIM>\n", token);
		}
		// если есть слово - берем его
		if (getNextWord(fin, token, MAX_LEN)) {
			// выводим слово в консоль
			printf("<WORD>%s</WORD>\n", token);
		}
	}

	// Закрываем файл с текстом
	fclose(fin);
	printf("END!!!\n");

	


	// Возвращает 1 - если  из файла прочитан разделитель.
	// В этом случае в token возвращается строка, содержащая 
	// этот разделитель.
	// Если в файле был не разделитель - возвращает 0.
	// В этом случае состояние token неопределено.
	

}


void task6()
{

	FILE* fin = fopen("text6.txt", "rt");
	if (fin == NULL) {
		printf("Входной файл не найден");
		return;
	}

	// Выходной файл
	FILE* fout;
	fout = fopen("out6.txt", "wt");
	if (fout == NULL) {
		printf("Выходной файл не создался");
		return;
	}
	// в цикле для всех строк
	while (!feof(fin)) {
		// загрузить строку
		if (fgets(s, MAX_LEN - 1, fin) != NULL) {
			// обработать загруженную строку
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
			// сохранить строку в выходной файл
			fprintf(fout, "%s", s);
			printf(fout, "%s", s);

		}
	}
	// закрыли файлы
	fclose(fin);
	fclose(fout);

	printf("ЛР23 Задача 6 FINISH\n");
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
		printf("Входной файл не найден");
		return;
	}

	// Выходной файл
	FILE* fout;
	fout = fopen("out7.txt", "wt");
	if (fout == NULL) {
		printf("Выходной файл не создался");
		return;
	}
	// в цикле для всех строк
	while (!feof(fin)) {
		// загрузить строку
		if (fgets(s, MAX_LEN - 1, fin) != NULL) {
			// обработать загруженную строку
			int kk = 0;
			for (int i = 0; s[i] != '\0'; i++) {
				if (islowerGl(s[i]) != 0)
				{
					s[i] = '@';
				}

			}
			
			// сохранить строку в выходной файл
			fprintf(fout, "%s", s);
			printf(fout, "%s", s);

		}
	}
	// закрыли файлы
	fclose(fin);
	fclose(fout);

	printf("ЛР23 Задача 7(4) FINISH\n");
}


void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int c = 1;
	while (c != 0)
	{
		printf("выберите задание от 1 до 7, кроме 5, оно сохранено как отдельный проект в этой же папке\n");
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
