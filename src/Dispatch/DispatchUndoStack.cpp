#include "Stack.h"

Stack::Stack() {
    topNode = nullptr;
    count = 0;
}

Stack::~Stack() {
    UndoRecord record;

    while (pop(record)) {
    }
}

bool Stack::push(const UndoRecord& record) {
    Node* newNode = new Node;
    newNode->record = record;
    newNode->next = topNode;
    topNode = newNode;
    count++;

    return true;
}

bool Stack::pop(UndoRecord& record) {
    if (empty()) {
        return false;
    }

    Node* temp = topNode;
    record = temp->record;
    topNode = topNode->next;

    delete temp;
    count--;

    return true;
}

bool Stack::top(UndoRecord& record) const {
    if (empty()) {
        return false;
    }

    record = topNode->record;
    return true;
}

bool Stack::empty() const {
    return topNode == nullptr;
}

int Stack::size() const {
    return count;
}
