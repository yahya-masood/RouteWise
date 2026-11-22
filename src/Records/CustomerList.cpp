
#include "CustomerList.h"

using namespace std;

CustomerList::CustomerList() {
    head = NULL;
    tail = NULL;
    count = 0;
}

CustomerList::~CustomerList() {
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    tail = NULL;
    count = 0;
}

bool CustomerList::add(const Customer& customer) {

    Node* newNode = new Node;

    newNode->data = customer;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }

    count++;

    return true;
}
