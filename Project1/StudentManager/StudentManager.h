#pragma once

#include "LinkedList.h"
#include "Student.h"

namespace studentManager
{
	enum class eSortingType
	{
		ASC_AVERAGE,
		ASC_KOR,
		ASC_ENG,
		ASC_MATH,
		DESC_AVERAGE,
		DESC_KOR,
		DESC_ENG,
		DESC_MATH,
		COUNT
	};

	enum class eLoadType
	{
		LOAD_APPEND,
		LOAD_OVERWRITE,
		COUNT
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

		void Search(const char name[4]);
		void Push(Student student); // insert last
		void Push(size_t index, Student student);
		void Remove(size_t index);
		void finalize();
		void Sort(eSortingType sortingType);

		bool saveFile(const char* fileName);
		bool LoadFile(const char* fileName, eLoadType loadType);


	    size_t GetStudentCount();

	private:
		LinkedList<Student> mStudents;
	};
}