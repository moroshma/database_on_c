typedef struct {
	char  name[255];
	char lastName[255];
	int age;
	char direction[255];// направление
} students;


bool newUserVerification(FILE* file, char* a);

char* concat(char* s1, char* s2);

void printLogo();

void printAllStu( students* STU, int* lastSTU);

void newStudent( students* st, int* last);

void loadToFile( students* STU, int* lastSTU, char* username);

void loadFromFile(struct students* STU, int* lastSTU, char* username);

void sortAscending(struct students* STU, int* n);

void parseData(char* data, char* newArr);

void descendingAscending(students* STU, int* n, int* lastSTU);
