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
		cout << '+' << setw(CENTER_SIZE) << "성적 관리 프로그램" << setw(SPACE_SIZE - CENTER_SIZE) << '+' << endl;
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
				cout << "잘못된 입력입니다. 숫자를 입력해주세요" << endl;
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

			cout << "원하는 기능의 번호를 입력해주세요" << endl;
			int input = getUserInput();
			switch(input)
			{

			}
		}
	}
}