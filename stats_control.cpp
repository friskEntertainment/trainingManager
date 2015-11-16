//
// Created by Thomas.f.o on 22-10-2015.
//

#include <fstream>
#include <map>
#include "stats_control.h"
#include <boost/filesystem.hpp>

using std::string;
using std::vector;
using std::map;
using boost::filesystem::create_directory;

string StatsControl::pathToExecutable = TrainingUtility::PathToExecutable();
string StatsControl::pathToExerciseStatsFolder = pathToExecutable+"/exercise_stats";

StatsControl::StatsControl()
{

}

void StatsControl::CreateExerciseStat(
        string exerciseName,
        int numberOfSets,
        int numberOfReps,
        double weight)
{
    if(!TrainingUtility::CheckIfDirExist(StatsControl::pathToExerciseStatsFolder))
        create_directory(StatsControl::pathToExerciseStatsFolder);

    std::ofstream exerciseStatsFile;
    exerciseName = TrainingUtility::ConvertStringToLowerCase(exerciseName);
    string exerciseStatsFilePath = StatsControl::pathToExerciseStatsFolder + "/" + exerciseName + string(".txt");
    exerciseStatsFile.open(exerciseStatsFilePath.c_str(), std::ios_base::app);
    exerciseStatsFile << numberOfSets << "\t" << numberOfReps << "\t" << weight << std::endl;
    exerciseStatsFile.close();
}

vector<string> RetrieveAllExerciseStatsNames()
{

}

map<string, vector<int> > RetrieveExerciseStats()
{

}