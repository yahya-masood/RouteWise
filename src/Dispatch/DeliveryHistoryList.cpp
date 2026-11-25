#include "History.h"
#include <iostream>

using namespace std;

HistoryList::HistoryList() {
    head = nullptr;
    tail = nullptr;
    count = 0;
}

HistoryList::~HistoryList() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    tail = nullptr;
    count = 0;
}

bool HistoryList::add(Parcel* parcel) {
    if (parcel == nullptr) {
        return false;
    }

    Node* newNode = new Node;
    newNode->parcel = parcel;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }

    count++;
    return true;
}

bool HistoryList::removeLast() {
    if (head == nullptr) {
        return false;
    }

    if (head == tail) {
        delete head;
        head = nullptr;
        tail = nullptr;
        count--;
        return true;
    }

    Node* current = head;

    while (current->next != tail) {
        current = current->next;
    }

    delete tail;
    tail = current;
    tail->next = nullptr;
    count--;

    return true;
}

bool HistoryList::removeByParcel(Parcel* parcel) {
    if (parcel == nullptr || head == nullptr) {
        return false;
    }

    Node* current = head;
    Node* previous = nullptr;

    while (current != nullptr) {
        if (current->parcel == parcel) {
            if (previous == nullptr) {
                head = current->next;
            } else {
                previous->next = current->next;
            }

            if (current == tail) {
                tail = previous;
            }

            delete current;
            count--;

            if (head == nullptr) {
                tail = nullptr;
            }

            return true;
        }

        previous = current;
        current = current->next;
    }

    return false;
}

bool HistoryList::empty() const {
    return head == nullptr;
}

int HistoryList::size() const {
    return count;
}

void HistoryList::display() const {
    if (empty()) {
        cout << "No completed deliveries in history." << endl;
        return;
    }

    Node* current = head;

    while (current != nullptr) {
        cout << "Tracking ID: " << current->parcel->trackingId
             << " | Destination: " << current->parcel->destination
             << " | Status: Delivered" << endl;
        current = current->next;
    }
}
