#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <Windows.h>
#include <ctype.h>


int isdigitMy(char c) {
	if ((c >= '0') && (c <= '9'))
		return 1;
	return 0;
}


int toupperAll(int c) {
	int new_c = c;
	if (c >= 'a' && c <= 'z')
		new_c = 'A' + (c - 'a');
	if (c >= 'а' && c <= 'п')
		new_c = 'А' + (c - 'а');
	if (c >= 'р' && c <= 'я')
		new_c = 'Р' + (c - 'р');
	if (c == 'ё')
		new_c = 'Ё';
	
	return new_c;
}


void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char name[12], s[80];
	//printf("Введите имя: "); // задание 1
	//fgets(name, 11, stdin);
	//printf("Приветствую тебя, %s\n", name);

	//printf("Введите символ = "); // задание 2
	//int ch = getchar();

	//for (int c = ch; c <= ch + 19; c++) {
	//	printf("'%c' (%d)\n", c, c);
	//}
	//printf("\n\n\n");


	//printf("Введите символ = "); // задание 3

	//int ch = getchar();

	//for (int c = ch; c > ch - 30; c--) {
	//	printf("'%c' (%d)\n", c, c);
	//}
	//printf("\n\n\n");

	printf("Введите строку: "); // задагие 5
	fgets(s, 79, stdin);
	printf("строка s = %s", s);

	int cnt = 0;
	for (int i = 0; i < strlen(s); i++) {
		if (s[i] == ' ')
			cnt++;
	}
	printf("в ней %d пробелов\n", cnt);



	printf("\nВведите строку: "); // задагие 6
	fgets(s, 79, stdin);
	printf("строка s = %s", s);


	for (int i = 0; i < strlen(s); i++) {
		if (s[i] == ' ')
			s[i] = '#';
	}
	printf("%s\n", s);

	printf("Введите строку: "); // задагие 6.1
	fgets(s, 79, stdin);
	printf("строка s = %s", s);


	for (int i = 0; i < strlen(s); i++) {
		if (isdigit(s[i]) != 0)
			s[i] = '$';
	}
	printf("%s\n", s);



	printf("Введите строку: ");//задагие 7.1
	fgets(s, 79, stdin);
	printf("s =%s", s);

	for (int i = 0; s[i] != '\0'; i++)
		s[i] = toupper(s[i]);
	printf("обработанная строка = %s", s);


	printf("Введите строку: ");//задагие 7.2
	fgets(s, 79, stdin);
	printf("s =%s", s);

	for (int i = 0; s[i] != '\0'; i++)
		s[i] = toupperAll(s[i]);
	printf("обработанная строка = %s", s);


}

