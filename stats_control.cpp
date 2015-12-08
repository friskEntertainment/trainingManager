//
// Created by Thomas.f.o on 22-10-2015.
//

#include <fstream>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <string>
#include "stats_control.h"
#include "exercise_stat.h"
#include <boost/filesystem.hpp>

using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::map;
using std::unordered_map;
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
        boost::filesystem::path pathToExerciseStatsFolder{StatsControl::pathToExerciseStatsFolder}; //Converts the string path to a boost filesystem path object
        directory_iterator itr{pathToExerciseStatsFolder};
        directory_iterator endItr{}; //Default iterator, which yields past-the-end.

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
    exerciseStatsFile << numberOfSets << "\t" << numberOfReps << "\t" << weight << "\t" << std::endl;
    exerciseStatsFile.close();
}


unordered_map<int, ExerciseStat*> StatsControl::RetrieveExerciseStats(string exerciseStatName)
{
    std::ifstream exerciseStatsFile;
    exerciseStatsFile.open(StatsControl::pathToExerciseStatsFolder+"/"+exerciseStatName+".txt");

    unordered_map<int, ExerciseStat*> statsInFile;
    int linePosition = 1;

    while(exerciseStatsFile.good())
    {
        string readLine;
        std::getline(exerciseStatsFile, readLine);

        vector<string> seperatedLineInFile = TrainingUtility::splitString(readLine, "\t");
        if(seperatedLineInFile.size() > 0)
        {
            const char * temp1 = seperatedLineInFile[0].c_str();
            const char * temp2 = seperatedLineInFile[1].c_str();
            const char * temp3 = seperatedLineInFile[2].c_str();
            int sets = atoi(temp1);
            int reps = atoi(temp2);
            double weight = atof(temp3);
            ExerciseStat* stat = new ExerciseStat(exerciseStatName, sets, reps, weight);
            statsInFile.emplace(linePosition, stat);
        }
        ++linePosition;
    }

    return statsInFile;
}