#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <windows.h>
#include "app.h"
#include <string.h >
#include <conio.h>
#include <ctype.h>

//typedef struct students students;




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
		printf("\n select the desired item:\n 1. entering user data\n 2. print students\n 3. sort arr\n 4. serch \n 5. delite elem\n 7. exit\n");
		scanf("%d", &n);
		switch (n)
		{
		case 1:
			system("cls");
			printLogo();
			printf("\n select the desired item:\n 1. console input\n 2. load from file input\n 3.exit.\n");
			scanf("%d", &n);
			switch (n)
			{
			case 1:
				newStudent(STU, &lastSTU);
				printf("students add press any key to return\n");
				_getch();
				break;
			case 2:
				loadFromFile(STU, &lastSTU, userName);
				break;

			case 3:

				break;
			default:
				printf("Invalid data, try again\n press any key: ");
				_getch();
				break;
			}
			break;



		case 2:
			system("cls");
			printLogo();
			printf("\n select the desired item:\n 1. console output\n 2. file output\n 3. exit.\n");
			scanf("%d", &n);

			switch (n)
			{
			case 1:
				printAllStu(STU, &lastSTU);
				_getch();
				break;
			case 2:
				loadToFile(STU, &lastSTU, userName);
				_getch();
				break;
			case 3:
				break;

			default:
				printf("Invalid data, try again\n press any key: ");
				_getch();
				break;
			}
			break;
		case 3:

			system("cls");
			printLogo();
			printf("\n select the desired item:\n 1.ascending sort \n 2. descending sort\n3. exit.\n");
			scanf("%d", &n);

			switch (n)
			{
			case 1:
				system("cls");
				printLogo();
				printf("\n select the desired item:\n 1.sort name \n 2.sort last name\n 3. sort age\n 4. sort direction\n 5. exit.\n");
				scanf("%d", &n);
				if (n == 5)
					break;
				sortAscending(STU, &n, &lastSTU);
				break;
			case 2:

				system("cls");
				printLogo();
				printf("\n select the desired item:\n 1.sort name \n 2.sort last name\n 3. sort age\n 4. sort direction\n 5. exit.\n");
				scanf("%d", &n);

				if (n == 5)
					break;

				descendingAscending(STU, &n, &lastSTU);
				break;

			case 3:
				break;
			default:
				printf("Invalid data, try again\n press any key: ");
				_getch();
				break;
			}
			break;
		case 4:
			system("cls");
			printLogo();
			sercInData(STU, &lastSTU,1);
			break;
		case 5:
			system("cls");
			printLogo();
			sercInData(STU, &lastSTU, 0); //mode 0 - delite mode 1- serch 
			break;

		case 7:
			printf("Have a good time <3\n Press any key: ");
			_getch();
			exit(1);

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
			printf("Welcome back %s enjoy our product!\n press any key", user);
			_getch();
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
		printf("We are glad that you have decided to use our product.\n press any key");
		_getch();

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
	printf("|Sn |   Name     |Last name   |   Age      |Direction   |\n");
	printf("|-- | ---------- | ---------- | ---------- | ---------- |\n");

	for (int i = 0; i < *lastSTU + 1; i++) {
			
	printf("|%-3d|%-12s|%-12s|   %-9d|%-12s|\n", i+1,  STU[i].name, STU[i].lastName , STU[i].age, STU[i].direction);

	
	if (i != *lastSTU)
		printf("|-- | ---------- | ---------- | ---------- | ---------- |\n");
			
	}
	printf("*-------------------------------------------------------*\n");




}

void printAllStuSpecial(students* STU, int* lastSTU, int* indexArr, int* lastIndex) {


	printf("*-------------------------------------------------------*\n");
	printf("|Sn |   Name     |Last name   |   Age      |Direction   |\n");
	printf("|-- | ---------- | ---------- | ---------- | ---------- |\n");

	for (int i = 0; i < *lastIndex + 1; i++) {

		printf("|%-3d|%-12s|%-12s|   %-9d|%-12s|\n", i + 1, STU[indexArr[i]].name, STU[indexArr[i]].lastName, STU[indexArr[i]].age, STU[indexArr[i]].direction);
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


void loadToFile(students* STU, int* lastSTU, char * username) {


	char* tDataUserName = concat(concat("UserData", username), ".txt");
	FILE* append = fopen(tDataUserName, "w");

	for (int i = 0; i <= *lastSTU; i++) {
		fprintf(append, "%s;", STU[i].name);
		fprintf(append, "%s;", STU[i].lastName);
		fprintf(append, "%d;", STU[i].age);
		fprintf(append, "%s\n", STU[i].direction);
	}
	
	fclose(append);
}


void loadFromFile(students* STU, int* lastSTU, char* username) {


	char* tDataUserName = concat(concat("UserData", username), ".txt");
	FILE* append = fopen(tDataUserName, "r");
	char buffer[255];
	char* newArr[4][255];
	*lastSTU = -1;

	

	while (fgets(buffer, 255, append) != NULL)
	{
		*lastSTU = *lastSTU + 1;
		parseData(buffer, STU, lastSTU);	 
	}

	fclose(append);
}



void parseData(char* datauser, students* STU, int* size) {

	int flag = 0;
	int count = 0;
	char agechar[10];

	for (int j = 0; j < 255; j++) {
		if (datauser[j] == '\n' || datauser[j] == '\0') {
			STU[*size].direction[count] = '\0';
			break;
		}
		if (datauser[j] == ';') {
			switch (flag)
			{
			case 0:
				STU[*size].name[count] = '\0';
				break;
			case 1:
				STU[*size].lastName[count] = '\0';
				break;
			case 2:
				agechar[count] = '\0';
				STU[*size].age = atoi(agechar);
			}
			flag++;
			count = 0;
			continue;
		}
		switch (flag) {
		case 0: {
			STU[*size].name[count] = datauser[j];
			count++;
			break;
		}
		case 1: {
			STU[*size].lastName[count] = datauser[j];
			count++;
			break;
		}
		case 2: {
			if (datauser[j] != ' ') {
				agechar[count] = datauser[j];
				count++;
			}
			break;
		}
		case 3: {
			STU[*size].direction[count] = datauser[j];
			count++;
			break;
		}
		}
	}
}




int nameCmpUp(const void* a, const void* b) {
	return strcmp(((students*)a)->name, ((students*)b)->name);
}
int nameCmpDown(const void* a, const void* b) {
	return strcmp(((students*)b)->name, ((students*)a)->name);
}


int lastNameCmpUp(const void* a, const void* b) {
	return strcmp(((students*)a)->lastName, ((students*)b)->lastName);
}
int lastNameCmpDown(const void* a, const void* b) {
	return strcmp(((students*)b)->lastName, ((students*)a)->lastName);
}


int directionCmpUp(const void* a, const void* b) {
	return strcmp(((students*)a)->direction, ((students*)b)->direction);
}
int directionCmpDown(const void* a, const void* b) {
	return strcmp(((students*)b)->direction, ((students*)a)->direction);
}


int ageCmpUp(const void* a, const void* b) {
	return ((students*)a)->age - ((students*)b)->age;
}
int ageCmpDown(const void* a, const void* b) {
	return ((students*)b)->age - ((students*)a)->age;
}



void serchStruct(students* STU, int* lastIndex, int* indexArr, int* lastIndexInResult, void * elem, int* num) {

	switch (*num)
	{
	case 1:
		for (int i = 0; i < *lastIndex + 1; i++) {
			if (strcmp(STU[i].name, (char*)elem) == 0) {
				*lastIndexInResult = *lastIndexInResult + 1;
				indexArr[*lastIndexInResult] = i;
			}
		}

		break;
	case 2:
		for (int i = 0; i < *lastIndex + 1; i++) {
			if (strcmp(STU[i].lastName, (char*)elem) == 0) {
				*lastIndexInResult = *lastIndexInResult + 1;
				indexArr[*lastIndexInResult] = i;
			}
		}

		break;
	case 3:
		for (int i = 0; i < *lastIndex + 1; i++) {
			if (STU[i].age == atoi((char*)elem)) {
				*lastIndexInResult = *lastIndexInResult + 1;
				indexArr[*lastIndexInResult] = i;
		
			}
		}

		break;
	case 4: 
		for (int i = 0; i < *lastIndex + 1; i++) {
			if (strcmp(STU[i].direction, (char*)elem) == 0) {
				*lastIndexInResult = *lastIndexInResult + 1;
				indexArr[*lastIndexInResult] = i;
		
			}
		}

		break;
	default:

		*lastIndexInResult = -1;
		break;
	}
	

}



void sortAscending(students* STU, int* n, int * lastSTU) {
	if (*lastSTU == -1) {
		printf("Hmm, it looks like there is no data in the database\nyou can enter them or load them from a file\n press any key");
	}
	switch(*n)
	{
	case 1:
		qsort(STU, *lastSTU + 1, sizeof(students), nameCmpUp);
	break;

	case 2:
		qsort(STU, *lastSTU + 1, sizeof(students), lastNameCmpUp);
	break;
	case 3:
		qsort(STU, *lastSTU + 1, sizeof(students), ageCmpUp);

	break;
	case 4:
		qsort(STU, *lastSTU + 1, sizeof(students), directionCmpUp);

	break;

	case 5:
		break;

	default:
		break;
	}

}


void descendingAscending(students* STU, int* n, int* lastSTU) {

	switch (*n)
	{
	case 1:
		qsort(STU, *lastSTU + 1, sizeof(students), nameCmpDown);
		break;

	case 2:
		qsort(STU, *lastSTU + 1, sizeof(students), lastNameCmpDown);
		break;
	case 3:
		qsort(STU, *lastSTU + 1, sizeof(students), ageCmpDown);

		break;
	case 4:
		qsort(STU, *lastSTU + 1, sizeof(students), directionCmpDown);

		break;

	case 5:
		break;
	default:
		break;
	}

}



void sercInData(students* STU, int* lastSTU, int  mode) {
	if (mode == 1) {
		printf("\nselect the desired item serch in:\n 1.find name \n 2.find last name\n 3. find age\n 4. find direction\n 5. exit.\n");
	}else 
		printf("\nselect the desired item delite in:\n 1.find name \n 2.find last name\n 3. find age\n 4. find direction\n 5. exit.\n");

	int n;
	char find[255];
	scanf("%d", &n);
	
	
	int indexArr[255];
	int lastIndenInArr = -1;
	if (n >= 1 && n <= 4) {
		printf("\ninput elem:\n");
		scanf("%s", find);

		serchStruct(STU, lastSTU, indexArr, &lastIndenInArr, find, &n);

		if (lastIndenInArr == -1)
			printf("Invalid data\n try again\n");
		else {
			system("cls");
			printLogo();
			if (mode == 1)
				printAllStuSpecial(STU, lastSTU, indexArr, &lastIndenInArr);
			else
				deliteData(STU, lastSTU, indexArr, &lastIndenInArr);
		}
	}
	printAllStu(STU, lastSTU);
	printf("\nCompleted successfully\npress any key: \n");
	_getch();
}

void deliteData(students *STU, int * lastSTU, int * indexArr, int *lastIndenInArr) {
	for (int i = 0; i <= *lastIndenInArr; i++) {
		shiftArr(STU, lastSTU, &i);
		*lastSTU = *lastSTU - 1;
	}
}

void shiftArr(students* STU, int* lastSTU, int * startIndex) {
	for (int i = *startIndex; i < *lastSTU - 1; i++) {

		students tST = STU[i];
		STU[i] = STU[i + 1];
		STU[i + 1] = tST;
	}
}

// TODO: Создать структуру с полями и создание файла нужен файл по типу user 
// TODO: С учётом регистра и без