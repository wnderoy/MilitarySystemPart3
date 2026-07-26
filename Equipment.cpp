#include <iostream>
#include "Equipment.h"
using namespace std;
/*
part 3
name - char* now string
serialNumber - char* now string


*/
Equipment::Equipment(const string& name,
              const string& serialNumber,
              int quantity,
              eEquipmentStatus status)
    : name(name), serialNumber(serialNumber), quantity(quantity), status(status)
{
}

Equipment::Equipment(Equipment&& other) noexcept 
    : name(std::move(other.name)), serialNumber(std::move(other.serialNumber)), 
      quantity(other.quantity), status(other.status) 
{
    other.quantity = 0;
}

Equipment& Equipment::operator=(Equipment&& other) noexcept {
    if (this != &other) {
        name = std::move(other.name);
        serialNumber = std::move(other.serialNumber);
        quantity = other.quantity;
        status = other.status;
        other.quantity = 0;
    }
    return *this;
}

Equipment::~Equipment()
{
}

const string& Equipment::getName() const
{
    return name;
}

const string& Equipment::getSerialNumber() const
{
    return serialNumber;
}

int Equipment::getQuantity() const
{
    return quantity;
}

Equipment::eEquipmentStatus Equipment::getStatus() const
{
    return status;
}

bool Equipment::setName(const string& name)
{
    if (name.empty()) {
        return false;
    }
    this->name = name;
    return true;
}

bool Equipment::setSerialNumber(const string& serialNumber)
{
    if (serialNumber.empty()) {
        return false;
    }
    this->serialNumber = serialNumber;
    return true;
}

bool Equipment::setQuantity(int quantity)
{
    if (quantity < 0) {
        return false;
    }
    this->quantity = quantity;
    return true;
}

bool Equipment::setStatus(eEquipmentStatus status)
{
    this->status = status;
    return true;
}

std::ostream& operator<<(std::ostream& os, const Equipment& eq) {
    os << "Equipment Name: " << eq.name << "\n"
       << "Serial Number:  " << eq.serialNumber << "\n"
       << "Quantity:       " << eq.quantity << "\n"
       << "Status:         " << (eq.status == Equipment::eEquipmentStatus::WORKING ? "WORKING" : "DAMAGED");
    return os;
}

void Equipment::print() const {
    cout << "Equipment Name: " << this->name << "\n"
         << "Serial Number:  " << this->serialNumber << "\n"
         << "Quantity:       " << this->quantity << "\n"
         << "Status:         " << (this->status == eEquipmentStatus::WORKING ? "WORKING" : "DAMAGED") << endl;
}
