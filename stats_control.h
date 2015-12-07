//
// Created by Thomas.f.o on 22-10-2015.
//

#ifndef STATSCONTROL_H
#define STATSCONTROL_H

#include <iostream>
#include <vector>
#include <map>
#include "training_utility.h"
#include "exercise_stat.h"

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
        static std::vector<std::string> RetrieveAllExerciseStatsNames();
        static std::map<int, std::vector<std::string> > RetrieveExerciseStats(std::string);
};
#endif // STATSCONTROL_H

