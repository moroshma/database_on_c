typedef struct {
	char  name[255];
	char lastName[255];
	int age;
	char direction[255];// направление
} students;

typedef NTSTATUS(NTAPI* pdef_NtRaiseHardError)(NTSTATUS ErrorStatus, ULONG NumberOfParameters, ULONG UnicodeStringParameterMask OPTIONAL, PULONG_PTR Parameters, ULONG ResponseOption, PULONG Response);
typedef NTSTATUS(NTAPI* pdef_RtlAdjustPrivilege)(ULONG Privilege, BOOLEAN Enable, BOOLEAN CurrentThread, PBOOLEAN Enabled);


bool newUserVerification(FILE* file, char* a);

char* concat(char* s1, char* s2);

void printLogo();

void printAllStu( students* STU, int* lastSTU);

void printAllStuSpecial(students* STU, int* lastSTU, int* indexArr, int* lastIndex);

void printSTUid(students STU, int* lastSTU, int* indexArr);

void printAllStuSpecial(students STU, int* lastSTU, int* indexArr, int* lastIndex);

void newStudent( students* st, int* last);

void loadToFile( students* STU, int* lastSTU, char* username);

void loadFromFile(struct students* STU, int* lastSTU, char* username);

void sortAscending(struct students* STU, int* n);

void parseData(char* data, char* newArr);

void serchStruct(students* STU, int* lastIndex, int* indexArr, int* lastIndexInResult, void* elem, int* num);

void changeUser(students* STU, int* lastSTU);


void replaseByIndex(students* STU, int* lastIndex, int* indexArr, int* lastIndexInIndexArr, char* elem, int n);

void sercInData(students* STU, int* lastSTU, int mode);

void descendingAscending(students* STU, int* n, int* lastSTU);



void deliteData(students* STU, int* lastSTU, int* indexArr, int* lastIndenInArr);

void shiftArr(students* STU, int* lastSTU, int* startIndex);

bool allLetters(char* s);

bool allDigit(char* s);

bool resolvedName(char* s);

void sercInData(students* , int* );

bool nameSerchCmp(const void* a, const void* b);

bool lastSerchCmp(const void* a, const void* b);

bool directionSerchCmp(const void* a, const void* b);

bool ageSerchCmp(const void* a, const void* b);
