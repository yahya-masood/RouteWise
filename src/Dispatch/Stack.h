#ifndef STACK_H
#define STACK_H

#include "../Models.h"

struct UndoRecord {
    Parcel* parcel;
    ParcelStatus previousStatus;
    int operationType;
    bool wasUrgent;
};

class Stack {
private:
    struct Node {
        UndoRecord record;
        Node* next;
    };

    Node* topNode;
    int count;

public:
    Stack();
    ~Stack();

    bool push(const UndoRecord& record);
    bool pop(UndoRecord& record);
    bool top(UndoRecord& record) const;
    bool empty() const;
    int size() const;
};

#endif
