
#include "CustomerList.h"
#include <iostream>
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
Customer* CustomerList::find(int customerId) {

    Node* temp = head;

    while (temp != NULL) {

        if (temp->data.customerId == customerId) {
            return &(temp->data);
        }

        temp = temp->next;
    }

    return NULL;
}

void CustomerList::display() const {

    Node* temp = head;

    if (head == NULL) {
        cout << "No customers found." << endl;
        return;
    }

    while (temp != NULL) {

        cout << "Customer ID: " << temp->data.customerId << endl;
        cout << "Name: " << temp->data.name << endl;
        cout << "Phone: " << temp->data.phone << endl;
        cout << "Address: " << temp->data.address << endl;


        temp = temp->next;
    }
}