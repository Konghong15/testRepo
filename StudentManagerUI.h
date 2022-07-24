#pragma once

#include "StudentManager.h"

namespace studentManager
{
	enum class eUserRequest
	{
		PRINT_ALL,
		ADD_STUENT,
		REMOVE_STUDENT,
		SEARCH_STUDENT,
		SORT_STUDENT,
		SAVE_STUDNET,
		LOAD_STUDENT,
		CREATE_RANDOM_DATA,
		Finalize,
		COUNT
	};

	class StudentManagerUI final
	{
	public:
		StudentManagerUI() = default;
		~StudentManagerUI() = default;
		StudentManagerUI(const StudentManagerUI&) = delete;
		StudentManagerUI& operator=(const StudentManagerUI&) = delete;

		void Run();

	private:
		void printTitle();
		void printSelection();
		int getUserInput();

		void addStudent();
		void removeStudent();
		void searchStudent();
		void sortStudents();
		void saveStudents();
		void loadStudents();
		void createRandomData();
		void finalize();

	private:
		enum { TOTAL_SPACE_SIZE = 89 };
		enum { CENTER_SIZE = 50 };
		enum { WORD_INTERVAL = 21 };
		StudentManager mStudentManager;
	};
}