#include <iostream>
#include "Mission.h"
#include "Unit.h"
using namespace std;
//part 3: missionName - char* now string

int Mission::s_nextMissionId = 1;

Mission::Mission(const string& missionName, Unit *assignedUnit)
    : missionName(missionName), assignedUnit(assignedUnit)
{
    this->status = Mission::eMissionStatus::NOT_STARTED;
    this->missionId = s_nextMissionId++;
}

Mission::~Mission()
{
}

const string& Mission::getMissionName() const
{
    return this->missionName;
}

int Mission::getMissionId() const
{
    return this->missionId;
}

Mission::eMissionStatus Mission::getStatus() const
{
    return this->status;
}

Unit* Mission::getAssignedUnit() const
{
    return this->assignedUnit;
}

bool Mission::setMissionName(const string& missionName)
{
    if (missionName.empty())
        return false;

    this->missionName = missionName;
    return true;
}

bool Mission::setStatus(eMissionStatus newStatus)
{
    this->status = newStatus;
    return true;
}

std::ostream &operator<<(std::ostream &os, const Mission &mission)
{
    os << "Mission Name: " << mission.missionName
       << ", Mission ID: " << mission.missionId
       << ", Status: " << mission.status
       << ", Assigned Unit: " << (mission.assignedUnit ? mission.assignedUnit->getUnitName() : "None");
    return os;
}
