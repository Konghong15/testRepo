#pragma once

#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>

#include "LinkedList.h"
#include "Student.h"

namespace assignment
{
	enum eLoadType
	{
		LOAD_APPEND,
		LOAD_OVERWRITE
	};

	enum eSortingType
	{
		SORTED_KOR,
		SORTED_ENG,
		SORTED_MATH,
		SORTED_AVERAGE
	};

	class StudentManager
	{
	public:
		StudentManager() = default;
		StudentManager(const StudentManager& rhs);
		~StudentManager();
		StudentManager& operator=(const StudentManager& rhs);

		void addStudent(const Student* student);
		void addStudent(const Student* student, size_t index);
		bool removeStudent(const char* name);
		size_t FindIndex(const char* name);
		const Student& operator[](int index);
		size_t GetStudentCount();

		void Print(unsigned int index);
		void PrintAll();
		bool SaveFile(const char* fileName);
		bool LoadFile(const char* fileName, eLoadType loadType);
		void Sort(eSortingType sortingType);

	private:
		LinkedList<Student> mStudents;
	};
}