#pragma once
#include "GroupList.h"
#include "Group.h"
#include "Student.h"
class Course
{
	friend class AMM;
	int groupCount;
	GroupList* groups;
public:
	Course();
	~Course();
	double getCourseMediumMark(Student::subject s);
	void printCourseStudents();
};

