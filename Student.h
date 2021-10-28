#pragma once
#include <string>
#include <utility>
class Student
{
	friend class Group;
	friend class Course;
	friend class AMM;
	enum class mark: int {
		Неудовлетворительно = 2,
		Удовлетворительно = 3,
		Хорошо = 4,
		Отлично = 5
	};
	enum class subject: int {
		Теорвер = 1,
		Английский = 2,
		Матанализ = 3,
		ЯМП = 4,
		ООП = 5
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

