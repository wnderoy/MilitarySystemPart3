#ifndef MILITARY_SYSTEM_H
#define MILITARY_SYSTEM_H

#include "BaseFacility.h"
#include "Soldier.h"
#include "Equipment.h"
#include "TrainingMission.h"
#include "Report.h"
#include <vector>
#include <string>

class Date;
class Unit;
class Vehicle;
class Warehouse;
class Mission;

class MilitarySystem {
private:
    std::vector<Soldier*> soldiers;
    std::vector<Unit*> units;
    std::vector<Mission*> missions;

    BaseFacility base;

public:
    MilitarySystem();
       ~MilitarySystem();

    MilitarySystem(const MilitarySystem& other) = delete;
    MilitarySystem& operator=(const MilitarySystem& other) = delete;

    bool addSoldier(const std::string& name,
                    const Date& birthDate,
                    const std::string& role,
                    Soldier::eRank rank);
    bool addOfficer(const std::string& name,
                    const Date& birthDate,
                    const std::string& role,
                    Soldier::eRank rank);
    const Soldier* findSoldier(int personalNumber) const;

    bool addUnit(const std::string& unitName);
    const Unit* findUnit(int unitId) const;
    bool assignSoldierToUnit(int personalNumber, int unitId);
    bool transferSoldier(int personalNumber, int newUnitId);

    bool addWarehouse(const std::string& name);
    const Warehouse* findWarehouse(const std::string& name) const;
    bool addEquipment(const std::string& warehouseName,
                      const std::string& equipmentName,
                      const std::string& serialNumber,
                      int quantity,
                      Equipment::eEquipmentStatus status);

    const Vehicle* findVehicle(const std::string& vehicleNumber) const;
    bool setVehicleDriver(const std::string& vehicleNumber, int personalNumber);

    bool addTrainingMission(const std::string& missionName,
                            int unitId,
                            TrainingMission::eTrainingType trainingType,
                            TrainingMission::eDifficultyLevel difficultyLevel);
    int addLogisticsMission(const std::string& missionName, int unitId);
    const Mission* findMission(int missionId) const;
    bool setMissionVehicle(int missionId, const std::string& vehicleNumber);
    bool addMissionEquipment(int missionId,
                             const std::string& warehouseName,
                             const std::string& equipmentName);

    BaseFacility&       getBase();
    const BaseFacility& getBase() const;

    void printAllUnits() const;
    void printAllMissions() const;
    int  getMissionsCount() const;
    Report generateReport() const;
    void   printAllData() const;
};

#endif // MILITARY_SYSTEM_H
