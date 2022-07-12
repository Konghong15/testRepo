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

	if (ppHead == NULL)
	{
		*ppHead = node;
		studentList->lastNode = *ppHead;
	}
	else
	{
		student_t* temp = (*ppHead)->next;
		(*ppHead)->next = node;
		node->next = temp;
	}
}

bool removeLast(studentList_t* studentList)
{
	student_t* pHead = studentList->head;
	student_t* pLast = studentList->lastNode;

	if (pHead == NULL)
	{
		return false;
	}

	while (pHead->next != pLast) {
		pHead = pHead->next;
	}
		pHead->next = NULL;

	free(pLast);
	pLast = pHead;

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

	free(*ppHead);
	*ppHead = next;

	return true;
}

bool removeNode(studentList_t* studentList, student_t* node)
{
	student_t* pHead = studentList->head;

	if (pHead == NULL)
	{
		return false;
	}

	while (pHead->next != node) {
		pHead = pHead->next;
	}
	pHead->next = node->next;

	free(node);

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
		printf("肋给等 林家涝聪促.");

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
		printf("肋给等 林家涝聪促.");

		return;
	}

	while (phead != NULL)
	{
		fprintf(stream, "%s %d\n", phead->name, phead->score);
		phead = phead->next;
	}

	fclose(stream);
}