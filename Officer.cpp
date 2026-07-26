#include <iostream>
#include "Officer.h"
using namespace std;

Officer::Officer(const char* name, const Date& birthDate, const char* role, eRank rank)
: Soldier(name, birthDate, role, rank),commandedSoldiers(nullptr), commandedCount(0), commandedCapacity(0){};

Officer::~Officer() {
    delete[] commandedSoldiers;
}

int Officer::getCommandedCount() const
{
    return commandedCount;
};

Soldier* Officer::getCommandedSoldier(int index) const
{
    return commandedSoldiers[index];
};

bool Officer::addCommandedSoldier(Soldier* soldier)
{
    if (commandedCount < commandedCapacity)
    {
        commandedSoldiers[commandedCount++] = soldier;
    }
    else
    {
        int newCapacity;
        if (commandedCapacity == 0)
        {
            newCapacity = 1;
        }    
        else
        {
            newCapacity = 2 * commandedCapacity;
        }
        Soldier** tempCommandedSoldiers = new Soldier*[newCapacity];
        for (int i = 0; i < commandedCount; i++)
        {
            tempCommandedSoldiers[i] = commandedSoldiers[i];
        }
        tempCommandedSoldiers[commandedCount] = soldier;
        delete[] commandedSoldiers;
        commandedSoldiers = tempCommandedSoldiers;
        commandedCount++;
        commandedCapacity = newCapacity;
    }
    return true;
};

bool Officer::removeCommandedSoldier(const Soldier* soldier)
{
    for (int i = 0; i < commandedCount; i++)
    {
        if (commandedSoldiers[i] == soldier)
        {
            for (int j = i; j < commandedCount - 1; j++)
            {
                commandedSoldiers[j] = commandedSoldiers[j + 1];
            }
            commandedCount--;
            return true;
        }
    }
    return false;
};

void Officer::printCommandedSoldiers() const
{
    for (int i = 0; i < commandedCount; i++)
    {
        cout << "Commanded Soldier " << i + 1 << ": " << endl;
        commandedSoldiers[i];
    }
};

std::ostream &operator<<(std::ostream &os, const Officer &officer)
{
    os << static_cast<const Soldier&>(officer) << ", Commanded Soldiers Count: " << officer.commandedCount;
    return os;
};

// void Officer::print() const override;