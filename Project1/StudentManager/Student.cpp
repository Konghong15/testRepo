#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <string>

#include "Student.h"

namespace studentManager
{
	std::ostream& operator<<(std::ostream& out, const Student& student)
	{
		const int SUBJECT_COUNT = 3;

		unsigned int kor = student.mKorean;
		unsigned int eng = student.mEnglish;
		unsigned int math = student.mMath;
		unsigned int total = kor + eng + math;

		out << std::setw(13) << student.mName
			<< std::setw(13) << kor
			<< std::setw(13) << eng
			<< std::setw(13) << math
			<< std::setw(13) << total
			<< std::setw(13) << total / SUBJECT_COUNT << std::endl;

		return out;
	}

	Student::Student(const char* name, size_t kor, size_t eng, size_t math)
		: mKorean(kor)
		, mEnglish(eng)
		, mMath(math)
	{
		strncpy(mName, name, NAME_SIZE + 1);
		mName[NAME_SIZE] = '\0';
	}


	const char* Student::GetName() const
	{
		return (const char*)mName;
	}

	size_t Student::GetKorean() const
	{
		return mKorean;
	}

	size_t Student::GetEnglish() const
	{
		return mEnglish;
	}

	size_t Student::GetMath() const
	{
		return mMath;
	}

	size_t Student::GetAverage() const
	{
		return (mKorean + mEnglish + mMath) / 3;
	}
}