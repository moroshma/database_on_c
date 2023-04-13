#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>
#include <windows.h>
#include "app.h"
#include < string.h >
#include <conio.h>
#include <ctype.h>

//typedef struct students students;

typedef struct  {
	char  name[255];
	char lastName[255];
	int age;
	char direction[255];// направление
} students;


void main() {

	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console, WH_FOREGROUNDIDLE);
	system("chcp 1251");

	char userName[255];
	FILE* dataUser = fopen("UserData.txt", "r");
	students STU[255];




	int lastSTU = -1;


	printLogo();
	
	printf("Hello, enter your name and the database will be loaded automatically,\n if you do not want this, then enter a new name to create an empty database\n");

	scanf("%255[^\n]", userName);
	
	
	newUserVerification(dataUser, userName);
	int n;
	

	while (1) {
		system("cls");
		printLogo();
		printf("\n select the desired item:\n 1. entering user data\n 2. print students\n");
		scanf("%d", &n);
		switch (n)
		{
		case 1:
			system("cls");
			printLogo();
			printf("\n select the desired item:\n 1. console input\n 2. load from file input\n");
			scanf("%d", &n);
			switch (n)
			{
			case 1:
				newStudent(STU, &lastSTU);
				//printf("%d", STU[0].age);
				printf("students add press any key to return\n");
				
				//scanf("%s", &s);
				_getch();
				break;
			case 2:

				break;
			default:
				break;
			}
			break;



		case 2:
			system("cls");
			printLogo();
			printf("\n select the desired item:\n 1. console output\n 2. file output\n");
			scanf("%d", &n);

			switch (n)
			{
			case 1:
				printAllStu(STU, &lastSTU);
				_getch();
				break;
			case 2:

				break;

			default:
				break;
			}
			break;

		default:
			printf("Invalid data, try again\n press any key: ");
			_getch();
		}

	}
		
	
	

	

}



bool newUserVerification(FILE* file, char* user) {
	char name[255];
	char buffer[255];

	
	while (fgets(buffer, 255, file) != NULL)
	{
		if (strcmp(buffer, concat(user, "\n")) == 0) {
			printf("Welcome back %s enjoy our product!\n", user);

			return true;
		}
		
	}

	
		FILE* append = fopen("UserData.txt", "a");

		char* tDataUserName = concat(concat("UserData", user), ".txt");

		FILE* dtUser = fopen(tDataUserName, "w");

		fputs(user, append);
		fputs("\n", append);

		fclose(append);
		fclose(dtUser);	
		printf("We are glad that you have decided to use our product.\n");

		return FALSE;
}

char* concat(char* s1, char* s2) {

	size_t len1 = strlen(s1);
	size_t len2 = strlen(s2);

	char* result = malloc(len1 + len2 + 1);

	if (!result) {
		fprintf(stderr, "malloc() failed: insufficient memory!\n");
		return NULL;
	}

	memcpy(result, s1, len1);
	memcpy(result + len1, s2, len2 + 1);

	return result;
}


void printLogo() {
	printf("   _____    ______   ___       _   __   __ __    ____   _   __   ____   ____ \n");
	printf("  / ___/   /_  __/  /   |     / | / /  / //_/   /  _/  / | / /  / __ \\ / __ )\n");
	printf("  \\__ \\     / /    / /| |    /  |/ /  / ,<      / /   /  |/ /  / / / // __  |\n");
	printf(" ___/ /    / /    / ___ |   / /|  /  / /| |   _/ /   / /|  /  / /_/ // /_/ / \n");
	printf("/____/    /_/    /_/  |_|  /_/ |_/  /_/ |_|  /___/  /_/ |_/  /_____//_____/  \n\n\n");

}

void printAllStu(students* STU, int* lastSTU) {


	printf("*-------------------------------------------------------*\n");
	printf("|Sn |   Name     |Last name   |   age      |Direction   |\n");
	printf("|-- | ---------- | ---------- | ---------- | ---------- |\n");

	for (int i = 0; i < *lastSTU + 1; i++) {
			
	printf("|%-3d|%-12s|%-12s|   %-9d|%-12s|\n", i+1,  STU[i].name, STU[i].lastName , STU[i].age, STU[i].direction);

	
	if (i != *lastSTU)
		printf("|-- | ---------- | ---------- | ---------- | ---------- |\n");
			
	}
	printf("*-------------------------------------------------------*\n");




}

void newStudent(students* st, int* last) {
	system("cls");
	printLogo();
	*last = *last + 1;
	/*
	char name[255];
	char lastName[255];
	int age;
	char direction[255]; // направление
	*/
	printf("input new name:\n");
	scanf("%s", &st[*last].name);
	
	printf("\ninput new last name:\n");
	scanf("%s", &st[*last].lastName);

	printf("\ninput age:\n");
	scanf("%d", &(st[*last].age));

	printf("\ninput direction:\n");
	scanf("%s", &st[*last].direction);

	

}

// TODO: Создать структуру с полями и создание файла нужен файл по типу user 