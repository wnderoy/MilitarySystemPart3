#include <iostream>
#include "TrainingMission.h"
#include "Unit.h"
using namespace std;

TrainingMission::TrainingMission(const string &missionName,
                                 Unit *assignedUnit,
                                 eTrainingType trainingType,
                                 eDifficultyLevel difficultyLevel)
    : Mission(missionName, assignedUnit), trainingType(trainingType), difficultyLevel(difficultyLevel) {};


TrainingMission::eTrainingType TrainingMission::getTrainingType() const {
    return trainingType;
};

TrainingMission::eDifficultyLevel TrainingMission::getDifficultyLevel() const {
    return difficultyLevel;
};

bool TrainingMission::setTrainingType(TrainingMission::eTrainingType trainingType) {
    this->trainingType = trainingType;
    return true;
}

bool TrainingMission::setDifficultyLevel(TrainingMission::eDifficultyLevel difficultyLevel) {
    this->difficultyLevel = difficultyLevel;
    return true;
}

bool TrainingMission::improveReadiness()
{
    cout << "Improving readiness for mission: " << getMissionName() << endl;
    return true;
}

std::ostream &operator<<(std::ostream &os, const TrainingMission &trainingMission)
{
    os << "Training Mission Name: " << trainingMission.getMissionName()
       << ", Assigned Unit ID: ";
    if (trainingMission.getAssignedUnit() != nullptr) {
        os << trainingMission.getAssignedUnit()->getUnitId();
    } else {
        os << "~ No Unit Assigned ~";
    }
    os << ", Training Type: " << trainingMission.getTrainingType()
       << ", Difficulty Level: " << trainingMission.getDifficultyLevel()
       << ", Status: " << trainingMission.getStatus();

    return os;
};
