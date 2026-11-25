#ifndef HISTORYLIST_H
#define HISTORYLIST_H

#include "../Models.h"

class HistoryList {
private:
    struct Node {
        Parcel* parcel;
        Node* next;
    };

    Node* head;
    Node* tail;
    int count;

public:
    HistoryList();
    ~HistoryList();

    bool add(Parcel* parcel);
    bool removeLast();
    bool removeByParcel(Parcel* parcel);
    bool empty() const;
    int size() const;
    void display() const;
};

#endif
