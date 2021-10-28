#include "Course.h"
#include "GroupList.h"
#include <iostream>
Course::Course() {
	groups = new GroupList;
	groupCount = 0;
}
Course::~Course() {
	delete groups;
}
double Course::getCourseMediumMark(Student::subject s) {
	double ans = 0;
	int groupCount = 0;
	GroupList::Node* p = groups->head;
	while (p) {
		ans += p->data.getGroupMediumMark(s);
		++groupCount;
		p = p->next;
	}
	return ans / groupCount;
}
void Course::printCourseStudents() {
	GroupList::Node* p = groups->head;
	std::cout << "На курсе " << groupCount << " группы.\n";
	while (p) {
		std::cout << p->data.groupNumber << " группа:\n";
		p->data.printGroupStudents();
		p = p->next;
	}
}
