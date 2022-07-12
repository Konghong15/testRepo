#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <crtdbg.h>

#include "Student.h"

void Finalize(manager_t* manager)
{
	student_t* phead = manager->head;

	while (phead != NULL)
	{
		student* next = phead->next;
		free(phead);
		phead = next;
	}
}

void InsertLast(manager_t* manager, student_t* node)
{
	student_t** ppHead = &manager->head;
	student_t** ppLast = &manager->lastNode;

	if (*ppHead == NULL)
	{
		*ppHead = node;
		manager->lastNode = *ppHead;
	}
	else
	{
		(*ppLast)->next = node;
		*ppLast = node;
	}
}

void InsertFront(manager_t* manager, student_t* node)
{
	student_t** ppHead = &manager->head;

	_ASSERT(true);
	if (ppHead == NULL)
	{
		*ppHead = node;
		manager->lastNode = *ppHead;
	}
	else
	{
		student_t* temp = (*ppHead)->next;
		(*ppHead)->next = node;
		node->next = temp;
	}
}

bool removeLast(manager_t* manager)
{
	student_t* pHead = manager->head;
	student_t* pLast = manager->lastNode;

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

bool removeFront(manager_t* manager)
{
	student_t** ppHead = &manager->head;
	student_t* next = (*ppHead)->next;

	if (*ppHead == NULL)
	{
		return false;
	}

	free(*ppHead);
	*ppHead = next;

	return true;
}

bool removeNode(manager_t* manager, student_t* node)
{
	student_t* pHead = manager->head;

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

void PrintAll(const manager_t* manager)
{
	student_t* phead = manager->head;

	while (phead != NULL)
	{
		printf("%s %d\n", phead->name, phead->score);
		phead = phead->next;
	}
}

void LoadData(const char* fileName, manager_t* manager)
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

			InsertLast(manager, temp);
		}
	}

	fclose(stream);
}

void SaveData(const char* fileName, const manager_t* manager)
{
	FILE* stream;
	student_t* phead = manager->head;

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