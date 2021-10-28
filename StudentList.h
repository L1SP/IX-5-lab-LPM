#pragma once
#include "Student.h"
class StudentList
{
	friend class Group;
	friend class AMM;
	struct Node {
		Student data;
		Node* next;
		Node() : next(nullptr) {};
	};
	Node* head;
	void addToHead(const Student& value);
	void addAfterNode(const Student& value, Node* nn);
public:
	StudentList();
	~StudentList();
};