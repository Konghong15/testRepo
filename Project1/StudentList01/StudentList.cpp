#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "StudentList.h"

void Finalize(student_t** students)
{
	student_t* pNode = *students;

	while (pNode != NULL)
	{
		student_t* next = pNode->next;
		free(pNode);

		pNode = next;
	}

	*students = NULL;
}

void InsertLast(student_t** students, const char name[4], int score)
{
	student_t* prevNode = NULL;

	while (*students != NULL)
	{
		prevNode = *students;
		students = &(*students)->next;
	}

	student_t* paStudent = (student_t*)malloc(sizeof(student_t));
	strncpy(paStudent->name, name, 4);
	paStudent->name[3] = '\0';
	paStudent->score = score;
	paStudent->next = NULL;

	*students = paStudent;
	paStudent->prev = prevNode;

	if (prevNode != NULL)
	{
		prevNode->next = paStudent;
	}
}

void InsertFront(student_t** students, const char name[4], int score)
{
	student_t* paStudent = (student_t*)malloc(sizeof(student_t));
	strncpy(paStudent->name, name, 4);
	paStudent->name[3] = '\0';
	paStudent->score = score;
	paStudent->prev = NULL;

	paStudent->next = *students;
	if (*students != NULL)
	{
		(*students)->prev = paStudent;
	}
	*students = paStudent;
}

bool removeLast(student_t** students)
{
	if (*students == NULL)
	{
		return false;
	}

	student_t** prevNode = NULL;
	
	while (*students != NULL)
	{
		prevNode = students;
		students = &(*students)->next;
	}
	
	student_t* prevprevNode = (*prevNode)->prev;
	free(*prevNode);

	if (prevprevNode != NULL)
	{
		prevprevNode->next = NULL;
	}
	else
	{
		*prevNode = NULL;
	}
}

bool removeFront(student_t** students)
{
	if (students == NULL)
	{
		return false;
	}

	student_t* nextNode = (*students)->next;

	free(*students);
	*students = nextNode;

	if (*students != NULL)
	{
		(*students)->prev = NULL;
	}
}