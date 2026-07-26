#include "MilitarySystem.h"
#include "Date.h"
#include "Soldier.h"
#include "Equipment.h"
#include "Mission.h"
#include "TrainingMission.h"
#include "LogisticsMission.h"
#include "Vehicle.h"
#include "Report.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

void readPersonInput(const string& namePrompt,
                     string& name,
                     string& role,
                     int& day,
                     int& month,
                     int& year,
                     int& rank) {
    cout << namePrompt;
    cin >> name;
    cout << "Enter birth date:" << endl;
    cout << "Day: ";   cin >> day;
    cout << "Month: "; cin >> month;
    cout << "Year: ";  cin >> year;
    cout << "Role: ";  cin >> role;
    cout << "Rank (0=PRIVATE 1=CORPORAL 2=SERGEANT 3=LIEUTENANT 4=CAPTAIN 5=MAJOR): ";
    cin >> rank;
}

void addSoldier(MilitarySystem& militarySystem) {
    string name, role;
    int day, month, year, rank;

    readPersonInput("Soldier name: ", name, role, day, month, year, rank);

    if (militarySystem.addSoldier(name, Date(day, month, year), role,
                                  (Soldier::eRank)rank)) {
        cout << "Soldier added." << endl;
    } else {
        cout << "Failed to add soldier." << endl;
    }
}

void addOfficer(MilitarySystem& militarySystem) {
    string name, role;
    int day, month, year, rank;

    readPersonInput("Officer name: ", name, role, day, month, year, rank);

    if (militarySystem.addOfficer(name, Date(day, month, year), role,
                                  (Soldier::eRank)rank)) {
        cout << "Officer added." << endl;
    } else {
        cout << "Failed to add officer." << endl;
    }
}

void createUnit(MilitarySystem& militarySystem) {
    string unitName;
    cout << "Unit name: ";
    cin >> unitName;

    if (militarySystem.addUnit(unitName)) {
        cout << "Unit created." << endl;
    } else {
        cout << "Failed to create unit." << endl;
    }
}

void addWarehouse(MilitarySystem& militarySystem) {
    string warehouseName;
    cout << "Warehouse name: "; 
    cin >> warehouseName;

    if (militarySystem.addWarehouse(warehouseName)) {
        cout << "Warehouse added." << endl;
    } else {
        cout << "Failed to add warehouse." << endl;
    }
}

void addEquipment(MilitarySystem& militarySystem) {
    militarySystem.getBase().printWarehouses();

    if (militarySystem.getBase().getWarehouseCount() == 0) {
        return;
    }

    string warehouseName, equipmentName, serialNumber;
    int quantity, equipmentStatus;

    cout << "Warehouse name: ";
    cin >> warehouseName;

    if (!militarySystem.findWarehouse(warehouseName)) {
        cout << "Warehouse not found." << endl;
        return;
    }

    cout << "Equipment name: ";
    cin >> equipmentName;
    cout << "Serial number: ";
    cin >> serialNumber;
    cout << "Quantity: ";
    cin >> quantity;
    cout << "Status (0=WORKING 1=DAMAGED): ";
    cin >> equipmentStatus;

    if (militarySystem.addEquipment(warehouseName, equipmentName, serialNumber, quantity,
                                    (Equipment::eEquipmentStatus)equipmentStatus)) {
        cout << "Equipment added." << endl;
    } else {
        cout << "Failed to add equipment." << endl;
    }
}

void createTrainingMission(MilitarySystem& militarySystem) {
    string name;
    int unitId, trainingType, difficultyLevel;

    cout << "Mission name: ";   
    cin >> name;
    cout << "Assigned unit ID: "; 
    cin >> unitId;
    cout << "Training type (0=FITNESS 1=DRIVING 2=TECHNICAL 3=COMMAND): "; 
    cin >> trainingType;
    cout << "Difficulty (0=EASY 1=MEDIUM 2=HARD): ";                      
    cin >> difficultyLevel;

    if (militarySystem.addTrainingMission(name, unitId,
                                          (TrainingMission::eTrainingType)trainingType,
                                          (TrainingMission::eDifficultyLevel)difficultyLevel)) {
        cout << "Training mission created." << endl;
    } else {
        cout << "Failed to create training mission." << endl;
    }
}

void updateMissionStatus(MilitarySystem& militarySystem) {
    int missionId, missionStatus;

    militarySystem.printAllMissions();
    if (militarySystem.getMissionsCount() == 0) {
        return;
    }

    cout << "Mission ID: ";                                       
    cin >> missionId;
    cout << "Status (0=NOT_STARTED 1=IN_PROGRESS 2=COMPLETED): "; 
    cin >> missionStatus;

    Mission* mission = const_cast<Mission*>(militarySystem.findMission(missionId));
    if (!mission) {
        cout << "Mission not found." << endl;
        return;
    }
    if (mission->setStatus((Mission::eMissionStatus)missionStatus)) {
        cout << "Status updated." << endl;
    } else {
        cout << "Status update rejected." << endl;
    }
}

void printMenu() {
    cout << endl;
    cout << "=== Military Base Management System ===" << endl;
    cout << " 1. Add soldier"                                              << endl;
    cout << " 2. Add officer"                                              << endl;
    cout << " 3. Create unit"                                              << endl;
    cout << " 4. Add warehouse"                                            << endl;
    cout << " 5. Add equipment to warehouse"                               << endl;
    cout << " 6. Create training mission"                                  << endl;
    cout << " 7. Update mission status"                                    << endl;
    cout << " 8. Print all data"                                           << endl;
    cout << " 9. Generate and print report"                                << endl;
    cout << " 0. Exit"                                                     << endl;
}

int main() {
    srand((unsigned)time(nullptr));
    MilitarySystem militarySystem;

    cout << "Welcome to the Military Base Management System." << endl;
    cout << "Note: names are single words (use MainDepot, not Main Depot)." << endl;

    int choice;
    do {
        printMenu();
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:  addSoldier(militarySystem);                       break;
            case 2:  addOfficer(militarySystem);                       break;
            case 3:  createUnit(militarySystem);                       break;
            case 4:  addWarehouse(militarySystem);                     break;
            case 5:  addEquipment(militarySystem);                     break;
            case 6:  createTrainingMission(militarySystem);            break;
            case 7:  updateMissionStatus(militarySystem);              break;
            case 8:  militarySystem.printAllData();                    break;
            case 9:  cout << militarySystem.generateReport();          break;
            case 0:  cout << "Goodbye." << endl;                       break;
            default: cout << "Invalid choice." << endl;
        }
    } while (choice != 0);

    return 0;
}
