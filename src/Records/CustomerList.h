
#ifndef CUSTOMERLIST_H
#define CUSTOMERLIST_H

#include "src/Models.h"

class CustomerList {
private:

    struct Node {
        Customer data;
        Node* next;
    };

    Node* head;
    Node* tail;
    int count;

public:

    CustomerList();
    ~CustomerList();

    bool add(const Customer& customer);
    Customer* find(int customerId);
    void display() const;
    int getCount() const;
};

#endif
