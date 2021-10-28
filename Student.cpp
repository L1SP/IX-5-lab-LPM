#include <string>
#include <iostream>
#include "Student.h"
Student::Student() {
	fio = "Иванов Иван Иванович";
	feeType = "бюджет";
	marks = new std::pair<subject, mark>[5];
}
Student::Student(std::string& _fio, std::string& _feeType, std::pair<subject, mark>* _marks) {
	fio = _fio;
	feeType = _feeType;
	marks = new std::pair<subject, mark>[5];
	for (int i = 0; i < 5; ++i) {
		marks[i].first = _marks[i].first;
		marks[i].second = _marks[i].second ;
	}
}
Student::~Student() {
	delete[]marks;
}
int Student::getSubjectMark(subject s) {
	for (int i = 0; i < 5; ++i)
		if (marks[i].first == s)
			return (int)marks[i].second;
	return 0;
}
std::ostream& operator<<(std::ostream& os, const Student::subject s) {
	switch (s) {
	case Student::subject::Теорвер:
		os << "Теорвер";
		break;
	case Student::subject::Английский:
		os << "Английский";
		break;
	case Student::subject::Матанализ:
		os << "Матанализ";
		break;
	case Student::subject::ЯМП:
		os << "ЯМП";
		break;
	case Student::subject::ООП:
		os << "ООП";
		break;
	}
	return os;
}
std::ostream& operator<<(std::ostream& os, const Student::mark m) {
	switch (m) {
	case Student::mark::Неудовлетворительно:
		os << "Неудовлетворительно";
		break;
	case Student::mark::Удовлетворительно:
		os << "Удовлетворительно";
		break;
	case Student::mark::Хорошо:
		os << "Хорошо";
		break;
	case Student::mark::Отлично:
		os << "Отлично";
		break;
	}
	return os;
}
