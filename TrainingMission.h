#ifndef TRAINING_MISSION_H
#define TRAINING_MISSION_H

#include "Mission.h"

class TrainingMission : public Mission 
{
public:
    enum class eTrainingType {
        FITNESS,
        DRIVING,
        TECHNICAL,
        COMMAND
    };

    enum class eDifficultyLevel {
        EASY,
        MEDIUM,
        HARD
    };

private:
    eTrainingType    trainingType;
    eDifficultyLevel difficultyLevel;

public:
    TrainingMission(const std::string& missionName,
                    Unit* assignedUnit,
                    eTrainingType trainingType,
                    eDifficultyLevel difficultyLevel);

    TrainingMission(const TrainingMission& other) = delete;
    TrainingMission& operator=(const TrainingMission& other) = delete;

    eTrainingType    getTrainingType() const;
    eDifficultyLevel getDifficultyLevel() const;

    bool setTrainingType(eTrainingType trainingType);
    bool setDifficultyLevel(eDifficultyLevel difficultyLevel);

    bool improveReadiness();

    friend std::ostream &operator<<(std::ostream &os, const TrainingMission &trainingMission);
};

inline std::ostream& operator<<(std::ostream& os, const TrainingMission::eTrainingType& status) 
{
    switch (status) 
    {
        case TrainingMission::eTrainingType::FITNESS: os << "FITNESS"; break;
        case TrainingMission::eTrainingType::DRIVING: os << "DRIVING"; break;
        case TrainingMission::eTrainingType::TECHNICAL: os << "TECHNICAL"; break;
        case TrainingMission::eTrainingType::COMMAND: os << "COMMAND"; break;
        default:                                   os << "UNKNOWN";    break;
    }
    return os;
};

inline std::ostream& operator<<(std::ostream& os, const TrainingMission::eDifficultyLevel& status) 
{
    switch (status) 
    {
        case TrainingMission::eDifficultyLevel::EASY: os << "EASY"; break;
        case TrainingMission::eDifficultyLevel::MEDIUM: os << "MEDIUM"; break;
        case TrainingMission::eDifficultyLevel::HARD: os << "HARD"; break;
        default:                                   os << "UNKNOWN";    break;
    }
    return os;
};

#endif // TRAINING_MISSION_H
