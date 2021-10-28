#pragma once
#include <string>
#include <utility>
class Student
{
	friend class Group;
	friend class Course;
	friend class AMM;
	enum class mark: int {
		������������������� = 2,
		����������������� = 3,
		������ = 4,
		������� = 5
	};
	enum class subject: int {
		������� = 1,
		���������� = 2,
		��������� = 3,
		��� = 4,
		��� = 5
	};
	std::string fio;
	std::string feeType;
	std::pair<subject, mark>* marks;
	friend std::ostream& operator<<(std::ostream& os, const subject s);	
	friend std::ostream& operator<<(std::ostream& os, const mark m);
public:
	Student();
	Student(std::string& _fio, std::string& _feeType, std::pair<subject, mark>* _marks);
	~Student();
	int getSubjectMark(subject s);
};

