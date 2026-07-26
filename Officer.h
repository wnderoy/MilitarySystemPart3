#ifndef OFFICER_H
#define OFFICER_H

#include "Soldier.h"
#include <vector>
/*
part 3:

commandedSoldiers - Soldier** now vector<Soldier*> 
commandedCount - deleted cause now we have vector
 commandedCapacity - deleted
*/
class Officer : public Soldier {
private:
    std::vector<Soldier*> commandedSoldiers;

public:
    Officer(const std::string& name,
            const Date& birthDate,
            const std::string& role,
            eRank rank);
    ~Officer();

    Officer(const Officer& other) = delete;
    Officer& operator=(const Officer& other) = delete;

    int getCommandedCount() const;
    Soldier* getCommandedSoldier(int index) const;

    bool addCommandedSoldier(Soldier& soldier);
    bool removeCommandedSoldier(const Soldier& soldier);
    void printCommandedSoldiers() const;

    friend std::ostream &operator<<(std::ostream &os, const Officer &officer);
};

#endif // OFFICER_H
