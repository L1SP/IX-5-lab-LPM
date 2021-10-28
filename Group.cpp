#include "Group.h"
#include "StudentList.h"
#include "Student.h"
#include <iostream>
Group::Group() {
	students = new StudentList;
	studentCount = 0;
	groupNumber = 0;
}
Group::~Group() {
	delete students;
}
double Group::getGroupMediumMark(Student::subject s) {
	double ans=0;
	int studentCount=0;
	StudentList::Node* p = students->head;
	while (p) {
		ans += p->data.getSubjectMark(s);
		++studentCount;
		p = p->next;
	}
	return ans/studentCount;
}
void Group::printGroupStudents() {
	StudentList::Node* p = students->head;
	std::cout << "В группе " << studentCount << " студентов.\n";
	while (p) {
		std::cout << "Студент: " << p->data.fio<<'\n';
		std::cout << "Форма обучения: " << p->data.feeType << '\n';
		std::cout << "Оценки за экзамены:\n";
		for (int i = 0; i < 5; ++i)
			std::cout << p->data.marks[i].first << ", " << p->data.marks[i].second<<'\n';
		std::cout << '\n';
		p = p->next;
	}
}
