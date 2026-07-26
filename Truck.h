#ifndef TRUCK_H
#define TRUCK_H

#include "Vehicle.h"
#include <vector>
class Equipment;
/*
part 3:
loadedEquipment - Equipment* static now vector<Equipment*>
loadedCapacity - deleted
loadedCount - deleted

*/
class Truck : virtual public Vehicle {
private:
    std::vector<Equipment*> loadedEquipment;
    double maxWeightKG;

public:
    Truck(const std::string& vehicleNumber, double maxWeightKG);
    ~Truck();

    Truck(const Truck& other) = delete;
    Truck& operator=(const Truck& other) = delete;

    int        getLoadedCount() const;
    Equipment* getLoadedEquipment(int index) const;
    double     getMaxWeightKG() const;

    bool setMaxWeightKG(double maxWeightKG);

    bool loadEquipment(Equipment& equipment);
    bool unloadEquipment(const Equipment& equipment);
};

#endif // TRUCK_H
