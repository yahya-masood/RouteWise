#include "AVL.h"

AVL::AVL() {
    root = NULL;
    nodeCount = 0;
}

AVL::~AVL() {
    destroy(root);
    root = NULL;
}

void AVL::destroy(AVLNode* node) {
    if (node == NULL) {
        return;
    }
    destroy(node->left);
    destroy(node->right);
    delete node;
}

int AVL::heightOf(AVLNode* node) const {
    if (node == NULL) {
        return 0;
    }
    return node->height;
}

int AVL::balanceFactor(AVLNode* node) const {
    if (node == NULL) {
        return 0;
    }
    return heightOf(node->left) - heightOf(node->right);
}

AVLNode* AVL::rotateRight(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* middle = x->right;

    x->right = y;
    y->left = middle;

    int yLeft = heightOf(y->left);
    int yRight = heightOf(y->right);
    y->height = (yLeft > yRight ? yLeft : yRight) + 1;

    int xLeft = heightOf(x->left);
    int xRight = heightOf(x->right);
    x->height = (xLeft > xRight ? xLeft : xRight) + 1;

    return x;
}

AVLNode* AVL::rotateLeft(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* middle = y->left;

    y->left = x;
    x->right = middle;

    int xLeft = heightOf(x->left);
    int xRight = heightOf(x->right);
    x->height = (xLeft > xRight ? xLeft : xRight) + 1;

    int yLeft = heightOf(y->left);
    int yRight = heightOf(y->right);
    y->height = (yLeft > yRight ? yLeft : yRight) + 1;

    return y;
}

AVLNode* AVL::insertNode(AVLNode* node, Parcel* parcel) {
    if (node == NULL) {
        AVLNode* newNode = new AVLNode;
        newNode->parcel = parcel;
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->height = 1;
        return newNode;
    }

    if (parcel->trackingId < node->parcel->trackingId) {
        node->left = insertNode(node->left, parcel);
    } else {
        node->right = insertNode(node->right, parcel);
    }

    int leftHeight = heightOf(node->left);
    int rightHeight = heightOf(node->right);
    node->height = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;

    int balance = balanceFactor(node);

    if (balance > 1 && parcel->trackingId < node->left->parcel->trackingId) {
        return rotateRight(node);
    }

    if (balance < -1 && parcel->trackingId > node->right->parcel->trackingId) {
        return rotateLeft(node);
    }

    if (balance > 1 && parcel->trackingId > node->left->parcel->trackingId) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    if (balance < -1 && parcel->trackingId < node->right->parcel->trackingId) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

bool AVL::insert(Parcel* parcel) {
    if (parcel == NULL) {
        return false;
    }
    if (search(parcel->trackingId) != NULL) {
        return false;
    }
    root = insertNode(root, parcel);
    nodeCount++;
    return true;
}

Parcel* AVL::search(int trackingId) const {
    AVLNode* current = root;
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

int AVL::searchSteps(int trackingId) const {
    int steps = 0;
    AVLNode* current = root;
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

void AVL::displayInOrder(AVLNode* node) const {
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

void AVL::display() const {
    if (root == NULL) {
        cout << "AVL is empty." << endl;
        return;
    }
    displayInOrder(root);
}

int AVL::height() const {
    return heightOf(root);
}

int AVL::count() const {
    return nodeCount;
}