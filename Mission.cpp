#include <iostream>
#include <cstring>
#include "Mission.h"
#include "Unit.h"
using namespace std;

int Mission::s_nextMissionId = 1;

Mission::Mission(const char* missionName, Unit *assignedUnit)
{
    this->missionName = new char[strlen(missionName) + 1];
    strcpy(this->missionName, missionName);
    this->assignedUnit = assignedUnit;
    this->status = Mission::eMissionStatus::NOT_STARTED;
    this->missionId = s_nextMissionId++;
};

Mission::~Mission()
{
    delete[] this->missionName;
};

const char* Mission::getMissionName() const
{
    return this->missionName;
};

int Mission::getMissionId() const
{
    return this->missionId;
};

Mission::eMissionStatus Mission::getStatus() const
{
    return this->status;
};

Unit* Mission::getAssignedUnit() const
{
    return this->assignedUnit;
};

bool Mission::setMissionName(const char* missionName)
{
    if (!missionName)
        return false;

    delete[] this->missionName;
    this->missionName = new char[strlen(missionName) + 1];
    strcpy(this->missionName, missionName);
    return true;
};

bool Mission::setStatus(eMissionStatus newStatus)
{
    this->status = newStatus;
    return true;
};

std::ostream &operator<<(std::ostream &os, const Mission &mission)
{
    os << "Mission Name: " << mission.missionName
       << ", Mission ID: " << mission.missionId
       << ", Status: " << mission.status
       << ", Assigned Unit: " << (mission.assignedUnit ? mission.assignedUnit->getUnitName() : "None");
    return os;
};

// virtual void Mission::print() const = 0;