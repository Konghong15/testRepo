#include "StudentManager.h"

namespace assignment
{
	StudentManager::StudentManager(const StudentManager& rhs)
	{
		for (auto it = rhs.mStudents.begin(); it != rhs.mStudents.end(); ++it)
		{
			mStudents.push_back(new Student(**it));
		}
	}

	StudentManager::~StudentManager()
	{
		for (auto it = mStudents.begin(); it != mStudents.end(); ++it)
		{
			delete* it;
		}
	}

	StudentManager& StudentManager::operator=(const StudentManager& rhs)
	{
		if (this == &rhs)
		{
			return *this;
		}

		for (auto it = mStudents.begin(); it != mStudents.end(); ++it)
		{
			delete* it;
		}
		for (auto it = rhs.mStudents.begin(); it != rhs.mStudents.end(); ++it)
		{
			mStudents.push_back(new Student(**it));
		}

		return *this;
	}

	void StudentManager::addStudent(const Student* student)
	{
		mStudents.push_back(student);
	}

	void StudentManager::addStudent(const Student* student, size_t index)
	{
		auto it = mStudents.begin();
		std::advance(it, index);
		mStudents.insert(it, student);
	}

	bool StudentManager::removeStudent(const char* name)
	{
		for (auto it = mStudents.begin(); it != mStudents.end(); ++it)
		{
			if (strncmp((*it)->mName, name, 4) == 0)
			{
				mStudents.remove(*it);

				return true;
			}
		}

		return false;
	}

	size_t StudentManager::FindIndex(const char* name)
	{
		size_t index = 0;
		for (auto it = mStudents.begin(); it != mStudents.end(); ++it, ++index)
		{
			if (strncmp((*it)->mName, name, 4) == 0)
			{
				return index;
			}
		}

		return -1;
	}

	const Student& StudentManager::operator[](int index)
	{
		auto it = mStudents.begin();
		std::advance(it, index);

		return **it;
	}

	size_t StudentManager::GetStudentCount()
	{
		return mStudents.size();
	}

	void StudentManager::Print(unsigned int index)
	{
		using namespace std;

		std::shared_ptr<Node<Student>> studentNode = mStudents[index];

		if (studentNode == nullptr)
		{
			return;
		}

		const Student student = studentNode->Data.get();
		size_t total = student->mKor + student->mEng + student->mMath;

		cout << setw(10) << student->mName
			<< setw(10) << student->mKor
			<< setw(10) << student->mEng
			<< setw(10) << student->mMath
			<< setw(10) << total / 3 << std::endl;
	}

	void StudentManager::PrintAll()
	{
		using namespace std;

		cout << setw(10) << "name"
			 << setw(10) << "Kor"
			 << setw(10) << "Eng"
			<< setw(10) << "Math"
			 << setw(10) << "Average" << endl;
		for (auto it = mStudents.begin(); it != mStudents.end(); ++it)
		{
			const Student* student = *it;
			size_t total = student->mKor + student->mEng + student->mMath;

			cout << setw(10) << student->mName
				<< setw(10) << student->mKor
				<< setw(10) << student->mEng
				<< setw(10) << student->mMath
				<< setw(10) << total / 3 << std::endl;
		}
	}

	bool StudentManager::SaveFile(const char* fileName)
	{
		std::ofstream fout(fileName, std::ios_base::out | std::ios_base::binary);

		if (!fout.is_open())
		{
			return false;
		}

		size_t size = mStudents.size();
		fout.write(reinterpret_cast<const char*>(&size), sizeof(size_t));

		for (auto it = mStudents.begin(); it != mStudents.end(); ++it)
		{
			const Student* student = *it;
			fout.write(reinterpret_cast<const char*>(student), sizeof(Student));
		}
		fout.flush();

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
			for (auto it = mStudents.begin(); it != mStudents.end(); ++it)
			{
				delete* it;
			}
		}

		for (unsigned int i = 0; i < size; ++i)
		{
			size_t kor;
			size_t eng;
			size_t math;
			size_t average;
			char name[4];

			fin.read(reinterpret_cast<char*>(&kor), sizeof(size_t));
			fin.read(reinterpret_cast<char*>(&eng), sizeof(size_t));
			fin.read(reinterpret_cast<char*>(&math), sizeof(size_t));
			fin.read(reinterpret_cast<char*>(&average), sizeof(size_t));
			fin.read(reinterpret_cast<char*>(name), sizeof(char) * 4);

			mStudents.push_back(new Student(kor, eng, math, name));
		}

		return true;
	}

	void StudentManager::Sort(eSortingType sortingType)
	{
		switch (sortingType)
		{
		case SORTED_KOR:
			mStudents.sort([=](const Student* a, const Student* b) { return a->mKor > b->mKor; });
			break;
		case SORTED_ENG:
			mStudents.sort([=](const Student* a, const Student* b) { return a->mEng > b->mEng; });
			break;
		case SORTED_MATH:
			mStudents.sort([=](const Student* a, const Student* b) { return a->mMath > b->mMath; });
			break;
		case SORTED_AVERAGE:
			mStudents.sort([=](const Student* a, const Student* b) { return a->mAverage > b->mAverage; });
			break;
		default:
			_ASSERT(false);
			break;
		}
	}


}