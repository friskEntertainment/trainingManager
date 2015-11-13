//
// Created by Thomas.f.o on 22-10-2015.
//

#include "stats_control.h"
#include "training_utility.h"
#include <fstream>
#include <boost/filesystem.hpp>

using std::string;
using boost::filesystem::create_directory;
using trainingUtility::TrainingUtility;

StatsControl::StatsControl()
{

}

void StatsControl::CreateExerciseStat(
        string exerciseName,
        int numberOfSets,
        int numberOfReps,
        double weight)
{
    string pathToExecutable = TrainingUtility::PathToExecutable();
    string pathToExerciseStatsFolder = pathToExecutable+"/exercise_stats";
    if(!TrainingUtility::CheckIfDirExist(pathToExerciseStatsFolder))
        create_directory(pathToExerciseStatsFolder);

    std::ofstream exerciseStatsFile;
    exerciseName = TrainingUtility::ConvertStringToLowerCase(exerciseName);
    string exerciseStatsFilePath = pathToExerciseStatsFolder + "/" + exerciseName + string(".txt");
    exerciseStatsFile.open(exerciseStatsFilePath.c_str(), std::ios_base::app);
    exerciseStatsFile << numberOfSets << "\t" << numberOfReps << "\t" << weight << std::endl;
    exerciseStatsFile.close();
}
