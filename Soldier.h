#ifndef SOLDIER_H
#define SOLDIER_H

#include "Date.h"
#include <string>

class Unit;

class Soldier {
public:
    enum class eRank {
        PRIVATE,
        CORPORAL,
        SERGEANT,
        LIEUTENANT,
        CAPTAIN,
        MAJOR
    };

private:
    static int s_nextId;
    static int s_nextPersonalNumber;

    std::string name;
    int   id;
    Date  birthDate;

    int   personalNumber;
    std::string role;
    eRank rank;
    Unit* unit;

public:
    Soldier(const std::string& name,
            const Date& birthDate,
            const std::string& role,
            eRank rank);
    virtual ~Soldier();

    Soldier(const Soldier& other) = delete;
    Soldier& operator=(const Soldier& other) = delete;

    const std::string& getName() const;
    int         getId() const;
    const Date& getBirthDate() const;
    int         getPersonalNumber() const;
    const std::string& getRole() const;
    eRank       getRank() const;
    Unit*       getUnit() const;

    bool setName(const std::string& name);
    bool setBirthDate(const Date& birthDate);
    bool setRole(const std::string& role);
    bool setRank(eRank rank);
    bool setUnit(Unit* newUnit);

    friend std::ostream &operator<<(std::ostream &os, const Soldier &soldier);
};

inline std::ostream& operator<<(std::ostream& os, const Soldier::eRank& rank) {
    switch (rank) {
        case Soldier::eRank::PRIVATE:    os << "PRIVATE"; break;
        case Soldier::eRank::CORPORAL:   os << "CORPORAL"; break;
        case Soldier::eRank::SERGEANT:   os << "SERGEANT"; break;
        case Soldier::eRank::LIEUTENANT: os << "LIEUTENANT"; break;
        case Soldier::eRank::CAPTAIN:    os << "CAPTAIN"; break;
        case Soldier::eRank::MAJOR:      os << "MAJOR"; break;
        default:                         os << "UNKNOWN"; break;
    }
    return os;
}

#endif // SOLDIER_H
