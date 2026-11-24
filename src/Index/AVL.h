#ifndef AVL_H
#define AVL_H

#include <iostream>
#include "../Models.h"

using namespace std;

struct AVLNode {
    Parcel* parcel;
    AVLNode* left;
    AVLNode* right;
    int height;
};

class AVL {
private:
    AVLNode* root;
    int nodeCount;

    void destroy(AVLNode* node);
    int heightOf(AVLNode* node) const;
    int balanceFactor(AVLNode* node) const;
    AVLNode* rotateRight(AVLNode* y);
    AVLNode* rotateLeft(AVLNode* x);
    AVLNode* insertNode(AVLNode* node, Parcel* parcel);
    void displayInOrder(AVLNode* node) const;

public:
    AVL();
    ~AVL();

    bool insert(Parcel* parcel);
    Parcel* search(int trackingId) const;
    int searchSteps(int trackingId) const;
    void display() const;
    int height() const;
    int count() const;
};

#endif