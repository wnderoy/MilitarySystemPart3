#include <iostream>
#include <cstring>
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

MilitarySystem::MilitarySystem():base(), soldiersCount(0), soldiersCapacity(10),
      unitsCount(0), unitsCapacity(10),
      missionsCount(0), missionsCapacity(10)
{
    this->soldiers = new Soldier*[this->soldiersCapacity];
    for (int i = 0; i < this->soldiersCapacity; i++) {
        this->soldiers[i] = nullptr;
    }

    this->units = new Unit*[this->unitsCapacity];
    for (int i = 0; i < this->unitsCapacity; i++) {
        this->units[i] = nullptr;
    }

    this->missions = new Mission*[this->missionsCapacity];
    for (int i = 0; i < this->missionsCapacity; i++) {
        this->missions[i] = nullptr;
    }
}

MilitarySystem::~MilitarySystem()
{
    for (int i = 0; i < this->soldiersCount; i++) {
        delete this->soldiers[i];
    }
    delete[] this->soldiers;

    for (int i = 0; i < this->unitsCount; i++) {
        delete this->units[i];
    }
    delete[] this->units;

    for (int i = 0; i < this->missionsCount; i++) {
        delete this->missions[i];
    }
    delete[] this->missions;
}

bool MilitarySystem::addSoldier(const char* name, const Date& birthDate, const char* role, Soldier::eRank rank)
{
    if (this->soldiersCount >= this->soldiersCapacity) {
        int newCapacity = this->soldiersCapacity * 2;
        Soldier** temp = new Soldier*[newCapacity];
        for (int i = 0; i < this->soldiersCapacity; i++) {
            temp[i] = this->soldiers[i];
        }
        for (int i = this->soldiersCapacity; i < newCapacity; i++) {
            temp[i] = nullptr;
        }
        delete[] this->soldiers;
        this->soldiers = temp;
        this->soldiersCapacity = newCapacity;
    }
    this->soldiers[this->soldiersCount++] = new Soldier(name, birthDate, role, rank);
    return true;
}

bool MilitarySystem::addOfficer(const char* name, const Date& birthDate, const char* role, Soldier::eRank rank)
{
    if (this->soldiersCount >= this->soldiersCapacity) {
        int newCapacity = this->soldiersCapacity * 2;
        Soldier** temp = new Soldier*[newCapacity];
        for (int i = 0; i < this->soldiersCapacity; i++) {
            temp[i] = this->soldiers[i];
        }
        for (int i = this->soldiersCapacity; i < newCapacity; i++) {
            temp[i] = nullptr;
        }
        delete[] this->soldiers;
        this->soldiers = temp;
        this->soldiersCapacity = newCapacity;
    }
    this->soldiers[this->soldiersCount++] = new Officer(name, birthDate, role, rank);
    return true;
}

const Soldier* MilitarySystem::findSoldier(int personalNumber) const
{
    for (int i = 0; i < this->soldiersCount; i++) {
        if (this->soldiers[i]->getPersonalNumber() == personalNumber) {
            return this->soldiers[i];
        }
    }
    return nullptr;
}

bool MilitarySystem::addUnit(const char* unitName)
{
    if (this->unitsCount >= this->unitsCapacity) {
        int newCapacity = this->unitsCapacity * 2;
        Unit** temp = new Unit*[newCapacity];
        for (int i = 0; i < this->unitsCapacity; i++) {
            temp[i] = this->units[i];
        }
        for (int i = this->unitsCapacity; i < newCapacity; i++) {
            temp[i] = nullptr;
        }
        delete[] this->units;
        this->units = temp;
        this->unitsCapacity = newCapacity;
    }
    this->units[this->unitsCount++] = new Unit(unitName);
    return true;
}

const Unit* MilitarySystem::findUnit(int unitId) const
{
    for (int i = 0; i < this->unitsCount; i++) {
        if (this->units[i]->getUnitId() == unitId) {
            return this->units[i];
        }
    }
    return nullptr;
}

bool MilitarySystem::assignSoldierToUnit(int personalNumber, int unitId)
{
    const Unit* unit = findUnit(unitId);
    if (!unit) return false;

    Soldier* soldier = nullptr;
    for (int i = 0; i < this->soldiersCount; i++) {
        if (this->soldiers[i]->getPersonalNumber() == personalNumber) {
            soldier = this->soldiers[i];
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
    for (int i = 0; i < this->soldiersCount; i++) {
        if (this->soldiers[i]->getPersonalNumber() == personalNumber) {
            soldier = this->soldiers[i];
            break;
        }
    }
    if (!soldier) return false;

    Unit* oldUnit = soldier->getUnit();
    if (oldUnit) {
        oldUnit->removeSoldier(soldier);
    }

    const Unit* newUnit = findUnit(newUnitId);
    if (!newUnit) {
        if (oldUnit) oldUnit->addSoldier(*soldier); // rollback
        return false;
    }

    Unit* nu = const_cast<Unit*>(newUnit);
    if (!nu->addSoldier(*soldier)) {
        if (oldUnit) oldUnit->addSoldier(*soldier); // rollback
        return false;
    }
    soldier->setUnit(nu);
    return true;
}

bool MilitarySystem::addWarehouse(const char* name)
{
    return this->base.addWarehouse(new Warehouse(name));
}

const Warehouse* MilitarySystem::findWarehouse(const char* name) const
{
    return this->base.findWarehouse(name);
}

bool MilitarySystem::addEquipment(const char* warehouseName, const char* equipmentName, const char* serialNumber, int quantity, Equipment::eEquipmentStatus status)
{
    Warehouse* w = const_cast<Warehouse*>(this->base.findWarehouse(warehouseName));
    if (!w) return false;

    Equipment* eq = new Equipment(equipmentName, serialNumber, quantity, status);
    if (!w->addEquipment(eq)) {
        delete eq;
        return false;
    }
    return true;
}

Vehicle* MilitarySystem::findVehicle(const char* vehicleNumber) const
{
    return const_cast<Vehicle*>(this->base.findVehicle(vehicleNumber));
}

bool MilitarySystem::setVehicleDriver(const char* vehicleNumber, int personalNumber)
{
    Vehicle* v = findVehicle(vehicleNumber);
    if (!v) return false;

    Soldier* driver = nullptr;
    for (int i = 0; i < this->soldiersCount; i++) {
        if (this->soldiers[i]->getPersonalNumber() == personalNumber) {
            driver = this->soldiers[i];
            break;
        }
    }
    if (!driver) return false;

    return v->setDriver(driver);
}

bool MilitarySystem::addTrainingMission(const char* missionName, int unitId, TrainingMission::eTrainingType trainingType, TrainingMission::eDifficultyLevel difficultyLevel)
{
    if (this->missionsCount >= this->missionsCapacity) {
        int newCapacity = this->missionsCapacity * 2;
        Mission** temp = new Mission*[newCapacity];
        for (int i = 0; i < this->missionsCapacity; i++) {
            temp[i] = this->missions[i];
        }
        for (int i = this->missionsCapacity; i < newCapacity; i++) {
            temp[i] = nullptr;
        }
        delete[] this->missions;
        this->missions = temp;
        this->missionsCapacity = newCapacity;
    }

    const Unit* unit = findUnit(unitId);
    if (!unit) return false;

    this->missions[this->missionsCount++] = new TrainingMission(missionName, const_cast<Unit*>(unit), trainingType, difficultyLevel);
    return true;
}

int MilitarySystem::addLogisticsMission(const char* missionName, int unitId)
{
    if (this->missionsCount >= this->missionsCapacity) {
        int newCapacity = this->missionsCapacity * 2;
        Mission** temp = new Mission*[newCapacity];
        for (int i = 0; i < this->missionsCapacity; i++) {
            temp[i] = this->missions[i];
        }
        for (int i = this->missionsCapacity; i < newCapacity; i++) {
            temp[i] = nullptr;
        }
        delete[] this->missions;
        this->missions = temp;
        this->missionsCapacity = newCapacity;
    }

    const Unit* unit = findUnit(unitId);
    if (!unit) return -1;

    LogisticsMission* lm = new LogisticsMission(missionName, const_cast<Unit*>(unit));
    int id = lm->getMissionId();
    this->missions[this->missionsCount++] = lm;
    return id;
}

Mission* MilitarySystem::findMission(int missionId) const
{
    for (int i = 0; i < this->missionsCount; i++) {
        if (this->missions[i]->getMissionId() == missionId) {
            return this->missions[i];
        }
    }
    return nullptr;
}

bool MilitarySystem::setMissionVehicle(int missionId, const char* vehicleNumber)
{
    Mission* m = findMission(missionId);
    if (!m) return false;

    LogisticsMission* lm = dynamic_cast<LogisticsMission*>(m);
    if (!lm) return false;

    Vehicle* v = findVehicle(vehicleNumber);
    if (!v) return false;

    return lm->setAssignedVehicle(v);
}

bool MilitarySystem::addMissionEquipment(int missionId, const char* warehouseName, const char* equipmentName)
{
    Mission* m = findMission(missionId);
    if (!m) return false;

    LogisticsMission* lm = dynamic_cast<LogisticsMission*>(m);
    if (!lm) return false;

    const Warehouse* w = findWarehouse(warehouseName);
    if (!w) return false;

    Equipment* eq = w->searchEquipment(equipmentName);
    if (!eq) return false;

    return lm->addEquipment(eq);
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
    for (int i = 0; i < this->unitsCount; i++) {
        cout<< *this->units[i];
    }
}

void MilitarySystem::printAllMissions() const
{
    for (int i = 0; i < this->missionsCount; i++) {
        cout << *this->missions[i] << "\n";
    }
}

int MilitarySystem::getMissionsCount() const
{
    return this->missionsCount;
}

Report MilitarySystem::generateReport() const
{
    int totalEquipment = 0;
    for (int i = 0; i < this->base.getWarehouseCount(); i++) {
        if (this->base.getWarehouse(i) != nullptr) {
            totalEquipment += this->base.getWarehouse(i)->getEquipmentCount();
        }
    }
    return Report(this->soldiersCount,this->unitsCount,this->base.getVehicleCount(),totalEquipment,this->missionsCount);
}

void MilitarySystem::printAllData() const
{
    this->base.print();
    this->printAllUnits();
    this->printAllMissions();
}
