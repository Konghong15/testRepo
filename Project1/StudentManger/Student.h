#ifndef STUDENT_H
#define STUDENT_H

#ifndef NULL
#define NULL 0
#endif

typedef struct student
{
	char name[4];
	int score;
	struct student* next;
} student_t;

typedef struct mananger
{
	student_t* lastNode;
	student_t* head;
} manager_t;

void Finalize(manager_t* manager);

void InsertLast(manager_t* manager, student_t* node); // O(1)
void InsertFront(manager_t* manager, student_t* node); // O(1)

bool removeLast(manager_t* manager);
bool removeFront(manager_t* manager);
bool removeNode(manager_t* manager, student_t* node);

void PrintNode(const student_t* node);
void PrintAll(const manager_t* manager);

void LoadData(const char* fileName, manager_t* manager);
void SaveData(const char* fileName, const manager_t* manager);

#endif /* STUDENT_H */