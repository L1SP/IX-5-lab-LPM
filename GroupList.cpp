#include "GroupList.h"
GroupList::GroupList() {
    head = nullptr;
}
GroupList::~GroupList() {
    Node* p = head;
    while (p) {
        head = head->next;
        delete p;
        p = head;
    }
}
void GroupList::addToHead(const Group& value) {
    Node* p = new Node;
    p->data = value;
    p->next = head;
    head = p;
}
void GroupList::addAfterNode(const Group& value, Node* nn) {
    if (nn != nullptr) {
        Node* p = new Node;
        p->data = value;
        p->next = nn->next;
        nn->next = p;
    }
}