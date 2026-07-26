#include <iostream>
using namespace std;
#include "BaseFacility.h"
#include "Warehouse.h"
#include "Vehicle.h"

BaseFacility::BaseFacility()
    : vehicleCount(0), vehicleCapacity(10),
      warehouseCount(0), warehouseCapacity(10)
{
    this->vehicles = new Vehicle*[this->vehicleCapacity];
    for (int i = 0; i < this->vehicleCapacity; i++) {
        this->vehicles[i] = nullptr;
    }

    this->warehouses = new Warehouse*[this->warehouseCapacity];
    for (int i = 0; i < this->warehouseCapacity; i++) {
        this->warehouses[i] = nullptr;
    }
}

BaseFacility::~BaseFacility()
{
    for (int i = 0; i < this->vehicleCount; i++) {
        delete this->vehicles[i];
    }
    delete[] this->vehicles;

    for (int i = 0; i < this->warehouseCount; i++) {
        delete this->warehouses[i];
    }
    delete[] this->warehouses;
}

int BaseFacility::getVehicleCount() const
{
    return this->vehicleCount;
}

const Vehicle* BaseFacility::getVehicle(int index) const
{
    if (index < 0 || index >= this->vehicleCount) {
        return nullptr;
    }
    return this->vehicles[index];
}

int BaseFacility::getWarehouseCount() const
{
    return this->warehouseCount;
}

const Warehouse* BaseFacility::getWarehouse(int index) const
{
    if (index < 0 || index >= this->warehouseCount) {
        return nullptr;
    }
    return this->warehouses[index];
}

bool BaseFacility::addVehicle(Vehicle* vehicle)
{
    if (vehicle == nullptr) {
        return false;
    }

    if (this->vehicleCount >= this->vehicleCapacity) {
        int newCapacity = this->vehicleCapacity * 2;
        Vehicle** temp = new Vehicle*[newCapacity];
        for (int i = 0; i < this->vehicleCapacity; i++) {
            temp[i] = this->vehicles[i];
        }
        for (int i = this->vehicleCapacity; i < newCapacity; i++) {
            temp[i] = nullptr;
        }
        delete[] this->vehicles;
        this->vehicles = temp;
        this->vehicleCapacity = newCapacity;
    }

    this->vehicles[this->vehicleCount] = vehicle;
    this->vehicleCount++;
    return true;
}

bool BaseFacility::addWarehouse(Warehouse* warehouse)
{
    if (warehouse == nullptr) {
        return false;
    }

    if (this->warehouseCount >= this->warehouseCapacity) {
        int newCapacity = this->warehouseCapacity * 2;
        Warehouse** temp = new Warehouse*[newCapacity];
        for (int i = 0; i < this->warehouseCapacity; i++) {
            temp[i] = this->warehouses[i];
        }
        for (int i = this->warehouseCapacity; i < newCapacity; i++) {
            temp[i] = nullptr;
        }
        delete[] this->warehouses;
        this->warehouses = temp;
        this->warehouseCapacity = newCapacity;
    }

    this->warehouses[this->warehouseCount] = warehouse;
    this->warehouseCount++;
    return true;
}

bool BaseFacility::addJeep(const char* vehicleNumber, int maxPassengers)
{
    return false; 
}

bool BaseFacility::addTruck(const char* vehicleNumber, double maxWeightKG)
{
    return false;
}

bool BaseFacility::addArmoredTransport(const char* vehicleNumber, int maxPassengers, double maxWeightKG)
{
    return false;
}

const Vehicle* BaseFacility::findVehicle(const char* vehicleNumber) const
{
    if (vehicleNumber == nullptr) {
        return nullptr;
    }
    for (int i = 0; i < this->vehicleCount; i++) {
        if (strcmp(this->vehicles[i]->getVehicleNumber(), vehicleNumber) == 0) {
            return this->vehicles[i];
        }
    }
    return nullptr;
}

const Warehouse* BaseFacility::findWarehouse(const char* name) const
{
    if (name == nullptr) {
        return nullptr;
    }
    for (int i = 0; i < this->warehouseCount; i++) {
        if (strcmp(this->warehouses[i]->getName(), name) == 0) {
            return this->warehouses[i];
        }
    }
    return nullptr;
}

void BaseFacility::printVehicles() const
{
    for (int i = 0; i < this->vehicleCount; i++) {
        cout << *this->vehicles[i];
    }
}

void BaseFacility::printWarehouses() const
{
    for (int i = 0; i < this->warehouseCount; i++) {
        cout << *this->warehouses[i] << "\n";
    }
}

void BaseFacility::print() const
{
    this->printVehicles();
    this->printWarehouses();
} 
/*
#ifndef BASE_FACILITY_H
#define BASE_FACILITY_H

class Vehicle;
class Warehouse;

class BaseFacility {
private:
    Vehicle**   vehicles;
    int         vehicleCount;
    int         vehicleCapacity;

    Warehouse** warehouses;
    int         warehouseCount;
    int         warehouseCapacity;

public:
    BaseFacility();
    ~BaseFacility();

    BaseFacility(const BaseFacility& other) = delete;
    BaseFacility& operator=(const BaseFacility& other) = delete;

    int              getVehicleCount() const;
    const Vehicle*   getVehicle(int index) const;

    int              getWarehouseCount() const;
    const Warehouse* getWarehouse(int index) const;

    bool addVehicle(Vehicle* vehicle);
    bool addWarehouse(Warehouse* warehouse);

    bool addJeep(const char* vehicleNumber, int maxPassengers);
    bool addTruck(const char* vehicleNumber, double maxWeightKG);
    bool addArmoredTransport(const char* vehicleNumber,
                             int maxPassengers,
                             double maxWeightKG);

    const Vehicle*   findVehicle(const char* vehicleNumber) const;
    const Warehouse* findWarehouse(const char* name) const;

    void printVehicles() const;
    void printWarehouses() const;
    void print() const;
};

#endif // BASE_FACILITY_H
*/