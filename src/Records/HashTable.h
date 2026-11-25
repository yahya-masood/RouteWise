
#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "../Models.h"

class HashTable {

private:

    Parcel** table;
    int capacity;
    int count;

    int hashFunction(int trackingId) const;
    bool resize();

public:

    HashTable(int initialCapacity = 10);
    ~HashTable();

    bool insert(Parcel* parcel);
    Parcel* search(int trackingId) const;

    int getCount() const;
};

#endif
