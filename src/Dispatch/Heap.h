#ifndef HEAP_H
#define HEAP_H

#include "../Models.h"

class Heap {
private:
    Parcel** arr;
    int capacity;
    int count;

    bool hasHigherPriority(Parcel* first, Parcel* second) const;
    void heapifyUp(int index);
    void heapifyDown(int index);
    void resize();

public:
    Heap();
    ~Heap();

    bool insert(Parcel* parcel);
    Parcel* extractMax();
    Parcel* peek() const;
    bool empty() const;
    int size() const;
    bool contains(Parcel* parcel) const;
    bool remove(Parcel* parcel);
    void display() const;
};

#endif
