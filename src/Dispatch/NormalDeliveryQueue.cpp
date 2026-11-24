#include "Queue.h"
#include <iostream>

using namespace std;

Queue::Queue() {
    frontNode = nullptr;
    rearNode = nullptr;
    count = 0;
}

Queue::~Queue() {
    while (!empty()) {
        dequeue();
    }
}

bool Queue::enqueue(Parcel* parcel) {
    if (parcel == nullptr) {
        return false;
    }

    Node* newNode = new Node;
    newNode->parcel = parcel;
    newNode->next = nullptr;

    if (empty()) {
        frontNode = newNode;
        rearNode = newNode;
    } else {
        rearNode->next = newNode;
        rearNode = newNode;
    }

    count++;
    return true;
}

bool Queue::enqueueFront(Parcel* parcel) {
    if (parcel == nullptr) {
        return false;
    }

    Node* newNode = new Node;
    newNode->parcel = parcel;
    newNode->next = frontNode;
    frontNode = newNode;

    if (rearNode == nullptr) {
        rearNode = newNode;
    }

    count++;
    return true;
}

Parcel* Queue::dequeue() {
    if (empty()) {
        return nullptr;
    }

    Node* temp = frontNode;
    Parcel* parcel = temp->parcel;
    frontNode = frontNode->next;

    if (frontNode == nullptr) {
        rearNode = nullptr;
    }

    delete temp;
    count--;
    return parcel;
}

Parcel* Queue::front() const {
    if (empty()) {
        return nullptr;
    }

    return frontNode->parcel;
}

bool Queue::empty() const {
    return frontNode == nullptr;
}

int Queue::size() const {
    return count;
}

bool Queue::contains(Parcel* parcel) const {
    Node* current = frontNode;

    while (current != nullptr) {
        if (current->parcel == parcel) {
            return true;
        }
        current = current->next;
    }

    return false;
}

void Queue::display() const {
    if (empty()) {
        cout << "No normal deliveries pending." << endl;
        return;
    }

    Node* current = frontNode;

    while (current != nullptr) {
        cout << "Tracking ID: " << current->parcel->trackingId << endl;
        current = current->next;
    }
}
