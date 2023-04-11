#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include <windows.h>



void input(int arr[100][100], int* i, int* j) {
	for (int a = 0; a < *i; a++) {
		for (int b = 0; b < *j; b++) {
			scanf("%d", &arr[a][b]);
		}
	}
}


int check(int arr[100][100], int* i, int* j, int curentI, int curentJ) {
	int count = 0, tI = curentI, tJ = curentJ;

	while (tI < *i) {
		if (arr[tI][tJ] < 0) {
			count += arr[tI][tJ];
		}
		tI++;
	}
	tI = curentI;
	tJ = curentJ;
	int temp = 0;

	if (tJ < (*j - 1)) {
		tJ++;
		while (tI >= 0 && temp < 3) {
			if (arr[tI][tJ] < 0) {
				count += arr[tI][tJ];				
			}
			temp++;
			tI--;
		}
	}
	return count;
}





void outPut(int arr[100][100], int* pi, int* pj) {
	int count = 0;
	/*printf("*-------------------------------------------*\n");
	printf("|Serial Num|     i    |    j     |  Result  |\n");
	printf("|----------|----------|----------|----------|\n");
	for (int i = 0; i < *pi; i++) {
		for (int j = 0; j < *pj; j++) {
			count++;

			printf("|%-10d|%-10d|%-10d|%-10d|\n", count, i + 1, j + 1, check(arr, pi, pj, i, j));

			if (i != *pi - 1 || j != *pj - 1) {
				printf("|----------|----------|----------|----------|\n");;
			}
			}
	}
	printf("*-------------------------------------------*\n");


	*/
}



void main() {

	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console, WH_FOREGROUNDIDLE);

	int arr[100][100], i, j;



	printf("Hi {User_name}, input i and j:  \n");

	/*
	scanf("%d %d", &i, &j);
	input(arr, &i, &j);
	outPut(arr, &i, &j);\
	*/

	printf("   _____    ______   ___       _   __   __ __    ____   _   __   ____   ____ \n");
	printf("  / ___/   /_  __/  /   |     / | / /  / //_/   /  _/  / | / /  / __ \\ / __ )\n");
	printf("  \\__ \\     / /    / /| |    /  |/ /  / ,<      / /   /  |/ /  / / / // __  |\n");
	printf(" ___/ /    / /    / ___ |   / /|  /  / /| |   _/ /   / /|  /  / /_/ // /_/ / \n");
	printf("/____/    /_/    /_/  |_|  /_/ |_/  /_/ |_|  /___/  /_/ |_/  /_____//_____/  \n");
	printf("Hello, enter your name and the database will be loaded automatically,\n if you do not want this, then enter a new name to create an empty database");



}


