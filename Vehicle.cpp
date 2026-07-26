#include <iostream>
#include "Vehicle.h"
using namespace std;

Vehicle::Vehicle(const string &vehicleNumber)
    : vehicleNumber(vehicleNumber), available(true), needsMaintenance(false), driver(nullptr)
{
}

Vehicle::~Vehicle()
{
}

bool Vehicle::setVehicleNumber(const string& vehicleNumber)
{
    if (vehicleNumber.empty())
    {
        return false;
    }
    this->vehicleNumber = vehicleNumber;
    return true;
}

const string &Vehicle::getVehicleNumber() const
{
    return vehicleNumber;
}

bool Vehicle::getAvailable() const
{
    return available;
}

bool Vehicle::getNeedsMaintenance() const
{
    return needsMaintenance;
}

Soldier *Vehicle::getDriver() const
{
    return driver;
}

bool Vehicle::setAvailability(bool status)
{
    available = status;
    return true;
}

bool Vehicle::sendToMaintenance()
{
    needsMaintenance = true;
    return true;
}

bool Vehicle::setDriver(Soldier *driver)
{
    this->driver = driver;
    return true;
}

std::ostream &operator<<(std::ostream &os, const Vehicle &Vehicle)
    {
        os << "Vehicle Number: " << Vehicle.vehicleNumber
           << " ,Available: " << (Vehicle.available ? "Yes" : "No")
           << " ,Needs Maintenance: " << (Vehicle.needsMaintenance ? "Yes" : "No")
           << " ,Driver: " << (Vehicle.driver ? "Assigned" : "None");
        return os;
    }
