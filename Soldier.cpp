#include <iostream>
#include "Soldier.h"
using namespace std;

int Soldier::s_nextId = 1;
int Soldier::s_nextPersonalNumber = 1000;

Soldier::Soldier(const string &name, const Date &birthDate, const string &role, eRank rank)
    : name(name), birthDate(birthDate), role(role), rank(rank),
      id(s_nextId++), personalNumber(s_nextPersonalNumber++), unit(nullptr)
{
}

Soldier::~Soldier()
{
}

const string& Soldier::getName() const
{
    return name;
}

int Soldier::getId() const
{
    return id;
}

const Date &Soldier::getBirthDate() const
{
    return birthDate;
}

int Soldier::getPersonalNumber() const
{
    return personalNumber;
}

const string& Soldier::getRole() const
{
    return role;
}

Soldier::eRank Soldier::getRank() const
{
    return rank;
}

Unit *Soldier::getUnit() const
{
    return unit;
}

bool Soldier::setName(const string &name)
{
    if (name.empty())
    {
        return false;
    }
    this->name = name;
    return true;
}

bool Soldier::setBirthDate(const Date &birthDate)
{
    this->birthDate = birthDate;
    return true;
}

bool Soldier::setRole(const string &role)
{
    if (role.empty())
    {
        return false;
    }
    this->role = role;
    return true;
}

bool Soldier::setRank(eRank rank)
{
    this->rank = rank;
    return true;
}

bool Soldier::setUnit(Unit *newUnit)
{
    this->unit = newUnit;
    return true;
}

std::ostream &operator<<(std::ostream &os, const Soldier &soldier)
{
    os << "name: " << soldier.name
       << " ,birthDate: " << soldier.birthDate
       << " ,role: " << soldier.role << " ,rank: " << soldier.rank;
    return os;
}
