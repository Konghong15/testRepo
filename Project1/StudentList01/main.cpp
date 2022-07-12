#include <stdio.h>
#include "StudentList.h"

#include <stdio.h>




int main()
{
	student_t* pHead = NULL;
	InsertLast(&pHead, "AAA", 10);
	InsertLast(&pHead, "BBB", 20);
	InsertLast(&pHead, "CCC", 30);
	InsertLast(&pHead, "DDD", 40);
	removeLast(&pHead);
	removeLast(&pHead);
	removeLast(&pHead);
	removeLast(&pHead);
	Finalize(&pHead);

	InsertFront(&pHead, "AAA", 10);
	InsertFront(&pHead, "BBB", 20);
	InsertFront(&pHead, "CCC", 30);
	InsertFront(&pHead, "DDD", 40);
	removeFront(&pHead);
	removeFront(&pHead);
	removeFront(&pHead);
	removeFront(&pHead);
	Finalize(&pHead);

	InsertFront(&pHead, "AAA", 10);
	InsertFront(&pHead, "BBB", 20);
	InsertFront(&pHead, "CCC", 30);
	InsertFront(&pHead, "DDD", 40);
	removeLast(&pHead);
	removeLast(&pHead);
	removeLast(&pHead);
	removeLast(&pHead);
	Finalize(&pHead);

	InsertLast(&pHead, "AAA", 10);
	InsertLast(&pHead, "BBB", 20);
	InsertLast(&pHead, "CCC", 30);
	InsertLast(&pHead, "DDD", 40);
	removeLast(&pHead);
	removeLast(&pHead);
	removeLast(&pHead);
	removeLast(&pHead);
	Finalize(&pHead);

	return 0;
}