#ifndef MISSION_H
#define MISSION_H

#include <string>

class Unit;

class Mission {
public:
    enum class eMissionStatus {
        NOT_STARTED,
        IN_PROGRESS,
        COMPLETED
    };

private:
    static int s_nextMissionId;
    std::string missionName;
    int   missionId;
    eMissionStatus status;
    Unit* assignedUnit;

public:
    Mission(const std::string& missionName, Unit* assignedUnit);
    virtual ~Mission();

    Mission(const Mission& other) = delete;
    Mission& operator=(const Mission& other) = delete;

    const std::string& getMissionName() const;
    int            getMissionId() const;
    eMissionStatus getStatus() const;
    Unit*          getAssignedUnit() const;

    bool setMissionName(const std::string& missionName);
    bool setStatus(eMissionStatus newStatus);

    friend std::ostream &operator<<(std::ostream &os, const Mission &mission);
};

inline std::ostream& operator<<(std::ostream& os, const Mission::eMissionStatus& status) {
    switch (status) {
        case Mission::eMissionStatus::NOT_STARTED: os << "NOT_STARTED"; break;
        case Mission::eMissionStatus::IN_PROGRESS: os << "IN_PROGRESS"; break;
        case Mission::eMissionStatus::COMPLETED:   os << "COMPLETED";   break;
        default:                                   os << "UNKNOWN";    break;
    }
    return os;
};

#endif // MISSION_H
