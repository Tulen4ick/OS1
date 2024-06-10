#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

void main() {
	setlocale(LC_ALL, "Rus");
	int* cpu;
	int* p1;
	int* p2;
	int n; 
	printf("Введите количество процессов: ");
	scanf("%d", &n);
	cpu = (int*)malloc(n * 2 * sizeof(int));
	p1 = (int*)malloc(n * 2 * sizeof(int));
	p2 = (int*)malloc(n * 2 * sizeof(int));
	for (int i = 0; i < n; ++i) {
		scanf("%d", cpu + i * 2 + 0);
		*(cpu + i * 2 + 1) = i+1;
	}
	system("cls");
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 2; ++j)
		{
			printf("%5d ", *(cpu + i * 2 + j));
		}
		printf("\n");
	}
	for (int i = n-1; i >=0; i--) {
		for (int j = 0; j < i; ++j) {
			if (*(cpu + (j) * 2 + 0) < *(cpu + (j+1) * 2 + 0)) {
				int temp1 = *(cpu + (j) * 2 + 0);
				int temp2 = *(cpu + (j) * 2 + 1);
				*(cpu + (j) * 2 + 0) = *(cpu + (j+1) * 2 + 0);
				*(cpu + (j+1) * 2 + 0) = temp1;
				*(cpu + (j) * 2 + 1) = *(cpu + (j+1) * 2 + 1);
				*(cpu + (j+1) * 2 + 1) = temp2;
			}
		}
	}
	printf("\nпосле сортировки: \n");
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 2; ++j)
		{
			printf("%5d ", *(cpu + i * 2 + j));
		}
		printf("\n");
	}
	int s1, s2;
	s1 = s2 = 0;
	int l1, l2, n1;
	l1 = l2 = n1 = 0;
	printf("Таблица разложения: \n");
	printf("-----------------------------------------\n");
	while (n1 < n) {
		if (s1 <= s2) {
			s1 += *(cpu + n1 * 2 + 0);
			*(p1 + l1 * 2 + 0) = *(cpu + n1 * 2 + 0);
			*(p1 + l1 * 2 + 1) = *(cpu + n1 * 2 + 1);
			n1 += 1;
			l1 += 1;
		}
		if (s1 > s2) {
			s2 += *(cpu + n1 * 2 + 0);
			*(p2 + l2 * 2 + 0) = *(cpu + n1 * 2 + 0);
			*(p2 + l2 * 2 + 1) = *(cpu + n1 * 2 + 1);
			n1 += 1;
			l2 += 1;
		}
		printf("1 процеcсор: ");
		for (int i = 0; i < l1; ++i) {
			printf("%d ", *(p1 + i * 2 + 0));
		}
		printf("        ");
		printf("2 процеcсор: ");
		for (int i = 0; i < l2; ++i) {
			printf("%d ", *(p2 + i * 2 + 0));
		}
		printf("\n\n");
	}
	printf("-----------------------------------------\n");
	printf("Результат работы: \n");
	printf("1 процеcсор: ");
	for (int i = 0; i < l1; ++i) {
		printf("%d ", *(p1 + i * 2 + 1));
	}
	printf("Суммарное время обработки: %d\n", s1);
	printf("2 процеcсор: ");
	for (int i = 0; i < l2; ++i) {
		printf("%d ", *(p2 + i * 2 + 1));
	}
	printf("Суммарное время обработки: %d\n", s2);
}
