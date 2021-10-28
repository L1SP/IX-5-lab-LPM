#pragma once
#include "Course.h"
#include <string>
#include <utility>
class AMM
{
	Course *c = new Course[5];
	const std::string facultyName;
public:
	AMM(): facultyName("олл") {};
	~AMM();
	void readFromFile(std::ifstream& rff);
	void insertStudent(std::string& _fio, int& _course, int& _group, std::string& _feeType, std::pair<Student::subject, Student::mark>* _marks);
	void printCourseMediumMark(int& _course, std::string _sub);
	void printAMMStudents();
};

