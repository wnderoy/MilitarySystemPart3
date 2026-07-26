#ifndef LOGISTICS_MISSION_H
#define LOGISTICS_MISSION_H

#include "Mission.h"
#include <vector>
class Equipment;
//part3: requiredEquipment - Equipment** now vector<Equipment*>
class Vehicle;

class LogisticsMission : public Mission {
private:
    Vehicle* assignedVehicle;

    std::vector<Equipment*> requiredEquipment;

public:
    LogisticsMission(const std::string& missionName, Unit* assignedUnit);
    ~LogisticsMission();

    LogisticsMission(const LogisticsMission& other) = delete;
    LogisticsMission& operator=(const LogisticsMission& other) = delete;

    Vehicle*   getAssignedVehicle() const;
    int        getRequiredEquipmentCount() const;
    Equipment* getRequiredEquipment(int index) const;

    bool setAssignedVehicle(Vehicle* vehicle);

    bool addEquipment(Equipment& equipment);
    bool removeEquipment(const Equipment& equipment);

    friend std::ostream &operator<<(std::ostream &os, const Mission &mission);
};

#endif // LOGISTICS_MISSION_H
