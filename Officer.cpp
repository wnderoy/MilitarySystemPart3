#include <iostream>
#include "Officer.h"
using namespace std;
/*
part 3:

commandedSoldiers - Soldier** now vector<Soldier*> 
commandedCount - deleted cause now we have vector
 commandedCapacity - deleted
*/
Officer::Officer(const string& name, const Date& birthDate, const string& role, eRank rank)
: Soldier(name, birthDate, role, rank)
{
}

Officer::~Officer()
{
}

int Officer::getCommandedCount() const
{
    return commandedSoldiers.size();
}

Soldier* Officer::getCommandedSoldier(int index) const
{
    if (index < 0 || index >= (int)commandedSoldiers.size()) return nullptr;
    return commandedSoldiers[index];
}

bool Officer::addCommandedSoldier(Soldier& soldier)
{
    commandedSoldiers.push_back(&soldier);
    return true;
}

bool Officer::removeCommandedSoldier(const Soldier& soldier)
{
    for (auto it = commandedSoldiers.begin(); it != commandedSoldiers.end(); ++it)
    {
        if (*it == &soldier)
        {
            commandedSoldiers.erase(it);
            return true;
        }
    }
    return false;
}

void Officer::printCommandedSoldiers() const
{
    for (size_t i = 0; i < commandedSoldiers.size(); i++)
    {
        cout << "Commanded Soldier " << i + 1 << ": " << endl;
    }
}

std::ostream &operator<<(std::ostream &os, const Officer &officer)
{
    os << static_cast<const Soldier&>(officer) << ", Commanded Soldiers Count: " << officer.commandedSoldiers.size();
    return os;
}
