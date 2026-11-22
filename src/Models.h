
#ifndef MODELS_H
#define MODELS_H

#include <string>

using namespace std;

enum ParcelStatus {
    Registered,
    Pending,
    InTransit,
    Delivered
};

struct Customer {
    int customerId;
    string name;
    string phone;
    string address;
};

struct Parcel {
    int trackingId;
    int customerId;
    string source;
    string destination;
    double weight;
    int priority;
    ParcelStatus status;
    int arrivalOrder;
};
#endif
