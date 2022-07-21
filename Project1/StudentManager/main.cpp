#include "Student.h"
#include "LinkedList.h"

int main(void)
{
	using namespace std;
	using namespace assignment1;

	Student s1("aaa", 20, 30, 40);
	Student s2("bbb", 20, 30, 40);

	s1 = s2;
	cout << s1 << s2;
	
	return 0;
}