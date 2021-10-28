#include "StudentList.h"
StudentList::StudentList() {
    head = nullptr;
}
StudentList::~StudentList() {
    Node* p = head;
    while (p) {
        head = head->next;
        delete p;
        p = head;
    }
}
void StudentList::addToHead(const Student& value) {
    Node* p = new Node;
    p->data = value;
    p->next = head;
    head = p;
}
void StudentList::addAfterNode(const Student& value, Node* nn) {
    if (nn != nullptr) {
        Node* p = new Node;
        p->data = value;
        p->next = nn->next;
        nn->next = p;
    }
}