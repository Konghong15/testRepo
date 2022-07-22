#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <iomanip>
#include <iostream>
#include <string>


namespace studentManager
{
	class StudentManager;

	class Student
	{
		friend class StudentManager;

		friend std::ostream& operator<<(std::ostream& out, const Student& student);

	public:
		Student() = default;
		Student(const char* name, size_t kor, size_t eng, size_t math);
		
		const char* GetName() const;
		size_t GetKorean() const;
		size_t GetEnglish() const;
		size_t GetMath() const;
		size_t GetAverage() const;

	private:
		enum { NAME_SIZE = 3 };

		size_t mKorean;
		size_t mEnglish;
		size_t mMath;
		char mName[NAME_SIZE + 1];
	};
}