#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "StudentList.h"

int main(void)
{
	studentList_t studentList = { 0, };

	student_t* s1 = (student_t*)malloc(sizeof(student_t));
	strcpy(s1->name, "ABC");
	s1->score = 13;
	s1->next = NULL;

	student_t* s2 = (student_t*)malloc(sizeof(student_t));
	strcpy(s2->name, "DEF");
	s2->score = 22;
	s2->next = NULL;

	student_t* s3 = (student_t*)malloc(sizeof(student_t));
	strcpy(s3->name, "GHI");
	s3->score = 33;
	s3->next = NULL;

	student_t* s4 = (student_t*)malloc(sizeof(student_t));
	strcpy(s4->name, "JKL");
	s4->score = 44;
	s4->next = NULL;

	student_t* s5 = (student_t*)malloc(sizeof(student_t));
	strcpy(s5->name, "MNO");
	s5->score = 55;
	s5->next = NULL;

	InsertLast(&studentList, s1);
	InsertLast(&studentList, s2);
	InsertLast(&studentList, s3);
	InsertLast(&studentList, s4);
	InsertLast(&studentList, s5);

	removeFront(&studentList);
	removeLast(&studentList);
	removeNode(&studentList, s3);

	SaveData("studentInfo.txt", &studentList);

	studentList_t srcStudentList = { 0, };
	LoadData("studentInfo.txt", &srcStudentList);

	PrintAll(&srcStudentList);
	
	Finalize(&studentList);
	Finalize(&srcStudentList);

	return 0;
}