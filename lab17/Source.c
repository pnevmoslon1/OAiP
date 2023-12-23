#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>


#define NUM_ELEMENTS 10

int arr[NUM_ELEMENTS];
int n = 0;
int minIndex;
void printElements()
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}


void keyboardInput()
{
	printf("n = ");
	scanf_s("%d", &n);
	printf("input %d values: ", n);
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &arr[i]);
	}
}


void oddsX10()
{
	for (int i = 0; i < n; i++)
	{
		if (arr[i] % 2 != 0) {
			arr[i] *= 10;
		}
	}
}


int findMin()
{
	int mn = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (arr[i] < mn) {
			mn = arr[i];
			minIndex = i;
		}
	}
	return mn;
}


int more10()
{
	int kk = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > 10)
		{
			kk++;
		}
	}
	return kk;
}



lastEven()
{
	int lastI = -1;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] % 2 == 0)
		{
			lastI = i;
		}
	}
	return lastI;
}



int leftMinCnt()
{
	int kk = 0;
	int s = findMin();
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == s) return kk;
		if (arr[i] % 2 == 0) kk++;
	}
}


int task10()
{
	int s = 0, e = lastEven();

	for (int i = 0; i < e; i++)
	{
		if (arr[i] % 2 == 0)
		{
			s = i;
			break;
		}
	}
	for (int i = s + 1; i < e; i++)
	{
		arr[i] *= 100;
	}
	printElements();
}


void deleteElement(int delIndex) 
{
	for (int i = delIndex; i < n - 1; ++i) 
	{
		arr[i] = arr[i + 1];
	}
	n--;
}


void insertElement(int insIndex, int value) 
{
	for (int i = n; i > insIndex; i--) 
	{
		arr[i] = arr[i - 1];
	}
	n++;
	arr[insIndex] = value;
}



void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int item;
	do {
		printf("\n");
		printf("------------------------------\n");
		printf("Содержимое массива:");
		printElements();
		printf("Выберите нужную вам операцию:\n");
		printf("1: Ввести с клавиатуры массив\n");
		printf("2: x10 для всех нечетных элементов\n");
		printf("3: Найти минимальный элемент\n");
		printf("4: количество > 10\n");
		printf("5: х2 для последнего четного\n");
		printf("6: сколько четных левее минимального\n");
		printf("10: Все элементы между первым и последним четным увеличить в 100 раз\n");
		printf("11: удалить заданный элемент\n");
		printf("12: вставить новый элемент в заданное место\n");
		printf("13: удалить минимальный элемент\n");
		printf("14: Перед минимальным элементом вставить 0\n");
		printf("20: сохранить массив в файлик 0\n");
		printf("21: вытащить массив из файлика 0\n");
		printf("\n");
		printf("0: Выйти из программы\n");
		printf("Выбранная операция >>>>>> ");

		scanf_s("%d", &item);
		switch (item) {
		case 1:
			keyboardInput();
			break;

		case 2:
			oddsX10();
			break;

		case 3:
		{
			int min = findMin();
			printf("min = %d\n", min);
		}
		break;
		case 4:
		{
			printf("х2 для последнего четного = %d\n", arr[lastEven()] * 2);
		}
		break;
		case 5:
		{
			if (more10() >= 0)
			{
				printf("%d элементов > 10\n", more10());
			}
			else
			{
				printf("четных нет\n");
			}
		}
		break;
		case 6:
		{
			printf("левее минимального %d\n", leftMinCnt());
		}
		break;
		case 10:
		{
			task10();
		}
		break;
		case 11:
		{
			printf("Индес удаляесмого элемента = ");
			int index;
			scanf_s("%d", &index);
			deleteElement(index);
		}
		break;
		case 12:
		{
			printf("введите индекс и значение ");
			int value, index;
			scanf_s("%d%d", &index, &value);
			insertElement(index, value);
		}
		break;

		case 13:
		{
			findMin();
			printf("индекс минимального элемента = %d ", minIndex);
			deleteElement(minIndex);
			
		}
		break;

		case 14:
		{
			findMin();
			insertElement(minIndex, 0);

		}
		break;
		case 20:
		{
			FILE* fout = fopen("save.txt", "wt");
			if (fout == NULL)
			{
				printf("не удалось открыть файл");
					return;
			}
			fprintf(fout, "%d ", n);
			for (int i = 0; i < n; i++)
			{
				fprintf(fout, "%d ", arr[i]);
			}
			printf("массив сохранен\n");
			fclose(fout);
		}
		break;

		case 21:
		{
			FILE* fin = fopen("save.txt", "rt");
			if (fin == NULL)
			{
				printf("не удалось открыть файл");
				return;
			}
			fscanf(fin, "%d", &n);
			for (int i = 0; i < n; i++)
			{
				fscanf(fin, "%d", &arr[i]);
			}
			printf("массив получен\n");
			fclose(fin);
			printElements();
		}
		break;
		}

	} while (item != 0);
}