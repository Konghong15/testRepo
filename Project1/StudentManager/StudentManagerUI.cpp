#include <string>

#include "StudentManagerUI.h"

using namespace std;

namespace studentManager
{
	void home()
	{
		const int SPACE_SIZE = 89;
		const int CENTER_SIZE = 50;

		system("cls");

		cout << '+' << setfill('-') << setw(SPACE_SIZE) << '+' << endl;
		cout << '+' << setfill(' ') << setw(SPACE_SIZE) << '+' << endl;
		cout << '+' << setw(SPACE_SIZE) << '+' << endl;
		cout << '+' << setw(CENTER_SIZE) << "���� ���� ���α׷�" << setw(SPACE_SIZE - CENTER_SIZE) << '+' << endl;
		cout << '+' << setw(SPACE_SIZE) << '+' << endl;
		cout << '+' << setw(SPACE_SIZE) << '+' << endl;
		cout << '+' << setfill('-') << setw(SPACE_SIZE) << '+' << endl;
	}

	int getUserInput()
	{
		string trash;
		int inputNum;
		while (true)
		{
			cin >> inputNum;

			if (cin.fail())
			{
				cin.clear();
				cin >> trash;
				home();
				cout << "�߸��� �Է��Դϴ�. ���ڸ� �Է����ּ���" << endl;
			}
			else
			{
				return inputNum;
			}
		}
	}

	void StudentManagerUI::run()
	{
		using namespace std;

		while (true)
		{
			home();

			cout << "���ϴ� ����� ��ȣ�� �Է����ּ���" << endl;
			int input = getUserInput();
			switch(input)
			{

			}
		}
	}
}