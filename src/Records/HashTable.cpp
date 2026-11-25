
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

bool HashTable::resize() {

    int newCapacity = capacity * 2;

    Parcel** newTable = new Parcel*[newCapacity];

    for (int i = 0; i < newCapacity; i++) {
        newTable[i] = NULL;
    }

    for (int i = 0; i < capacity; i++) {

        if (table[i] != NULL) {

            int index = table[i]->trackingId % newCapacity;

            while (newTable[index] != NULL) {
                index = (index + 1) % newCapacity;
            }

            newTable[index] = table[i];
        }
    }

    delete[] table;

    table = newTable;
    capacity = newCapacity;

    return true;
}

bool HashTable::insert(Parcel* parcel) {

    if (parcel == NULL) {
        return false;
    }

    if (search(parcel->trackingId) != NULL) {
        return false;
    }

    if ((count + 1) * 10 >= capacity * 7) {
        resize();
    }

    int index = hashFunction(parcel->trackingId);

    while (table[index] != NULL) {
        index = (index + 1) % capacity;
    }

    table[index] = parcel;

    count++;

    return true;
}

