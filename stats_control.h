//
// Created by Thomas.f.o on 22-10-2015.
//

#ifndef STATSCONTROL_H
#define STATSCONTROL_H
#include "training_utility.h"
#include <iostream>
#include <vector>
#include <map>

class StatsControl
{
    private:
        static std::string pathToExecutable;
        static std::string pathToExerciseStatsFolder;

    public:
        StatsControl();
        static void CreateExerciseStat(
                std::string exerciseName,
                int numberOfSets,
                int numberOfReps,
                double oneRM);
        static std::map<std::string, std::vector<int> > RetrieveExerciseStats();
        static std::vector<std::string> RetrieveAllExerciseStatsNames();
};
#endif // STATSCONTROL_H

