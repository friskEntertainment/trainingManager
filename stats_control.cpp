//
// Created by Thomas.f.o on 22-10-2015.
//

#include "stats_control.h"
#include "training_utility.h"
#include <fstream>
#include <boost/filesystem.hpp>
#include <windows.h>

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
    std::cout << TrainingUtility::PathToExecuteable();


    string gg;
    std::cin >> gg;
//    std::ofstream exerciseStatsFile;
//    string exerciseStatsPath = pathToProjectFile + exerciseName + string(".txt");
//    exerciseStatsFile.open(exerciseStatsPath.c_str(), std::ios_base::app);
//    exerciseStatsFile << numberOfSets << "\t" << numberOfReps << "\t" << weight << std::endl;
//    exerciseStatsFile.close();
}
