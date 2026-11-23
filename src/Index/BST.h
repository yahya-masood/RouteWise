#ifndef BST_H
#define BST_H

#include <iostream>
#include "../Models.h"

using namespace std;

struct BSTNode {
    Parcel* parcel;
    BSTNode* left;
    BSTNode* right;
};

class BST {
private:
    BSTNode* root;
    int nodeCount;

    void destroy(BSTNode* node);
    void displayInOrder(BSTNode* node) const;
    int heightOf(BSTNode* node) const;

public:
    BST();
    ~BST();

    bool insert(Parcel* parcel);
    Parcel* search(int trackingId) const;
    int searchSteps(int trackingId) const;
    void display() const;
    int height() const;
    int count() const;
};

#endif