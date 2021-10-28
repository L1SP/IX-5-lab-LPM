#include "AMM.h"
#include "Course.h"
#include <iostream>
#include <fstream>
#include <utility>
AMM::~AMM() {
	delete []c;
}
void AMM::readFromFile(std::ifstream& rff) {
	bool first = 1;
	std::string fio;
	std::string feetype;
	std::pair<Student::subject, Student::mark> *tmpmarks = new std::pair<Student::subject, Student::mark> [5];
	std::string tmpsubject;
	std::string tmpmark;
	std::string emptyline;
	int course;
	int group;
	std::getline(rff, fio);
	while (!(rff.eof())) {
		if (!first)
			std::getline(rff, fio);
		else
			first = 0;
		rff >> course;
		rff >> group;
		rff >> feetype;
		for (int i = 0; i < 5; ++i) {
			rff >> tmpsubject;
			if (tmpsubject == "�������")
				tmpmarks[i].first = static_cast<Student::subject>(1);
			else if (tmpsubject == "����������")
				tmpmarks[i].first = static_cast<Student::subject>(2);
			else if (tmpsubject == "���������")
				tmpmarks[i].first = static_cast<Student::subject>(3);
			else if (tmpsubject == "���")
				tmpmarks[i].first = static_cast<Student::subject>(4);
			else if (tmpsubject == "���")
				tmpmarks[i].first = static_cast<Student::subject>(5);
			rff >> tmpmark;
			if (tmpmark == "�������������������")
				tmpmarks[i].second = static_cast<Student::mark>(2);
			else if (tmpmark == "�����������������")
				tmpmarks[i].second = static_cast<Student::mark>(3);
			else if (tmpmark == "������")
				tmpmarks[i].second = static_cast<Student::mark>(4);
			else if (tmpmark == "�������")
				tmpmarks[i].second = static_cast<Student::mark>(5);
		}
		std::getline(rff, emptyline).ignore(1,'\n');
		insertStudent(fio, course, group, feetype, tmpmarks);
	}
}
void AMM::printAMMStudents() {
	std::cout << facultyName<<'\n';
	for (int i = 0; i < 5; ++i) {
		if (!(c[i].groups->head))
			std::cout << "�� " << i + 1 << " ����� ����� �� ������.\n";
		else {
			std::cout << i + 1 << " ����:\n";
			c[i].printCourseStudents();
		}
	}
}
void AMM::insertStudent(std::string& _fio, int& _course, int& _group, std::string& _feeType, std::pair<Student::subject, Student::mark>* _marks) {
	Student *s = new Student(_fio, _feeType, _marks);
	GroupList::Node* p = c[_course-1].groups->head;
	StudentList::Node* q;
	bool foundNode = 0;
	if (!p || p->data.groupNumber>_group) {
		GroupList::Node* nn = new GroupList::Node;
		nn->data.groupNumber = _group;
		nn->data.studentCount++;
		c[_course-1].groups->addToHead(nn->data);
		c[_course - 1].groupCount++;
		p = nn;
		foundNode = 1;
	}
	else{
		while (p) {
			if (p->data.groupNumber == _group) {
				foundNode = 1;
				break;
			}
			if (!(p->next) || p->next->data.groupNumber > _group)
				break;
			p = p->next;
		}
	}
	if (!foundNode) {
		GroupList::Node* nn = new GroupList::Node;
		nn->data.groupNumber = _group;
		c[_course-1].groups->addAfterNode(nn->data, p);
		c[_course - 1].groupCount++;
		q = nn->data.students->head;
		p = p->next;
	}
	else
		q = p->data.students->head;
	if (!q || q->data.fio > _fio) {
		p->data.students->addToHead(*s);
		p->data.studentCount++;
	}
	else {
		while (q && q->next && q->data.fio <= q->next->data.fio) {
			q = q->next;
		}
		p->data.students->addAfterNode(*s, q);
		p->data.studentCount++;
	}
}
void AMM::printCourseMediumMark(int& _course, std::string _sub) {
	if (!(c[_course - 1].groups->head)) {
		std::cout << "�� �������� ����� ����� �� ������.\n";
		return;
	}
	Student::subject sub;
	if (_sub == "�������")
		sub = static_cast<Student::subject>(1);
	else if (_sub == "����������")
		sub = static_cast<Student::subject>(2);
	else if (_sub == "���������")
		sub = static_cast<Student::subject>(3);
	else if (_sub == "���")
		sub = static_cast<Student::subject>(4);
	else if (_sub == "���")
		sub = static_cast<Student::subject>(5);
	else {
		std::cout << "��������� �������� ���.\n";
		return;
	}
	std::cout<<"������� ���� �� ��������� �������� �� "<<_course<<" �����: " << c[_course - 1].getCourseMediumMark(sub)<<'\n';
}