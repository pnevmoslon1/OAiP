#include <stdio.h>
#include <Windows.h>


void aboutMe() {

	printf("���������\n");
	printf("�����\n");
	printf("���������\n");
	printf("\n");
	printf("������: ����-13\n");
	printf("���� 19.10.2023\n");
	printf("������� ������ ����������������\n");
	printf("������������ ������ �8\n");
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	aboutMe();

	return 0;
}