#include "BST.h"

BST::BST() {
    root = NULL;
    nodeCount = 0;
}

BST::~BST() {
    destroy(root);
    root = NULL;
}

void BST::destroy(BSTNode* node) {
    if (node == NULL) {
        return;
    }
    destroy(node->left);
    destroy(node->right);
    delete node;
}

bool BST::insert(Parcel* parcel) {
    if (parcel == NULL) {
        return false;
    }
    if (search(parcel->trackingId) != NULL) {
        return false;
    }

    BSTNode* newNode = new BSTNode;
    newNode->parcel = parcel;
    newNode->left = NULL;
    newNode->right = NULL;

    if (root == NULL) {
        root = newNode;
        nodeCount++;
        return true;
    }

    BSTNode* current = root;
    while (true) {
        if (parcel->trackingId < current->parcel->trackingId) {
            if (current->left == NULL) {
                current->left = newNode;
                break;
            }
            current = current->left;
        } else {
            if (current->right == NULL) {
                current->right = newNode;
                break;
            }
            current = current->right;
        }
    }

    nodeCount++;
    return true;
}

Parcel* BST::search(int trackingId) const {
    BSTNode* current = root;
    while (current != NULL) {
        if (trackingId == current->parcel->trackingId) {
            return current->parcel;
        }
        if (trackingId < current->parcel->trackingId) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return NULL;
}

int BST::searchSteps(int trackingId) const {
    int steps = 0;
    BSTNode* current = root;
    while (current != NULL) {
        steps++;
        if (trackingId == current->parcel->trackingId) {
            return steps;
        }
        if (trackingId < current->parcel->trackingId) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return steps;
}

void BST::displayInOrder(BSTNode* node) const {
    if (node == NULL) {
        return;
    }
    displayInOrder(node->left);
    cout << "Tracking ID: " << node->parcel->trackingId
         << " | Customer: " << node->parcel->customerId
         << " | To: " << node->parcel->destination
         << " | Priority: " << node->parcel->priority << endl;
    displayInOrder(node->right);
}

void BST::display() const {
    if (root == NULL) {
        cout << "BST is empty." << endl;
        return;
    }
    displayInOrder(root);
}

int BST::heightOf(BSTNode* node) const {
    if (node == NULL) {
        return 0;
    }
    int leftHeight = heightOf(node->left);
    int rightHeight = heightOf(node->right);
    if (leftHeight > rightHeight) {
        return leftHeight + 1;
    }
    return rightHeight + 1;
}

int BST::height() const {
    return heightOf(root);
}

int BST::count() const {
    return nodeCount;
}