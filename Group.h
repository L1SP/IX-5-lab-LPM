#pragma once
#include "StudentList.h"
#include "Student.h"
class Group
{
	friend class AMM;
	friend class Course;
	int studentCount;
	int groupNumber;
	StudentList *students;
public:
	Group();
	~Group();
	double getGroupMediumMark(Student::subject s);
	void printGroupStudents();
};

