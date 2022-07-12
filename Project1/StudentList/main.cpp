#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "StudentList.h"

student_t* GetStudentMalloc(const char name[4], int score)
{
	student_t* student = (student_t*)malloc(sizeof(student_t));

	strncpy(student->name, name, 4);
	student->name[3] = '\0';
	student->score = score;
	student->next = NULL;

	return student;
}

int main(void)
{
	studentList_t studentList = { 0, };
	student_t* students[5];
	char name[4];
	int score;
	
	{
		score = 0;
		strcpy(name, "AAA");
		for (int i = 0; i < 5; ++i)
		{
			++name[0];
			++name[1];
			++name[2];

			score += 10;
			students[i] = GetStudentMalloc(name, score);
		}

		InsertFront(&studentList, students[0]);
		InsertFront(&studentList, students[1]);
		InsertFront(&studentList, students[2]);
		InsertFront(&studentList, students[3]);
		InsertFront(&studentList, students[4]);

		removeFront(&studentList);
		removeFront(&studentList);
		removeFront(&studentList);
		removeFront(&studentList);
		removeFront(&studentList);
	}

	{
		score = 0;
		strcpy(name, "AAA");
		for (int i = 0; i < 5; ++i)
		{
			++name[0];
			++name[1];
			++name[2];

			score += 10;
			students[i] = GetStudentMalloc(name, score);
		}

		InsertFront(&studentList, students[0]);
		InsertFront(&studentList, students[1]);
		InsertFront(&studentList, students[2]);
		InsertFront(&studentList, students[3]);
		InsertFront(&studentList, students[4]);

		removeLast(&studentList);
		removeLast(&studentList);
		removeLast(&studentList);
		removeLast(&studentList);
		removeLast(&studentList);
	}

	{
		score = 0;
		strcpy(name, "AAA");
		for (int i = 0; i < 5; ++i)
		{
			++name[0];
			++name[1];
			++name[2];

			score += 10;
			students[i] = GetStudentMalloc(name, score);
		}

		InsertFront(&studentList, students[0]);
		InsertFront(&studentList, students[1]);
		InsertFront(&studentList, students[2]);
		InsertFront(&studentList, students[3]);
		InsertFront(&studentList, students[4]);

		Finalize(&studentList);
	}

	SaveData("studentInfo.txt", &studentList);

	studentList_t srcStudentList = { 0, };
	LoadData("studentInfo.txt", &srcStudentList);

	PrintAll(&srcStudentList);

	Finalize(&studentList);
	Finalize(&srcStudentList);

	return 0;
}