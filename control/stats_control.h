//
// Created by Thomas.f.o on 22-10-2015.
//

#ifndef STATSCONTROL_H
#define STATSCONTROL_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include "../utility/training_utility.h"
#include "../utility/exercise_stat.h"

class StatsControl
{
    public:
        static std::string pathToExecutable;
        static std::string pathToExerciseStatsFolder;

        StatsControl();
        static void CreateExerciseStat(
                std::string exerciseName,
                int numberOfSets,
                int numberOfReps,
                double oneRM);
        static std::vector<std::string> RetrieveAllExerciseStatsNames();
        static std::unordered_map<int, ExerciseStat*> RetrieveExerciseStats(std::string);
};
#endif // STATSCONTROL_H

