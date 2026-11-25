
#include "HashTable.h"

HashTable::HashTable(int initialCapacity) {

    if (initialCapacity <= 0) {
        initialCapacity = 10;
    }

    capacity = initialCapacity;
    count = 0;

    table = new Parcel*[capacity];

    for (int i = 0; i < capacity; i++) {
        table[i] = NULL;
    }
}

HashTable::~HashTable() {

    delete[] table;

    table = NULL;
    capacity = 0;
    count = 0;
}

int HashTable::hashFunction(int trackingId) const {

    return trackingId % capacity;
}
