#include <iostream>
#include "Report.h"
using namespace std;

Report::Report(int soldierCount, int unitCount, int vehicleCount, int equipmentCount, int activeMissionCount)
: soldierCount(soldierCount), unitCount(unitCount), vehicleCount(vehicleCount),
 equipmentCount(equipmentCount), activeMissionCount(activeMissionCount){};

 int Report::getSoldierCount() const
 {
     return soldierCount;
 };

int Report::getUnitCount() const
 {
     return unitCount;
 };

int Report::getVehicleCount() const
 {
     return vehicleCount;
 };

int Report::getEquipmentCount() const
 {
     return equipmentCount;
 };

int Report::getActiveMissionCount() const
 {
     return activeMissionCount;
 };

 std::ostream &operator<<(std::ostream &os, const Report &report)
{
    os << "Soldier Count: " << report.soldierCount
    << ", Unit Count: " << report.unitCount
    << ", Vehicle Count: " << report.vehicleCount
    << ", Equipment Count: " << report.equipmentCount
    << ", Active Mission Count: " << report.activeMissionCount;
    return os;
};
