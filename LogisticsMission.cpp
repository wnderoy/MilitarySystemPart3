#include <iostream>
using namespace std;
#include "LogisticsMission.h"
//part3: requiredEquipment - Equipment** now vector<Equipment*>

LogisticsMission::LogisticsMission(const string& missionName, Unit* assignedUnit)
    : Mission(missionName, assignedUnit), assignedVehicle(nullptr)
{
}

LogisticsMission::~LogisticsMission()
{
}

Vehicle* LogisticsMission::getAssignedVehicle() const
{
    return this->assignedVehicle;
}

int LogisticsMission::getRequiredEquipmentCount() const
{
    return this->requiredEquipment.size();
}

Equipment* LogisticsMission::getRequiredEquipment(int index) const
{
    if (index < 0 || index >= (int)this->requiredEquipment.size()) {
        return nullptr;
    }
    return this->requiredEquipment[index];
}

bool LogisticsMission::setAssignedVehicle(Vehicle* vehicle)
{
    this->assignedVehicle = vehicle;
    return true;
}

bool LogisticsMission::addEquipment(Equipment& equipment)
{
    this->requiredEquipment.push_back(&equipment);
    return true;
}

bool LogisticsMission::removeEquipment(const Equipment& equipment)
{
    for (auto it = this->requiredEquipment.begin(); it != this->requiredEquipment.end(); ++it)
    {
        if (*it == &equipment)
        {
            this->requiredEquipment.erase(it);
            return true;
        }
    }
    return false;
}
