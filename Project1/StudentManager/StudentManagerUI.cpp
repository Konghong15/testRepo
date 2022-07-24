#include <iostream>
#include <iomanip>

#include "StudentManagerUI.h"

#define LAST_REMARK std::cout << "성공적으로 수행하였습니다. 엔터 키를 누르면 초기 화면으로 넘어갑니다." << std::endl; cin.get();

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
				cout << "선택하신 번호는 없는 기능입니다." << endl;
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
		cout << '+' << setw(CENTER_SIZE) << "성적 관리 프로그램" << setw(TOTAL_SPACE_SIZE - CENTER_SIZE) << '+' << endl;
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
		cout << setw(25) << '+' << setw(64) << "원하는 기능의 번호를 입력해주세요" << '+' << endl;
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

				cout << "잘못된 입력입니다. 숫자를 입력해주세요" << endl;
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
		cout << setw(10) << '+' << setw(79) << "학생 정보를 다음 포멧에 맞추어 입력해주세요" << '+' << endl;
		cout << setw(10) << '+' << setw(79) << "이름은 항상 3자리로 적용됩니다." << '+' << endl;
		cout << setw(10) << '+' << setw(79) << "<이름> <국어 성적> <영어 성적> <수학 성적>" << '+' << endl;
		cout << setw(10) << '+' << setw(79) << "예시) kgc 23 32 45" << '+' << endl;
		cout << setfill('-') << setw(TOTAL_SPACE_SIZE) << '+' << '+' << endl;

		char name[4];
		size_t kor;
		size_t eng;
		size_t math;
		string trash;

		while (true)
		{
			cout << "추가할 학생 정보 :";
			cin >> setw(4) >> name;
			cin.ignore(LONG_MAX, ' ');
			cin >> kor >> eng >> math;
			cin.ignore(LONG_MAX, '\n');

			if (cin.fail())
			{
				cin.clear();
				cin >> trash;
				cin.ignore(LONG_MAX, '\n');

				cout << "잘못된 입력입니다. 서식에 맞추어 다시 입력해주세요" << endl;
				cin.get();
			}
			else if (kor > 100 || eng > 100 || math > 100)
			{
				cout << "학생의 최고 성적은 100점입니다. 다시 입력해주세요" << endl;
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
		cout << setw(10) << '+' << setw(79) << "삭제할 학생 번호를 입력해주세요" << '+' << endl;
		cout << setw(10) << '+' << setw(79) << "범위를 넘어선 값을 입력할 시 마지막 학생이 삭제됩니다." << '+' << endl;
		cout << setfill('-') << setw(TOTAL_SPACE_SIZE) << '+' << '+' << endl;

		cout << "엔터 키를 누르면 학생 목록이 출력됩니다." << endl;
		cin.get();

		cout << mStudentManager << endl;

		cout << "삭제할 번호 : ";
		mStudentManager.Remove(getUserInput());

		LAST_REMARK
	}

	void StudentManagerUI::searchStudent()
	{
		cout << left << setfill(' ');
		cout << setw(10) << '+' << setw(79) << "검색을 원하는 학생의 이름을 입력해주세요" << '+' << endl;
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
		cout << setw(WORD_INTERVAL - 1) << "[0] 평균 오름차순"
			<< setw(WORD_INTERVAL) << "[1] 국어 오름차순"
			<< setw(WORD_INTERVAL) << "[2] 영어 오름차순"
			<< setw(WORD_INTERVAL) << "[3] 수학 오름차순" << " +" << endl;

		cout << setw(5) << '+';
		cout << setw(WORD_INTERVAL - 1) << "[4] 평균 내림차순"
			<< setw(WORD_INTERVAL) << "[5] 국어 내림차순"
			<< setw(WORD_INTERVAL) << "[6] 영어 내림차순"
			<< setw(WORD_INTERVAL) << "[7] 수학 내림차순" << " +" << endl;
		cout << setw(TOTAL_SPACE_SIZE) << '+' << '+' << endl;
		cout << setw(25) << '+' << setw(64) << "원하는 정렬 방식을 설정 입력해주세요" << '+' << endl;
		cout << setfill('-') << setw(TOTAL_SPACE_SIZE) << '+' << '+' << endl;

		size_t number = getUserInput();
		while (number >= static_cast<size_t>(eSortingType::COUNT))
		{
			cout << "범위 내의 값을 입력해주세요" << endl;
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
		cout << setw(25) << '+' << setw(64) << "저장할 파일 명을 입력해주세요 (20자까지 가능합니다)" << '+' << endl;
		cout << setfill('-') << setw(TOTAL_SPACE_SIZE) << '+' << '+' << endl;

		cin >> setw(21) >> fileName;
		mStudentManager.saveFile(fileName);

		LAST_REMARK
	}
	void StudentManagerUI::loadStudents()
	{
		char fileName[21];

		cout << left << setfill(' ');
		cout << setw(25) << '+' << setw(64) << "불러올 파일 명을 입력해주세요" << '+' << endl;
		cout << setw(25) << '+' << setw(64) << "불러오기 옵션 [0] 이어 붙이기 [1] 덮어 쓰기" << '+' << endl;
		cout << setfill('-') << setw(TOTAL_SPACE_SIZE) << '+' << '+' << endl;

		cout << "파일 명 :";
		cin >> setw(21) >> fileName;

		cout << "불러오기 옵션 :";
		size_t number = getUserInput();
		while (number >= static_cast<size_t>(eLoadType::COUNT))
		{
			cout << "범위 내의 값을 입력해주세요" << endl;

			cout << "불러오기 옵션 :";
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
		cout << setw(25) << '+' << setw(64) << "랜덤 데이터 10개를 추가합니다" << '+' << endl;
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