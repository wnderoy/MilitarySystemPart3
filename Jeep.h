#ifndef JEEP_H
#define JEEP_H

#include "Vehicle.h"
#include <vector>

class Soldier;

class Jeep : virtual public Vehicle {
private:
    std::vector<Soldier*> passengers;
    int maxPassengers;

public:
    Jeep(const std::string& vehicleNumber, int maxPassengers);
    ~Jeep();

    Jeep(const Jeep& other) = delete;
    Jeep& operator=(const Jeep& other) = delete;

    int      getMaxPassengers() const;
    int      getPassengerCount() const;
    Soldier* getPassenger(int index) const;

    bool setMaxPassengers(int maxPassengers);

    bool loadPassenger(Soldier& soldier);
    bool unloadPassenger(const Soldier& soldier);

    friend std::ostream &operator<<(std::ostream &os, const Jeep &jeep);
};

#endif // JEEP_H
