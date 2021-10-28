#include <iostream>
#include <fstream>
#include <Windows.h>
#include <utility>
#include "AMM.h"
using namespace std;
int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	AMM* faculty = new AMM;
	int _course;
	string _subject;
	ifstream rff("Students.txt");
	faculty->readFromFile(rff);
	faculty->printAMMStudents();
	cout << "Введите курс:\n";
	cin >> _course;
	cout << "Введите предмет:\n";
	cin >> _subject;
	faculty->printCourseMediumMark(_course, _subject);
	delete faculty;
	return 0;
}
