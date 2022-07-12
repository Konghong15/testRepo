#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "StudentList.h"

void Finalize(studentList_t* studentList)
{
	student_t* phead = studentList->head;

	while (phead != NULL)
	{
		student* next = phead->next;
		free(phead);
		phead = next;
	}

	memset(studentList, 0, sizeof(studentList_t)); // null 대입
}

void InsertLast(studentList_t* studentList, student_t* node)
{
	student_t** ppHead = &studentList->head;
	student_t** ppLast = &studentList->lastNode;

	if (*ppHead == NULL)
	{
		*ppHead = node;
		studentList->lastNode = *ppHead;
	}
	else
	{
		(*ppLast)->next = node;
		*ppLast = node;
	}
}

void InsertFront(studentList_t* studentList, student_t* node)
{
	student_t** ppHead = &studentList->head;

	if (*ppHead == NULL)
	{
		studentList->lastNode = node;
	}

	node->next = *ppHead;
	*ppHead = node;
}

bool removeLast(studentList_t* studentList)
{
	student_t* pHead = studentList->head;
	student_t** ppLast = &studentList->lastNode;

	if (pHead == NULL)
	{
		return false;
	}
	if (pHead == *ppLast)
	{
		free(*ppLast);
		memset(studentList, 0, sizeof(studentList_t));

		return true;
	}

	while (pHead->next != *ppLast) {
		pHead = pHead->next;
	}
	pHead->next = NULL;

	free(*ppLast);
	*ppLast = pHead;

	return true;
}

bool removeFront(studentList_t* studentList)
{
	student_t** ppHead = &studentList->head;
	student_t* next = (*ppHead)->next;

	if (*ppHead == NULL)
	{
		return false;
	}
	if (*ppHead == studentList->lastNode)
	{
		free(*ppHead);
		memset(studentList, 0, sizeof(studentList_t));

		return true;
	}

	free(*ppHead);
	*ppHead = next;


	return true;
}


void PrintNode(const student_t* node)
{
	printf("%s %d", node->name, node->score);
}

void PrintAll(const studentList_t* studentList)
{
	student_t* phead = studentList->head;

	while (phead != NULL)
	{
		printf("%s %d\n", phead->name, phead->score);
		phead = phead->next;
	}
}

void LoadData(const char* fileName, studentList_t* studentList)
{
	FILE* stream;
	char buf[1024];
	char name[4];
	int score;

	stream = fopen(fileName, "r");

	if (stream == NULL)
	{
		printf("잘못된 주소입니다.");

		return;
	}

	while (true)
	{
		if (fgets(buf, 1024, stream) == NULL)
		{
			break;
		}
		if (sscanf(buf, "%s %d", name, &score) == 2)
		{
			student* temp = (student_t*)malloc(sizeof(student_t));

			strncpy(temp->name, name, 4);
			temp->name[3] = '\0';
			temp->score = score;
			temp->next = NULL;

			InsertLast(studentList, temp);
		}
	}

	fclose(stream);
}

void SaveData(const char* fileName, const studentList_t* studentList)
{
	FILE* stream;
	student_t* phead = studentList->head;

	stream = fopen(fileName, "w");

	if (stream == NULL)
	{
		printf("잘못된 주소입니다.");

		return;
	}

	while (phead != NULL)
	{
		fprintf(stream, "%s %d\n", phead->name, phead->score);
		phead = phead->next;
	}

	fclose(stream);
}