#include "Heap.h"
#include <iostream>

using namespace std;

Heap::Heap() {
    capacity = 10;
    count = 0;
    arr = new Parcel*[capacity];
}

Heap::~Heap() {
    delete[] arr;
}

bool Heap::hasHigherPriority(Parcel* first, Parcel* second) const {
    if (first->priority > second->priority) {
        return true;
    }

    if (first->priority == second->priority &&
        first->arrivalOrder < second->arrivalOrder) {
        return true;
    }

    return false;
}

void Heap::resize() {
    capacity = capacity * 2;
    Parcel** newArr = new Parcel*[capacity];

    for (int i = 0; i < count; i++) {
        newArr[i] = arr[i];
    }

    delete[] arr;
    arr = newArr;
}

void Heap::heapifyUp(int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;

        if (hasHigherPriority(arr[index], arr[parent])) {
            Parcel* temp = arr[index];
            arr[index] = arr[parent];
            arr[parent] = temp;
            index = parent;
        } else {
            break;
        }
    }
}

void Heap::heapifyDown(int index) {
    while (true) {
        int left = (2 * index) + 1;
        int right = (2 * index) + 2;
        int best = index;

        if (left < count && hasHigherPriority(arr[left], arr[best])) {
            best = left;
        }

        if (right < count && hasHigherPriority(arr[right], arr[best])) {
            best = right;
        }

        if (best == index) {
            break;
        }

        Parcel* temp = arr[index];
        arr[index] = arr[best];
        arr[best] = temp;
        index = best;
    }
}

bool Heap::insert(Parcel* parcel) {
    if (parcel == nullptr) {
        return false;
    }

    if (count == capacity) {
        resize();
    }

    arr[count] = parcel;
    heapifyUp(count);
    count++;

    return true;
}

Parcel* Heap::extractMax() {
    if (empty()) {
        return nullptr;
    }

    Parcel* result = arr[0];
    count--;

    if (count > 0) {
        arr[0] = arr[count];
        heapifyDown(0);
    }

    arr[count] = nullptr;
    return result;
}

Parcel* Heap::peek() const {
    if (empty()) {
        return nullptr;
    }

    return arr[0];
}

bool Heap::empty() const {
    return count == 0;
}

int Heap::size() const {
    return count;
}

bool Heap::contains(Parcel* parcel) const {
    for (int i = 0; i < count; i++) {
        if (arr[i] == parcel) {
            return true;
        }
    }

    return false;
}

bool Heap::remove(Parcel* parcel) {
    int index = -1;

    for (int i = 0; i < count; i++) {
        if (arr[i] == parcel) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        return false;
    }

    count--;

    if (index < count) {
        arr[index] = arr[count];

        if (index > 0 &&
            hasHigherPriority(arr[index], arr[(index - 1) / 2])) {
            heapifyUp(index);
        } else {
            heapifyDown(index);
        }
    }

    arr[count] = nullptr;
    return true;
}

void Heap::display() const {
    if (empty()) {
        cout << "No urgent deliveries pending." << endl;
        return;
    }

    for (int i = 0; i < count; i++) {
        cout << "Tracking ID: " << arr[i]->trackingId
             << " | Priority: " << arr[i]->priority
             << " | Arrival Order: " << arr[i]->arrivalOrder << endl;
    }
}
