#include <stdio.h>
#include <Windows.h>


void aboutMe() {

	printf("Валиуллин\n");
	printf("Ринат\n");
	printf("Айратович\n");
	printf("\n");
	printf("Группа: ПИбд-13\n");
	printf("Дата 19.10.2023\n");
	printf("Предмет Основы программирования\n");
	printf("Лабараторная работа №8\n");
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	aboutMe();

	return 0;
}