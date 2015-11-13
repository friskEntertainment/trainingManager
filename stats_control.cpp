//
// Created by Thomas.f.o on 22-10-2015.
//

#include "stats_control.h"
#include "training_utility.h"
#include <fstream>
#include <boost/filesystem.hpp>

using std::string;

StatsControl::StatsControl()
{

}

void StatsControl::CreateExerciseStat(
        string exerciseName,
        int numberOfSets,
        int numberOfReps,
        double weight)
{
    std::ofstream exerciseStatsFile;
    string exerciseStatsPath = TrainingUtility::PathToExecuteable() + "/" + "exercise_stats/" + exerciseName + string(".txt");
    exerciseStatsFile.open(exerciseStatsPath.c_str(), std::ios_base::app);
    exerciseStatsFile << numberOfSets << "\t" << numberOfReps << "\t" << weight << std::endl;
    exerciseStatsFile.close();
}
