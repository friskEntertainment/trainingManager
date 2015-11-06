//
// Created by Thomas.f.o on 22-10-2015.
//

#include "stats_control.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include "training_utility.h"

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
    TrainingUtility::CheckIfDirExist("exerciseStats");

    exerciseName = TrainingUtility::ConvertStringToLowerCase(exerciseName);

    string mainFile = "stats_control.cpp";
    string pathToProjectFile = __FILE__;

    std::string::size_type index = pathToProjectFile.find(mainFile);

    if(index != std::string::npos)
    {
        pathToProjectFile.erase(index, mainFile.length());
    }

    std::ofstream exerciseStatsFile;
    string exerciseStatsPath = pathToProjectFile + exerciseName + string(".txt");
    exerciseStatsFile.open(exerciseStatsPath.c_str(), std::ios_base::app);
    exerciseStatsFile << numberOfSets << "\t" << numberOfReps << "\t" << weight << std::endl;
    exerciseStatsFile.close();
}
