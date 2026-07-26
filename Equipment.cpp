#include <iostream>
using namespace std;
#include "Equipment.h"

/*
   char* name;
    char* serialNumber;
    int quantity;
    eEquipmentStatus status;
*/
 
Equipment::Equipment(const char* name,
              const char* serialNumber,
              int quantity,
              eEquipmentStatus status) : quantity(quantity),status(status)
{
    this->name = new char[strlen(name) + 1];
    strcpy(this->name,name);
    this->serialNumber = new char[strlen(serialNumber) + 1];
    strcpy(this->serialNumber,serialNumber);
};

Equipment::Equipment(Equipment&& other) noexcept 
    : name(other.name), serialNumber(other.serialNumber), 
      quantity(other.quantity), status(other.status) 
{
    other.name = nullptr;
    other.serialNumber = nullptr;
    other.quantity = 0;
}

Equipment& Equipment::operator=(Equipment&& other) noexcept {
    if (this != &other) {
        delete[] this->name;
        delete[] this->serialNumber;

        this->name = other.name;
        this->serialNumber = other.serialNumber;
        this->quantity = other.quantity;
        this->status = other.status;

        other.name = nullptr;
        other.serialNumber = nullptr;
        other.quantity = 0;
    }
    return *this;
}

Equipment::~Equipment()
{
    delete[] this->name;    
    delete[] this->serialNumber;
};
const char* Equipment::getName() const
{
    return this->name;
};
const char* Equipment::getSerialNumber() const
{
    return this->serialNumber;
};
int Equipment::getQuantity() const
{
    return this->quantity;
};
Equipment::eEquipmentStatus Equipment::getStatus() const
{
    return this->status;
};
bool Equipment::setName(const char* name)
{
    if (name == nullptr || strlen(name) == 0) {
        return false;
    }
    delete[] this->name;
    
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    return true;
}
bool Equipment::setSerialNumber(const char* serialNumber)
{
    if (serialNumber == nullptr || strlen(serialNumber) == 0) {
        return false;
    }
    
    delete[] this->serialNumber;
    
    this->serialNumber = new char[strlen(serialNumber) + 1];
    strcpy(this->serialNumber, serialNumber);
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
/*
    
    
    

    bool setName(const char* name);
    bool setSerialNumber(const char* serialNumber);
    bool setQuantity(int quantity);
    bool setStatus(eEquipmentStatus status);

    void print() const;
};
*/
