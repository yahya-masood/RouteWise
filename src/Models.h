
#ifndef MODELS_H
#define MODELS_H

#include <string>

namespace routewise {

enum class ParcelStatus {
    Registered,
    Pending,
    InTransit,
    Delivered
};

struct Customer {
    int customerId;
    std::string name;
    std::string phone;
    std::string address;
};

struct Parcel {
    int trackingId;
    int customerId;
    std::string source;
    std::string destination;
    double weight;
    int priority;
    ParcelStatus status;
    int arrivalOrder;
};

}

#endif
