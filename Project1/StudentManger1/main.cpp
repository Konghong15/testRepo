#include <cassert>

#include "StudentManager.h"
#include "Student.h"


int main(void)
{
	using namespace assignment;

	StudentManager sm;
	StudentManager sm1;
	
	sm.addStudent(new Student(111, 222 ,333, "u123abdcdc"));
	sm.addStudent(new Student(222, 333 ,111, "u2456abdcdc"));
	sm.addStudent(new Student(333, 111 ,222, "u3789abdcdc"));
	sm.addStudent(new Student(300, 300 ,301, "u41011abdcdc"));
	

	sm.PrintAll();
	sm.Sort(SORTED_MATH);
	sm.PrintAll();
	sm.Sort(SORTED_KOR);
	sm.PrintAll();
	sm.Sort(SORTED_AVERAGE);
	sm.PrintAll();

	return 0;
}