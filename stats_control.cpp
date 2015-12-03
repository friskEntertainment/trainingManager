//
// Created by Thomas.f.o on 22-10-2015.
//

#include <fstream>
#include <map>
#include <algorithm>
#include "stats_control.h"
#include "training_exception.h"
#include <boost/filesystem.hpp>

using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::map;
using boost::filesystem::is_directory;
using boost::filesystem::create_directory;
using boost::filesystem::directory_iterator;
using boost::filesystem::path;

string StatsControl::pathToExecutable = TrainingUtility::PathToExecutable();
string StatsControl::pathToExerciseStatsFolder = pathToExecutable+"/exercise_stats";

StatsControl::StatsControl()
{
}

vector<string> StatsControl::RetrieveAllExerciseStatsNames()
{
    vector<string> exerciseNames;

    try
    {

        boost::filesystem::path pathToExerciseStatsFolder{StatsControl::pathToExerciseStatsFolder+"d"}; //Converts the string path to a boost filesystem path object
        directory_iterator itr{pathToExerciseStatsFolder};
        directory_iterator endItr{}; //Default iterator, which yields pas-the-end.

        while(itr != endItr)
        {
            string exerciseName = itr->path().string();
            exerciseName.erase(0, StatsControl::pathToExerciseStatsFolder.length()+1); //Remove entire path to exercise file name
            exerciseName.erase(exerciseName.length()-4, 4); //Remove file extension .txt of the file

            exerciseNames.push_back(exerciseName);
            ++itr;
        }
    }
    catch (boost::filesystem::filesystem_error exp)
    {
        cout << exp.what();
    }

    return exerciseNames;
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


static std::map<std::string, std::vector<int> > RetrieveExerciseStats()
{

}