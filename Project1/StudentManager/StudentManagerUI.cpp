#include <iostream>
#include <iomanip>

#include "StudentManagerUI.h"

#define LAST_REMARK std::cout << "���������� �����Ͽ����ϴ�. ���� Ű�� ������ �ʱ� ȭ������ �Ѿ�ϴ�." << std::endl; cin.get();

using namespace std;

namespace studentManager
{

	void StudentManagerUI::Run()
	{
		using namespace std;

		while (true)
		{
			system("cls");
			printTitle();
			printSelection();

			int input = getUserInput();
			switch (static_cast<eUserRequest>(input))
			{
			case eUserRequest::PRINT_ALL:
			{
				cout << mStudentManager << endl;
				LAST_REMARK;

				break;
			}
			case eUserRequest::ADD_STUENT:
			{
				system("cls");
				printTitle();
				addStudent();

				break;
			}
			case eUserRequest::REMOVE_STUDENT:
			{
				system("cls");
				printTitle();
				removeStudent();

				break;
			}
			case eUserRequest::SEARCH_STUDENT:
			{
				system("cls");
				printTitle();
				searchStudent();

				break;
			}
			case eUserRequest::SORT_STUDENT:
			{
				system("cls");
				printTitle();
				sortStudents();

				break;
			}
			case eUserRequest::SAVE_STUDNET:
			{
				system("cls");
				printTitle();
				saveStudents();

				break;
			}
			case eUserRequest::LOAD_STUDENT:
			{
				system("cls");
				printTitle();
				loadStudents();

				break;
			}
			case eUserRequest::CREATE_RANDOM_DATA:
			{
				system("cls");
				printTitle();
				createRandomData();

				break;
			}
			case eUserRequest::Finalize:
			{
				system("cls");
				printTitle();
				finalize();

				break;
			}
			default:
				cout << "�����Ͻ� ��ȣ�� ���� ����Դϴ�." << endl;
				cin.get();

				continue;
			}
		}
	}

	void StudentManagerUI::printTitle()
	{
		cout << right;
		cout << '+' << setfill('-') << setw(TOTAL_SPACE_SIZE) << '+' << endl;
		cout << '+' << setfill(' ') << setw(TOTAL_SPACE_SIZE) << '+' << endl;
		cout << '+' << setw(TOTAL_SPACE_SIZE) << '+' << endl;
		cout << '+' << setw(CENTER_SIZE) << "���� ���� ���α׷�" << setw(TOTAL_SPACE_SIZE - CENTER_SIZE) << '+' << endl;
		cout << '+' << setw(TOTAL_SPACE_SIZE) << '+' << endl;
		cout << '+' << setw(TOTAL_SPACE_SIZE) << '+' << endl;
		cout << right << '+' << setfill('-') << setw(TOTAL_SPACE_SIZE) << '+' << endl;
	}

	void StudentManagerUI::printSelection()
	{
		cout << left << setw(5) << setfill(' ') << '+';
		cout << setw(WORD_INTERVAL - 1) << "[0] PrintAll"
			<< setw(WORD_INTERVAL) << "[1] Add"
			<< setw(WORD_INTERVAL) << "[2] Remove"
			<< setw(WORD_INTERVAL) << "[3] Search" << " +" << endl;

		cout << setw(5) << '+';
		cout << setw(WORD_INTERVAL - 1) << "[4] Sort"
			<< setw(WORD_INTERVAL) << "[5] Save"
			<< setw(WORD_INTERVAL) << "[6] Load"
			<< setw(WORD_INTERVAL) << "[7] Random" << " +" << endl;

		cout << setw(5) << '+';
		cout << setw(WORD_INTERVAL - 1) << "[8] Finalize" << setw(WORD_INTERVAL * 3) << ' ' << " +" << endl;

		cout << setw(TOTAL_SPACE_SIZE) << '+' << '+' << endl;
		cout << setw(25) << '+' << setw(64) << "���ϴ� ����� ��ȣ�� �Է����ּ���" << '+' << endl;
		cout << right << '+' << setfill('-') << setw(TOTAL_SPACE_SIZE) << '+' << endl;
	}

	int StudentManagerUI::getUserInput()
	{
		string trash;
		int inputNum;

		while (true)
		{
			cin >> inputNum;
			cin.ignore(LONG_MAX, '\n');

			if (cin.fail())
			{
				cin.clear();
				cin >> trash;

				cout << "�߸��� �Է��Դϴ�. ���ڸ� �Է����ּ���" << endl;
			}
			else
			{
				return inputNum;
			}
		}
	}

	void StudentManagerUI::addStudent()
	{
		cout << left << setfill(' ');
		cout << setw(10) << '+' << setw(79) << "�л� ������ ���� ���信 ���߾� �Է����ּ���" << '+' << endl;
		cout << setw(10) << '+' << setw(79) << "�̸��� �׻� 3�ڸ��� ����˴ϴ�." << '+' << endl;
		cout << setw(10) << '+' << setw(79) << "<�̸�> <���� ����> <���� ����> <���� ����>" << '+' << endl;
		cout << setw(10) << '+' << setw(79) << "����) kgc 23 32 45" << '+' << endl;
		cout << setfill('-') << setw(TOTAL_SPACE_SIZE) << '+' << '+' << endl;

		char name[4];
		size_t kor;
		size_t eng;
		size_t math;
		string trash;

		while (true)
		{
			cout << "�߰��� �л� ���� :";
			cin >> setw(4) >> name;
			cin.ignore(LONG_MAX, ' ');
			cin >> kor >> eng >> math;
			cin.ignore(LONG_MAX, '\n');

			if (cin.fail())
			{
				cin.clear();
				cin >> trash;
				cin.ignore(LONG_MAX, '\n');

				cout << "�߸��� �Է��Դϴ�. ���Ŀ� ���߾� �ٽ� �Է����ּ���" << endl;
				cin.get();
			}
			else if (kor > 100 || eng > 100 || math > 100)
			{
				cout << "�л��� �ְ� ������ 100���Դϴ�. �ٽ� �Է����ּ���" << endl;
				cin.get();
			}
			else
			{
				mStudentManager.Push(Student(name, kor, eng, math));
				break;
			}
		}

		LAST_REMARK
	}

	void StudentManagerUI::removeStudent()
	{
		cout << left << setfill(' ');
		cout << setw(10) << '+' << setw(79) << "������ �л� ��ȣ�� �Է����ּ���" << '+' << endl;
		cout << setw(10) << '+' << setw(79) << "������ �Ѿ ���� �Է��� �� ������ �л��� �����˴ϴ�." << '+' << endl;
		cout << setfill('-') << setw(TOTAL_SPACE_SIZE) << '+' << '+' << endl;

		cout << "���� Ű�� ������ �л� ����� ��µ˴ϴ�." << endl;
		cin.get();

		cout << mStudentManager << endl;

		cout << "������ ��ȣ : ";
		mStudentManager.Remove(getUserInput());

		LAST_REMARK
	}

	void StudentManagerUI::searchStudent()
	{
		cout << left << setfill(' ');
		cout << setw(10) << '+' << setw(79) << "�˻��� ���ϴ� �л��� �̸��� �Է����ּ���" << '+' << endl;
		cout << setfill('-') << setw(TOTAL_SPACE_SIZE) << '+' << '+' << endl;

		char name[4];
		cin >> setw(4) >> name;
		cin.ignore(LONG_MAX, '\n');
		mStudentManager.Search(name);

		LAST_REMARK
	}

	void StudentManagerUI::sortStudents()
	{
		cout << left << setw(5) << setfill(' ') << '+';
		cout << setw(WORD_INTERVAL - 1) << "[0] ��� ��������"
			<< setw(WORD_INTERVAL) << "[1] ���� ��������"
			<< setw(WORD_INTERVAL) << "[2] ���� ��������"
			<< setw(WORD_INTERVAL) << "[3] ���� ��������" << " +" << endl;

		cout << setw(5) << '+';
		cout << setw(WORD_INTERVAL - 1) << "[4] ��� ��������"
			<< setw(WORD_INTERVAL) << "[5] ���� ��������"
			<< setw(WORD_INTERVAL) << "[6] ���� ��������"
			<< setw(WORD_INTERVAL) << "[7] ���� ��������" << " +" << endl;
		cout << setw(TOTAL_SPACE_SIZE) << '+' << '+' << endl;
		cout << setw(25) << '+' << setw(64) << "���ϴ� ���� ����� ���� �Է����ּ���" << '+' << endl;
		cout << setfill('-') << setw(TOTAL_SPACE_SIZE) << '+' << '+' << endl;

		size_t number = getUserInput();
		while (number >= static_cast<size_t>(eSortingType::COUNT))
		{
			cout << "���� ���� ���� �Է����ּ���" << endl;
			number = getUserInput();
		}

		switch (static_cast<eSortingType>(number))
		{
		case eSortingType::ASC_AVERAGE:
			mStudentManager.Sort(eSortingType::ASC_AVERAGE);
			break;
		case eSortingType::ASC_KOR:
			mStudentManager.Sort(eSortingType::ASC_KOR);
			break;
		case eSortingType::ASC_ENG:
			mStudentManager.Sort(eSortingType::ASC_ENG);
			break;
		case eSortingType::ASC_MATH:
			mStudentManager.Sort(eSortingType::ASC_MATH);
			break;
		case eSortingType::DESC_AVERAGE:
			mStudentManager.Sort(eSortingType::DESC_AVERAGE);
			break;
		case eSortingType::DESC_KOR:
			mStudentManager.Sort(eSortingType::DESC_KOR);
			break;
		case eSortingType::DESC_ENG:
			mStudentManager.Sort(eSortingType::DESC_ENG);
			break;
		case eSortingType::DESC_MATH:
			mStudentManager.Sort(eSortingType::DESC_MATH);
			break;
		default:
			_ASSERT(false);
			break;
		}

		cout << mStudentManager << endl;

		LAST_REMARK
	}

	void StudentManagerUI::saveStudents()
	{
		char fileName[21];
		cout << left << setfill(' ');
		cout << setw(25) << '+' << setw(64) << "������ ���� ���� �Է����ּ��� (20�ڱ��� �����մϴ�)" << '+' << endl;
		cout << setfill('-') << setw(TOTAL_SPACE_SIZE) << '+' << '+' << endl;

		cin >> setw(21) >> fileName;
		mStudentManager.saveFile(fileName);

		LAST_REMARK
	}
	void StudentManagerUI::loadStudents()
	{
		char fileName[21];

		cout << left << setfill(' ');
		cout << setw(25) << '+' << setw(64) << "�ҷ��� ���� ���� �Է����ּ���" << '+' << endl;
		cout << setw(25) << '+' << setw(64) << "�ҷ����� �ɼ� [0] �̾� ���̱� [1] ���� ����" << '+' << endl;
		cout << setfill('-') << setw(TOTAL_SPACE_SIZE) << '+' << '+' << endl;

		cout << "���� �� :";
		cin >> setw(21) >> fileName;

		cout << "�ҷ����� �ɼ� :";
		size_t number = getUserInput();
		while (number >= static_cast<size_t>(eLoadType::COUNT))
		{
			cout << "���� ���� ���� �Է����ּ���" << endl;

			cout << "�ҷ����� �ɼ� :";
			number = getUserInput();
		}

		switch (number)
		{
		case 0:
			mStudentManager.LoadFile(fileName, eLoadType::LOAD_APPEND);
		case 1:
			mStudentManager.LoadFile(fileName, eLoadType::LOAD_OVERWRITE);
		default:
			break;
		}

		LAST_REMARK
	}

	void StudentManagerUI::createRandomData()
	{
		cout << left << setfill(' ');
		cout << setw(25) << '+' << setw(64) << "���� ������ 10���� �߰��մϴ�" << '+' << endl;
		cout << setfill('-') << setw(TOTAL_SPACE_SIZE) << '+' << '+' << endl;

		srand(time(NULL));
		char name[4] = "tp0";
		size_t kor;
		size_t eng;
		size_t math;

		for (int i = 0; i < 10; ++i)
		{
			kor = rand() % 101;
			eng = rand() % 101;
			math = rand() % 101;
			mStudentManager.Push(Student(name, kor, eng, math));
			++(name[2]);
		}

		LAST_REMARK
	}

	void StudentManagerUI::finalize()
	{
		mStudentManager.finalize();

		LAST_REMARK
	}
}