#include <iostream>
#include "Warehouse.h"
#include "Equipment.h"
using namespace std;
/*
part 3 changes:
name - char* now string

equipmentList - Equipment** now vector<Equipment*>

*/
Warehouse::Warehouse(const string& name)
    : name(name)
{
}

Warehouse::~Warehouse()
{
    for (size_t i = 0; i < equipmentList.size(); i++) {
        delete equipmentList[i];
    }
}

const string& Warehouse::getName() const
{
    return name;
}

int Warehouse::getEquipmentCount() const
{
    return equipmentList.size();
}

Equipment* Warehouse::getEquipment(int index) const
{
    if (index < 0 || index >= (int)equipmentList.size()) {
        return nullptr;
    }
    return equipmentList[index];
}

bool Warehouse::setName(const string& name)
{
    if (name.empty()) {
        return false;
    }
    this->name = name;
    return true;
}

bool Warehouse::addEquipment(Equipment& equipment)
{
    equipmentList.push_back(&equipment);
    return true;
}

Equipment* Warehouse::searchEquipment(const string& name) const
{
    for (size_t i = 0; i < equipmentList.size(); i++) {
        if (equipmentList[i]->getName() == name) {
            return equipmentList[i];
        }
    }
    return nullptr;
}

std::ostream& operator<<(std::ostream& os, const Warehouse& wh)
{
    os << "Warehouse: " << wh.name << " (Items: " << wh.equipmentList.size() << ")\n";
    for (size_t i = 0; i < wh.equipmentList.size(); i++) {
        if (wh.equipmentList[i] != nullptr) {
            os << *wh.equipmentList[i] << "\n";
        }
    }
    return os;
}

void Warehouse::printEquipment() const
{
    for (size_t i = 0; i < equipmentList.size(); i++) {
        cout << equipmentList[i];
    }
}
