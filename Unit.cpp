#include <iostream>
#include "Unit.h"
using namespace std;

int Unit::s_nextUnitId = 1;

Unit::Unit(const string& unitName)
    : unitName(unitName)
{
    unitId = s_nextUnitId++;
}

Unit::~Unit()
{
}

const string& Unit::getUnitName() const
{
    return unitName;
}

int Unit::getUnitId() const
{
    return unitId;
}

int Unit::getSoldierCount() const
{
    return soldiers.size();
}

Soldier* Unit::getSoldier(int index) const
{
    if (index < 0 || index >= (int)soldiers.size()) return nullptr;
    return soldiers[index];
}

bool Unit::setUnitName(const string& name)
{
    if (name.empty())
    {
        return false;
    }
    unitName = name;
    return true;
}

bool Unit::addSoldier(Soldier& soldier)
{
    soldiers.push_back(&soldier);
    return true;
}

bool Unit::removeSoldier(const Soldier& soldier)
{
    for (auto it = soldiers.begin(); it != soldiers.end(); ++it)
    {
        if (*it == &soldier)
        {
            soldiers.erase(it);
            return true;
        }
    }
    return false;
}

void Unit::printSoldiers() const
{
    for (size_t i = 0; i < soldiers.size(); i++)
    {
        cout << soldiers[i] << endl;
    }
}

std::ostream &operator<<(std::ostream &os, const Unit &unit)
{
    os << "Unit Name: " << unit.unitName
       << ", Unit ID: " << unit.unitId
       << ", Soldier Count: " << unit.soldiers.size();
    return os;
}
