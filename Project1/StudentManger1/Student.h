#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <string.h>

namespace assignment
{
	class Student
	{
		
	public:
		Student(size_t kor, size_t eng, size_t math, const char name[4]);
		Student();

	public:
		size_t mKor;
		size_t mEng;
		size_t mMath;
		size_t mAverage;
		char mName[4];
	};
}