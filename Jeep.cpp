#include <iostream>
#include "Jeep.h"
using namespace std;
/*
part 3:
passengers - Soldier** now vector<Soldier*> 
passengerCount - deleted because we have vectors



*/
Jeep::Jeep(const string &vehicleNumber, int maxPassengers)
    : Vehicle(vehicleNumber), maxPassengers(maxPassengers)
{
}

Jeep::~Jeep()
{
}

int Jeep::getMaxPassengers() const
{
    return maxPassengers;
}

int Jeep::getPassengerCount() const
{
    return passengers.size();
}

Soldier *Jeep::getPassenger(int index) const
{
    if (index >= 0 && index < (int)passengers.size())
    {
        return passengers[index];
    }
    return nullptr;
}

bool Jeep::setMaxPassengers(int maxPassengers)
{
    if (maxPassengers <= 0)
    {
        return false;
    }

    if (maxPassengers < (int)passengers.size()) {
        passengers.resize(maxPassengers);
    }
    this->maxPassengers = maxPassengers;
    return true;
}

bool Jeep::loadPassenger(Soldier& soldier)
{
    if ((int)passengers.size() >= maxPassengers)
    {
        return false;
    }
    passengers.push_back(&soldier);
    return true;
}

bool Jeep::unloadPassenger(const Soldier& soldier)
{
    for (auto it = passengers.begin(); it != passengers.end(); ++it)
    {
        if (*it == &soldier)
        {
            passengers.erase(it);
            return true;
        }
    }
    return false;
}

std::ostream &operator<<(std::ostream &os, const Jeep &jeep)
{
    os << static_cast<const Vehicle&>(jeep) << ", Max Passengers: " << jeep.maxPassengers << ", Passenger Count: " << jeep.passengers.size();
    for (size_t i = 0; i < jeep.passengers.size(); ++i)
    {
        os << "\n, Passenger " << i + 1 << ": " << jeep.passengers[i];
    }
    return os;
}
