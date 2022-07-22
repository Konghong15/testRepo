#include "Student.h"

namespace assignment
{
	Student::Student(size_t kor, size_t eng, size_t math, const char name[4])
		: mKor(kor)
		, mEng(eng)
		, mMath(math)
		, mAverage((kor + eng + math) / 3)
	{
		strncpy(mName, name, 4);
		mName[3] = '\0';
	}
}