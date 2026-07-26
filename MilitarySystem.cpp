#include <iostream>
using namespace std;
#include "MilitarySystem.h"
#include "BaseFacility.h"
#include "Soldier.h"
#include "Officer.h"
#include "Unit.h"
#include "Mission.h"
#include "TrainingMission.h"
#include "LogisticsMission.h"
#include "Warehouse.h"
#include "Vehicle.h"
#include "Equipment.h"
#include "Report.h"

MilitarySystem::MilitarySystem()
{
}

MilitarySystem::~MilitarySystem()
{
    for (size_t i = 0; i < soldiers.size(); i++) {
        delete soldiers[i];
    }
    for (size_t i = 0; i < units.size(); i++) {
        delete units[i];
    }
    for (size_t i = 0; i < missions.size(); i++) {
        delete missions[i];
    }
}

bool MilitarySystem::addSoldier(const string& name, const Date& birthDate, const string& role, Soldier::eRank rank)
{
    soldiers.push_back(new Soldier(name, birthDate, role, rank));
    return true;
}

bool MilitarySystem::addOfficer(const string& name, const Date& birthDate, const string& role, Soldier::eRank rank)
{
    soldiers.push_back(new Officer(name, birthDate, role, rank));
    return true;
}

const Soldier* MilitarySystem::findSoldier(int personalNumber) const
{
    for (size_t i = 0; i < soldiers.size(); i++) {
        if (soldiers[i]->getPersonalNumber() == personalNumber) {
            return soldiers[i];
        }
    }
    return nullptr;
}

bool MilitarySystem::addUnit(const string& unitName)
{
    units.push_back(new Unit(unitName));
    return true;
}

const Unit* MilitarySystem::findUnit(int unitId) const
{
    for (size_t i = 0; i < units.size(); i++) {
        if (units[i]->getUnitId() == unitId) {
            return units[i];
        }
    }
    return nullptr;
}

bool MilitarySystem::assignSoldierToUnit(int personalNumber, int unitId)
{
    const Unit* unit = findUnit(unitId);
    if (!unit) return false;

    Soldier* soldier = nullptr;
    for (size_t i = 0; i < soldiers.size(); i++) {
        if (soldiers[i]->getPersonalNumber() == personalNumber) {
            soldier = soldiers[i];
            break;
        }
    }
    if (!soldier) return false;

    Unit* u = const_cast<Unit*>(unit);
    if (!u->addSoldier(*soldier)) return false;
    soldier->setUnit(u);
    return true;
}

bool MilitarySystem::transferSoldier(int personalNumber, int newUnitId)
{
    Soldier* soldier = nullptr;
    for (size_t i = 0; i < soldiers.size(); i++) {
        if (soldiers[i]->getPersonalNumber() == personalNumber) {
            soldier = soldiers[i];
            break;
        }
    }
    if (!soldier) return false;

    Unit* oldUnit = soldier->getUnit();
    if (oldUnit) {
        oldUnit->removeSoldier(*soldier);
    }

    const Unit* newUnit = findUnit(newUnitId);
    if (!newUnit) {
        if (oldUnit) oldUnit->addSoldier(*soldier);
        return false;
    }

    Unit* nu = const_cast<Unit*>(newUnit);
    if (!nu->addSoldier(*soldier)) {
        if (oldUnit) oldUnit->addSoldier(*soldier);
        return false;
    }
    soldier->setUnit(nu);
    return true;
}

bool MilitarySystem::addWarehouse(const string& name)
{
    return this->base.addWarehouse(new Warehouse(name));
}

const Warehouse* MilitarySystem::findWarehouse(const string& name) const
{
    return this->base.findWarehouse(name);
}

bool MilitarySystem::addEquipment(const string& warehouseName, const string& equipmentName, const string& serialNumber, int quantity, Equipment::eEquipmentStatus status)
{
    Warehouse* w = const_cast<Warehouse*>(this->base.findWarehouse(warehouseName));
    if (!w) return false;

    Equipment* eq = new Equipment(equipmentName, serialNumber, quantity, status);
    if (!w->addEquipment(*eq)) {
        delete eq;
        return false;
    }
    return true;
}

const Vehicle* MilitarySystem::findVehicle(const string& vehicleNumber) const
{
    return this->base.findVehicle(vehicleNumber);
}

bool MilitarySystem::setVehicleDriver(const string& vehicleNumber, int personalNumber)
{
    Vehicle* v = const_cast<Vehicle*>(findVehicle(vehicleNumber));
    if (!v) return false;

    Soldier* driver = nullptr;
    for (size_t i = 0; i < soldiers.size(); i++) {
        if (soldiers[i]->getPersonalNumber() == personalNumber) {
            driver = soldiers[i];
            break;
        }
    }
    if (!driver) return false;

    return v->setDriver(driver);
}

bool MilitarySystem::addTrainingMission(const string& missionName, int unitId, TrainingMission::eTrainingType trainingType, TrainingMission::eDifficultyLevel difficultyLevel)
{
    const Unit* unit = findUnit(unitId);
    if (!unit) return false;

    missions.push_back(new TrainingMission(missionName, const_cast<Unit*>(unit), trainingType, difficultyLevel));
    return true;
}

int MilitarySystem::addLogisticsMission(const string& missionName, int unitId)
{
    const Unit* unit = findUnit(unitId);
    if (!unit) return -1;

    LogisticsMission* lm = new LogisticsMission(missionName, const_cast<Unit*>(unit));
    int id = lm->getMissionId();
    missions.push_back(lm);
    return id;
}

const Mission* MilitarySystem::findMission(int missionId) const
{
    for (size_t i = 0; i < missions.size(); i++) {
        if (missions[i]->getMissionId() == missionId) {
            return missions[i];
        }
    }
    return nullptr;
}

bool MilitarySystem::setMissionVehicle(int missionId, const string& vehicleNumber)
{
    Mission* m = const_cast<Mission*>(findMission(missionId));
    if (!m) return false;

    LogisticsMission* lm = dynamic_cast<LogisticsMission*>(m);
    if (!lm) return false;

    Vehicle* v = const_cast<Vehicle*>(findVehicle(vehicleNumber));
    if (!v) return false;

    return lm->setAssignedVehicle(v);
}

bool MilitarySystem::addMissionEquipment(int missionId, const string& warehouseName, const string& equipmentName)
{
    Mission* m = const_cast<Mission*>(findMission(missionId));
    if (!m) return false;

    LogisticsMission* lm = dynamic_cast<LogisticsMission*>(m);
    if (!lm) return false;

    const Warehouse* w = findWarehouse(warehouseName);
    if (!w) return false;

    Equipment* eq = w->searchEquipment(equipmentName);
    if (!eq) return false;

    return lm->addEquipment(*eq);
}

BaseFacility& MilitarySystem::getBase()
{
    return this->base;
}

const BaseFacility& MilitarySystem::getBase() const
{
    return this->base;
}

void MilitarySystem::printAllUnits() const
{
    for (size_t i = 0; i < units.size(); i++) {
        cout<< *units[i];
    }
}

void MilitarySystem::printAllMissions() const
{
    for (size_t i = 0; i < missions.size(); i++) {
        cout << *missions[i] << "\n";
    }
}

int MilitarySystem::getMissionsCount() const
{
    return missions.size();
}

Report MilitarySystem::generateReport() const
{
    int totalEquipment = 0;
    for (int i = 0; i < this->base.getWarehouseCount(); i++) {
        if (this->base.getWarehouse(i) != nullptr) {
            totalEquipment += this->base.getWarehouse(i)->getEquipmentCount();
        }
    }
    return Report(soldiers.size(), units.size(), base.getVehicleCount(), totalEquipment, missions.size());
}

void MilitarySystem::printAllData() const
{
    this->base.print();
    this->printAllUnits();
    this->printAllMissions();
}
