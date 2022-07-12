#ifndef STUDENTLIST_H
#define STUDENTLIST_H

#ifndef NULL
#define NULL 0
#endif

typedef struct student
{
	char name[4];
	int score;
	struct student* prev;
	struct student* next;
} student_t;

void Finalize(student_t** students);

void InsertLast(student_t** students, const char name[4], int score);
void InsertFront(student_t** students, const char name[4], int score);

bool removeLast(student_t** students);
bool removeFront(student_t** students);

#endif /* STUDENTLIST_H */