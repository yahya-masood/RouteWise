
#ifndef RECORDSMODULE_H
#define RECORDSMODULE_H

#include "CustomerList.h"
#include "HashTable.h"

class RecordsModule {

private:

    CustomerList customers;
    HashTable parcelTable;

    Parcel** parcels;
    int parcelCountValue;
    int parcelCapacity;

    bool resizeParcelArray();

public:

    RecordsModule(int initialCapacity = 10);
    ~RecordsModule();

    bool addCustomer(const Customer& customer);
    Parcel* addParcel(const Parcel& parcel);

    Customer* findCustomer(int customerId);
    Parcel* findParcel(int trackingId);

    void displayCustomers() const;
    void displayParcels() const;

    int customerCount() const;
    int parcelCount() const;
};

#endif
