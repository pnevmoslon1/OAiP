#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

struct Node {
	int data;
	struct Node* next;
};

struct Node* first = NULL;

void addToHead(int value) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->next = first;
	newNode->data = value;
	first = newNode;
}

void printList() {
	struct Node* ptr = first;
	while (ptr != NULL) {
		printf("(%d) -> ", ptr->data);
		ptr = ptr->next;
	}
	printf("NULL\n\n");
}

void deleteFromHead() {
	int value = first->data;
	struct Node* delNode = first;
	first = first->next;
	free(delNode);
}

int contains(int value) {
	struct Node* ptr = first;
	while (ptr != NULL) {
		if (ptr->data == value) {
			return 1;
		}
		ptr = ptr->next;
	}
	return 0;
}

void clearList() {
	while (first != NULL) {
		struct Node* delNode = first;
		first = first->next;
		free(delNode);
	}
}

int sumList() {
	int k = 0;
	struct Node* sumNode = first;
	while (sumNode != NULL) {
		k += sumNode->data;
		sumNode = sumNode->next;
	}
	return k;
}

int countOfEvenNums() {
	int k = 0;
	struct Node* qNode = first;
	while (qNode != NULL) {
		if (qNode->data % 2 == 0) {
			k++;
		}
		qNode = qNode->next;
	}
	return k;
}

void oddsX10() {
	struct Node* r = first;
	while (r != NULL) {
		if (r->data % 2 != 0) {
			r->data *= 10;
		}
		r = r->next;
	}
}

void elementIx100(int i) {
	int index = 0;
	struct Node* r = first;
	while (r != NULL) {
		if (index == i) {
			r->data *= 100;
			return;
		}
		r = r->next;
		index++;
	}
}

void elementIleftx10(int i) {
	int index = 0;
	struct Node* r = first;
	while (r != NULL) {
		if (index < i) {
			r->data *= 10;
		}
		r = r->next;
		index++;
	}
}

void elementIRightX10(int i) {
	int index = 0;
	struct Node* r = first;
	while (r != NULL) {
		if (index > i) {
			r->data *= 10;
		}
		r = r->next;
		index++;
	}
}

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	first = NULL;
	printList();
	int act = 1;
	while (act != 0) {
		printf("0. EXIT\n1. addToHead\n2. printList\n3. deleteFromHead\n4. contains\n5. clearList\n6. countOfEvenNums\n7. oddsX10\n8. elementIx100\n9. elementILeftx10\n10. elementIRightX10\n");
		printf("выберите заданите: ");
		scanf_s("%d", &act);
		switch (act) {
		case 0:
			break;
		case 1:
		{
			int ch;
			printf("элемент который нужно добавить: ");
			scanf_s("%d", &ch);
			addToHead(ch);
			break;
		}
		case 2:
			printList();
			break;
		case 3:
			deleteFromHead();
			break;
		case 4:
		{
			int ch;
			printf("выберите число: ");
			scanf_s("%d", &ch);
			printf("contains(%d) = %d\n", ch, contains(ch));
			break;
		}
		case 5:
			clearList();
			break;
		case 6:
			printf("%d\n", countOfEvenNums());
			break;
		case 7:
			oddsX10();
			break;
		case 8:
		{
			int ch;
			printf("введите число: ");
			scanf_s("%d\n", &ch);
			elementIx100(ch);
			break;
		}
		case 9:
		{
			int ch;
			printf("введите число: ");
			scanf_s("%d", &ch);
			elementIleftx10(ch);
			break;
		}
		case 10:
		{
			int ch;
			printf("введите число: ");
			scanf_s("%d", &ch);
			elementIRightX10(ch);
			break;
		}
		}
		printList();
	}
}