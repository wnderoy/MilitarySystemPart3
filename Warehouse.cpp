#include <iostream>
#include "Warehouse.h"
#include "Equipment.h"
using namespace std;


Warehouse:: Warehouse(const char* name, int capacity) : capacity(capacity),count(0)
{
    this->name = new char[strlen(name) + 1];
    strcpy(this->name,name);

    this->equipmentList = new Equipment*[capacity];
    for (int i = 0; i < capacity; i++) {
        this->equipmentList[i] = nullptr;
    }
}

Warehouse::~Warehouse()
{
    delete[] this->name;
    for (int i = 0; i < this->count; i++) {
        delete this->equipmentList[i];
    }
    delete[] this->equipmentList;
}

const char* Warehouse::getName() const
{
    return this->name;
}

int Warehouse::getEquipmentCount() const
{
    return this->count;
}

Equipment* Warehouse::getEquipment(int index) const
{
    if (index < 0 || index >= this->count) {
        return nullptr;
    }
    return this->equipmentList[index];
}

bool Warehouse::setName(const char* name)
{
    if (name == nullptr || strlen(name) == 0) {
        return false;
    }
    delete[] this->name;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    return true;
}

bool Warehouse::addEquipment(Equipment* equipment)
{
    if (equipment == nullptr || this->count >= this->capacity) {
        return false;
    }
    this->equipmentList[this->count] = equipment;
    this->count++;
    return true;
}

Equipment* Warehouse::searchEquipment(const char* name) const
{
    if (name == nullptr) {
        return nullptr;
    }
    for (int i = 0; i < this->count; i++) {
        if (strcmp(this->equipmentList[i]->getName(), name) == 0) {
            return this->equipmentList[i];
        }
    }
    return nullptr;
}

std::ostream& operator<<(std::ostream& os, const Warehouse& wh)
{
    os << "Warehouse: " << wh.name << " (Items: " << wh.count << "/" << wh.capacity << ")\n";
    for (int i = 0; i < wh.count; i++) {
        if (wh.equipmentList[i] != nullptr) {
            os << *wh.equipmentList[i] << "\n";
        }
    }
    return os;
}

void Warehouse::printEquipment() const
{
    for (int i = 0; i < this->count; i++) {
        cout<<this->equipmentList[i];
    }
}

/*
#ifndef WAREHOUSE_H
#define WAREHOUSE_H

class Equipment;

class Warehouse {
private:
    char* name;

    Equipment** equipmentList;
    int count;
    int capacity;

    Warehouse(const char* name);
    ~Warehouse();

    Warehouse(const Warehouse& other) = delete;
    Warehouse& operator=(const Warehouse& other) = delete;

    const char* getName() const;
    int         getEquipmentCount() const;
    Equipment*  getEquipment(int index) const;

    bool setName(const char* name);

    bool       addEquipment(Equipment* equipment);
    Equipment* searchEquipment(const char* name) const;
    void       printEquipment() const;
};

#endif // WAREHOUSE_H
*/