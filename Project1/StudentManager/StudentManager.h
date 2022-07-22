#pragma once

#include <iostream>
#include <fstream>

#include "LinkedList.h"
#include "Student.h"

namespace studentManager
{
	enum eLoadType
	{
		LOAD_APPEND,
		LOAD_OVERWRITE
	};

	class StudentManager
	{
		// friend
		friend std::ostream& operator<<(std::ostream& out, const StudentManager& rhs);

	public:
		StudentManager() = default;
		~StudentManager() = default;
		StudentManager(const StudentManager&) = delete;
		StudentManager& operator=(const StudentManager&) = delete;

		void Push(Student student); // insert last
		void Push(size_t index, Student student);
		void Pop(size_t index);
		void finalize();
		void SortAverage();

		bool saveFile(const char* fileName);
		bool LoadFile(const char* fileName, eLoadType loadType);


	    size_t GetStudentCount();

	private:
		LinkedList<Student> mStudents;
	};
}