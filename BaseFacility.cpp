#include <iostream>
#include <cstring>
#include "BaseFacility.h"
#include "Warehouse.h"
#include "Vehicle.h"
#include "Jeep.h"
#include "Truck.h"
#include "ArmoredTransport.h"

using namespace std;
/*
part 3:
vehicles - Vehicle** is now vector<Vehicle*> 
warehouses - Warehouse** is now a vector<Warehouse*> 
*/
BaseFacility::BaseFacility()
{
}

BaseFacility::~BaseFacility()
{
    for (size_t i = 0; i < vehicles.size(); i++) {
        delete vehicles[i];
    }
    for (size_t i = 0; i < warehouses.size(); i++) {
        delete warehouses[i];
    }
}

int BaseFacility::getVehicleCount() const
{
    return vehicles.size();
}

const Vehicle* BaseFacility::getVehicle(int index) const
{
    if (index < 0 || index >= (int)vehicles.size()) {
        return nullptr;
    }
    return vehicles[index];
}

int BaseFacility::getWarehouseCount() const
{
    return warehouses.size();
}

const Warehouse* BaseFacility::getWarehouse(int index) const
{
    if (index < 0 || index >= (int)warehouses.size()) {
        return nullptr;
    }
    return warehouses[index];
}

bool BaseFacility::addVehicle(Vehicle* vehicle)
{
    if (vehicle == nullptr) {
        return false;
    }
    vehicles.push_back(vehicle);
    return true;
}

bool BaseFacility::addWarehouse(Warehouse* warehouse)
{
    if (warehouse == nullptr) {
        return false;
    }
    warehouses.push_back(warehouse);
    return true;
}

bool BaseFacility::addJeep(const string& vehicleNumber, int maxPassengers)
{
    return addVehicle(new Jeep(vehicleNumber, maxPassengers));
}

bool BaseFacility::addTruck(const string& vehicleNumber, double maxWeightKG)
{
    return addVehicle(new Truck(vehicleNumber, maxWeightKG));
}

bool BaseFacility::addArmoredTransport(const string& vehicleNumber, int maxPassengers, double maxWeightKG)
{
    return addVehicle(new ArmoredTransport(vehicleNumber, maxPassengers, maxWeightKG));
}

const Vehicle* BaseFacility::findVehicle(const string& vehicleNumber) const
{
    for (size_t i = 0; i < vehicles.size(); i++) {
        if (vehicles[i]->getVehicleNumber() == vehicleNumber) {
            return vehicles[i];
        }
    }
    return nullptr;
}

const Warehouse* BaseFacility::findWarehouse(const string& name) const
{
    for (size_t i = 0; i < warehouses.size(); i++) {
        if (warehouses[i]->getName() == name) {
            return warehouses[i];
        }
    }
    return nullptr;
}

void BaseFacility::printVehicles() const
{
    for (size_t i = 0; i < vehicles.size(); i++) {
        cout << *vehicles[i];
    }
}

void BaseFacility::printWarehouses() const
{
    for (size_t i = 0; i < warehouses.size(); i++) {
        cout << *warehouses[i] << "\n";
    }
}

void BaseFacility::print() const
{
    this->printVehicles();
    this->printWarehouses();
}
