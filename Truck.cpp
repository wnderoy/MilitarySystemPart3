#include <iostream>
#include "Truck.h"
#include "Equipment.h"

using namespace std;
/*
part 3:
loadedEquipment - Equipment* static now vector<Equipment*>
loadedCapacity - deleted
loadedCount - deleted

*/
Truck::Truck(const string& vehicleNumber, double maxWeightKG)
    : Vehicle(vehicleNumber), maxWeightKG(maxWeightKG)
{
}

Truck::~Truck()
{
}

int Truck::getLoadedCount() const
{
    return this->loadedEquipment.size();
}

Equipment* Truck::getLoadedEquipment(int index) const
{
    if (index < 0 || index >= (int)this->loadedEquipment.size()) {
        return nullptr;
    }
    return this->loadedEquipment[index];
}

double Truck::getMaxWeightKG() const
{
    return this->maxWeightKG;
}

bool Truck::setMaxWeightKG(double maxWeightKG)
{
    if (maxWeightKG < 0) {
        return false;
    }
    this->maxWeightKG = maxWeightKG;
    return true;
}

bool Truck::loadEquipment(Equipment& equipment)
{
    this->loadedEquipment.push_back(&equipment);
    return true;
}

bool Truck::unloadEquipment(const Equipment& equipment)
{
    for (auto it = this->loadedEquipment.begin(); it != this->loadedEquipment.end(); ++it)
    {
        if (*it == &equipment)
        {
            this->loadedEquipment.erase(it);
            return true;
        }
    }
    return false;
}
