#pragma once
#include "Group.h"
class GroupList
{
	friend class Course;
	friend class AMM;
	struct Node {
		Group data;
		Node* next;
		Node() : next(nullptr) {};
	};
	Node* head;
	void addToHead(const Group& value);
	void addAfterNode(const Group& value, Node* nn);
public:
	GroupList();
	~GroupList();
};