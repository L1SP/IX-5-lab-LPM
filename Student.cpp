#include <string>
#include <iostream>
#include "Student.h"
Student::Student() {
	fio = "������ ���� ��������";
	feeType = "������";
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
	case Student::subject::�������:
		os << "�������";
		break;
	case Student::subject::����������:
		os << "����������";
		break;
	case Student::subject::���������:
		os << "���������";
		break;
	case Student::subject::���:
		os << "���";
		break;
	case Student::subject::���:
		os << "���";
		break;
	}
	return os;
}
std::ostream& operator<<(std::ostream& os, const Student::mark m) {
	switch (m) {
	case Student::mark::�������������������:
		os << "�������������������";
		break;
	case Student::mark::�����������������:
		os << "�����������������";
		break;
	case Student::mark::������:
		os << "������";
		break;
	case Student::mark::�������:
		os << "�������";
		break;
	}
	return os;
}