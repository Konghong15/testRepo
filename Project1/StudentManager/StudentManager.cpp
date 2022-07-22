#include "StudentManager.h"

#include <memory>
#include <string>

namespace studentManager
{
	std::ostream& operator<<(std::ostream& out, const StudentManager& rhs)
	{
		using namespace std;

		out << setw(10) << "Name"
			<< setw(10) << "Korean"
			<< setw(10) << "English"
			<< setw(10) << "Math"
			<< setw(10) << "Total"
			<< setw(10) << "Average" << endl;

		std::shared_ptr<Node<Student>> begin = rhs.mStudents.GetBegin();
		std::shared_ptr<Node<Student>> end = rhs.mStudents.GetEnd();
		std::shared_ptr<Node<Student>> cur = begin->Next;
		
		while (cur != end)
		{
			out << cur->Data;
			cur = cur->Next;
		}

		return out;
	}

	void StudentManager::Push(Student student)
	{
		mStudents.PushBack(student);
	}

	void StudentManager::Push(size_t index, Student student)
	{
		mStudents.PushBack(index, student);
	}

	void StudentManager::Pop(size_t index)
	{
		mStudents.RemoveBack(index);
	}

	void StudentManager::finalize()
	{
		mStudents.Clear();
	}

	void StudentManager::SortAverage()
	{
		std::shared_ptr<Node<Student>> begin = mStudents.GetBegin();
		std::shared_ptr<Node<Student>> end = mStudents.GetEnd();
		std::shared_ptr<Node<Student>> cur = begin->Next;
		std::shared_ptr<Node<Student>> tempCur;

		while (cur != end)
		{
			Student* minAverageStudent = &(cur->Data);
			
			tempCur = begin->Next;
			while (tempCur != end)
			{
				Student* curStudent = &(tempCur->Data);

				if (minAverageStudent->GetAverage() > curStudent->GetAverage())
				{
					minAverageStudent = curStudent;
				}
			}

			Student temp = cur->Data;
			cur->Data = *minAverageStudent;
			*minAverageStudent = temp;

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

		size_t size;
		fin.read(reinterpret_cast<char*>(&size), sizeof(size_t));

		if (loadType == LOAD_OVERWRITE)
		{
			mStudents.Clear();
		}

		fin.seekg(0, std::ios_base::end);
		size_t count = fin.tellg() / sizeof(Student);

		fin.seekg(0, std::ios_base::beg);
		for (unsigned int i = 0; i < count; ++i)
		{
			Student student;

			fin.read(reinterpret_cast<char*>(&(student.mKorean)), sizeof(Student));
			fin.read(reinterpret_cast<char*>(&(student.mEnglish)), sizeof(Student));
			fin.read(reinterpret_cast<char*>(&(student.mMath)), sizeof(Student));
			fin.read(reinterpret_cast<char*>(&(student.mName)), sizeof(char) * 4);

			mStudents.PushBack(student);
		}

		return true;
	}

	size_t StudentManager::GetStudentCount()
	{
		return mStudents.GetSize();
	}
}