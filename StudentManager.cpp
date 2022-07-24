#include "StudentManager.h"

#include <fstream>
#include <iostream>
#include <iomanip>
#include <memory>
#include <string>

namespace studentManager
{
	std::ostream& operator<<(std::ostream& out, const StudentManager& rhs)
	{
		using namespace std;

		out << right << setfill(' ');
		out << setw(12) << "번호"
			<< setw(13) << "Name"
			<< setw(13) << "Korean"
			<< setw(13) << "English"
			<< setw(13) << "Math"
			<< setw(13) << "Total"
			<< setw(13) << "Average" << endl;

		std::shared_ptr<Node<Student>> begin = rhs.mStudents.GetBegin();
		std::shared_ptr<Node<Student>> end = rhs.mStudents.GetEnd();
		std::shared_ptr<Node<Student>> cur = begin->Next;

		size_t index = 0;
		while (cur != end)
		{
			out << setw(12) << index++ << cur->Data;
			cur = cur->Next;
		}

		return out;

	}
	void StudentManager::Search(const char name[4])
	{
		using namespace std;

		std::shared_ptr<Node<Student>> begin = mStudents.GetBegin();
		std::shared_ptr<Node<Student>> end = mStudents.GetEnd();
		std::shared_ptr<Node<Student>> cur = begin->Next;

		cout << right << setfill(' ');
		cout << setw(12) << "번호"
			<< setw(13) << "Name"
			<< setw(13) << "Korean"
			<< setw(13) << "English"
			<< setw(13) << "Math"
			<< setw(13) << "Total"
			<< setw(13) << "Average" << endl;

		bool isFind = false;
		size_t index = 0;
		while (cur != end)
		{
			if (strncmp((cur->Data).mName, name, 4) == 0)
			{
				cout << std::setw(12) << index++ << cur->Data;
				isFind = true;
			}
			cur = cur->Next;
		}

		if (!isFind)
		{
			cout << "일치하는 학생이 없습니다" << std::endl;
		}
	}

	void StudentManager::Push(Student student)
	{
		mStudents.PushBack(student);
	}

	void StudentManager::Push(size_t index, Student student)
	{
		mStudents.PushBack(index, student);
	}

	void StudentManager::Remove(size_t index)
	{
		mStudents.RemoveBack(index);
	}

	void StudentManager::finalize()
	{
		mStudents.Clear();
	}
	
	void StudentManager::Sort(eSortingType sortingType)
	{
		std::shared_ptr<Node<Student>> begin = mStudents.GetBegin();
		std::shared_ptr<Node<Student>> end = mStudents.GetEnd();
		std::shared_ptr<Node<Student>> cur = begin->Next;
		std::shared_ptr<Node<Student>> tempCur;

		while (cur != end)
		{
			Student* selectStudent = &(cur->Data);

			tempCur = cur->Next;
			while (tempCur != end)
			{
				Student* curStudent = &(tempCur->Data);

				switch (sortingType)
				{
				case eSortingType::ASC_AVERAGE:
					selectStudent = selectStudent->GetAverage() > curStudent->GetAverage() ? curStudent : selectStudent;
					break;
				case eSortingType::ASC_KOR:
					selectStudent = selectStudent->mKorean > curStudent->mKorean ? curStudent : selectStudent;
					break;
				case eSortingType::ASC_ENG:
					selectStudent = selectStudent->mEnglish > curStudent->mEnglish ? curStudent : selectStudent;
					break;
				case eSortingType::ASC_MATH:
					selectStudent = selectStudent->mMath > curStudent->mMath ? curStudent : selectStudent;
					break;
				case eSortingType::DESC_AVERAGE:
					selectStudent = selectStudent->GetAverage() < curStudent->GetAverage() ? curStudent : selectStudent;
					break;
				case eSortingType::DESC_KOR:
					selectStudent = selectStudent->mKorean < curStudent->mKorean ? curStudent : selectStudent;
					break;
				case eSortingType::DESC_ENG:
					selectStudent = selectStudent->mEnglish < curStudent->mEnglish ? curStudent : selectStudent;
					break;
				case eSortingType::DESC_MATH:
					selectStudent = selectStudent->mMath < curStudent->mMath ? curStudent : selectStudent;
					break;
				default:
					_ASSERT(false);
					break;
				}
				tempCur = tempCur->Next;
			}

			Student temp = cur->Data;
			cur->Data = *selectStudent;
			*selectStudent = temp;

			cur = cur->Next;
		}
	}

	bool StudentManager::saveFile(const char* fileName)
	{
		std::ofstream fout(fileName, std::ios_base::out | std::ios_base::binary);

		if (!fout.is_open())
		{
			return false;
		}

		std::shared_ptr<Node<Student>> begin = mStudents.GetBegin();
		std::shared_ptr<Node<Student>> end = mStudents.GetEnd();
		std::shared_ptr<Node<Student>> cur = begin->Next;

		while (cur != end)
		{
			Student student = cur->Data;
			fout.write(reinterpret_cast<char*>(&student), sizeof(Student));

			cur = cur->Next;
		}

		fout.flush();
		fout.close();

		return true;
	}

	bool StudentManager::LoadFile(const char* fileName, eLoadType loadType)
	{
		std::ifstream fin(fileName, std::ios_base::in | std::ios_base::binary);

		if (!fin.is_open())
		{
			return false;
		}

		if (loadType == eLoadType::LOAD_OVERWRITE)
		{
			mStudents.Clear();
		}

		fin.seekg(0, std::ios_base::end);
		size_t count = fin.tellg() / sizeof(Student);

		fin.seekg(0, std::ios_base::beg);
		for (unsigned int i = 0; i < count; ++i)
		{
			Student student;

			fin.read(reinterpret_cast<char*>(&(student)), sizeof(Student));

			mStudents.PushBack(student);
		}

		return true;
	}

	size_t StudentManager::GetStudentCount()
	{
		return mStudents.GetSize();
	}
}