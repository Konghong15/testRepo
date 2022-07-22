#pragma once

#include <iostream>
#include <iomanip>

#include "StudentManager.h"

namespace studentManager
{
	class StudentManagerUI final
	{
	public:
		StudentManagerUI() = default;
		~StudentManagerUI() = default;
		StudentManagerUI(const StudentManagerUI&) = delete;
		StudentManagerUI& operator=(const StudentManagerUI&) = delete;

		void run();


	private:
		StudentManager mStudentManager;
	};
}