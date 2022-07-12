#ifndef STUDENTLIST_H
#define STUDENTLIST_H

#ifndef NULL
#define NULL 0
#endif

typedef struct student
{
	char name[4];
	int score;
	struct student* next;
} student_t;

typedef struct studentList
{
	student_t* lastNode;
	student_t* head;
} studentList_t;

void Finalize(studentList_t* studentList);

void InsertLast(studentList_t* studentList, student_t* node); // O(1)
void InsertFront(studentList_t* studentList, student_t* node); // O(1)

bool removeLast(studentList_t* studentList);
bool removeFront(studentList_t* studentList);
bool removeNode(studentList_t* studentList, student_t* node);

void PrintNode(const student_t* node);
void PrintAll(const studentList_t* studentList);

void LoadData(const char* fileName, studentList_t* studentList);
void SaveData(const char* fileName, const studentList_t* studentList);

#endif /* STUDENTLIST_H */