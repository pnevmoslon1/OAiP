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
	if (c >= '�' && c <= '�')
		new_c = '�' + (c - '�');
	if (c >= '�' && c <= '�')
		new_c = '�' + (c - '�');
	if (c == '�')
		new_c = '�';
	
	return new_c;
}


void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char name[12], s[80];
	//printf("������� ���: "); // ������� 1
	//fgets(name, 11, stdin);
	//printf("����������� ����, %s\n", name);

	//printf("������� ������ = "); // ������� 2
	//int ch = getchar();

	//for (int c = ch; c <= ch + 19; c++) {
	//	printf("'%c' (%d)\n", c, c);
	//}
	//printf("\n\n\n");


	//printf("������� ������ = "); // ������� 3

	//int ch = getchar();

	//for (int c = ch; c > ch - 30; c--) {
	//	printf("'%c' (%d)\n", c, c);
	//}
	//printf("\n\n\n");

	printf("������� ������: "); // ������� 5
	fgets(s, 79, stdin);
	printf("������ s = %s", s);

	int cnt = 0;
	for (int i = 0; i < strlen(s); i++) {
		if (s[i] == ' ')
			cnt++;
	}
	printf("� ��� %d ��������\n", cnt);



	printf("\n������� ������: "); // ������� 6
	fgets(s, 79, stdin);
	printf("������ s = %s", s);


	for (int i = 0; i < strlen(s); i++) {
		if (s[i] == ' ')
			s[i] = '#';
	}
	printf("%s\n", s);

	printf("������� ������: "); // ������� 6.1
	fgets(s, 79, stdin);
	printf("������ s = %s", s);


	for (int i = 0; i < strlen(s); i++) {
		if (isdigit(s[i]) != 0)
			s[i] = '$';
	}
	printf("%s\n", s);



	printf("������� ������: ");//������� 7.1
	fgets(s, 79, stdin);
	printf("s =%s", s);

	for (int i = 0; s[i] != '\0'; i++)
		s[i] = toupper(s[i]);
	printf("������������ ������ = %s", s);


	printf("������� ������: ");//������� 7.2
	fgets(s, 79, stdin);
	printf("s =%s", s);

	for (int i = 0; s[i] != '\0'; i++)
		s[i] = toupperAll(s[i]);
	printf("������������ ������ = %s", s);


}

