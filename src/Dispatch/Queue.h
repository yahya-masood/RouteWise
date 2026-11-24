#ifndef QUEUE_H
#define QUEUE_H

#include "../Models.h"

class Queue {
private:
    struct Node {
        Parcel* parcel;
        Node* next;
    };

    Node* frontNode;
    Node* rearNode;
    int count;

public:
    Queue();
    ~Queue();

    bool enqueue(Parcel* parcel);
    bool enqueueFront(Parcel* parcel);
    Parcel* dequeue();
    Parcel* front() const;
    bool empty() const;
    int size() const;
    bool contains(Parcel* parcel) const;
    void display() const;
};

#endif
