#include "Student.h"
#include "LinkedList.h"

void throwzz()
{
	throw;
}

int main(void)
{
	using namespace std;
	using namespace studentManager;
	
	try
	{
		throwzz();
	}
	catch (int exception)
	{
		cout << exception << endl;
	}
	catch (...)
	{
		cout << "hh" << endl;
	}

	cin.get();

	return 0;
}