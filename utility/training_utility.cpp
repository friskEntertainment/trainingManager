//
// Created by Thomas.f.o on 22-10-2015.
//

#include <limits>
#include <boost/filesystem.hpp>
#include <windows.h>
#include <exception>
#include <vector>
#include "training_utility.h"
#include "../control/stats_control.h"
#include <boost/filesystem.hpp>


using std::string;
using std::cin;
using std::cout;
using std::vector;
using std::exception;
using boost::filesystem::directory_iterator;

TrainingUtility::TrainingUtility() {

}

string TrainingUtility::ConvertStringToLowerCase(string stringToLower) {
    for (int i = 0; i < stringToLower.length(); i++) {
        stringToLower[i] = tolower(stringToLower[i]);
    }
    return stringToLower;
}

vector<string> TrainingUtility::splitString(std::string stringToSplit, std::string stringToFind)
{
    vector<string> seperatedString;

    size_t startPosition = 0;
    size_t foundAtPosition = stringToSplit.find_first_of(stringToFind);

    while(foundAtPosition != std::string::npos)
    {
        string subString = stringToSplit.substr(startPosition, foundAtPosition-startPosition);
        seperatedString.push_back(subString);

        startPosition = ++foundAtPosition;
        foundAtPosition = stringToSplit.find(stringToFind, startPosition);
    }

    return seperatedString;
}

bool TrainingUtility::CheckIfDirExist(const std::string &dirPath) {
    if (boost::filesystem::is_directory(dirPath))
        return true;
    else
        return false;
}

string TrainingUtility::PathToExecutable() {
    try
    {
        //current working directory
        boost::filesystem::path pathToExe;
        pathToExe = boost::filesystem::current_path();
        return pathToExe.string();
    }
    catch (exception& e)
    {
        cout << e.what() << "\n";
        int a;
        cin >> a;
    }
}


vector<string> TrainingUtility::RetrieveNamesOfFilesInFolder(string pathToFolder)
{
    vector<string> exerciseNames;

    try
    {
        boost::filesystem::path pathToExerciseStatsFolder{pathToFolder}; //Converts the string path to a boost filesystem path object
        directory_iterator itr{pathToExerciseStatsFolder};
        directory_iterator endItr{}; //Default iterator, which yields past-the-end.

        while(itr != endItr)
        {
            string exerciseName = itr->path().string();
            exerciseName.erase(0, pathToFolder.length()+1); //Remove entire path to exercise file name
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

template<typename T>
T TrainingUtility::UserInput(T inputType) {
    while (!(cin >> inputType)) {
        cout << "invalid input\n";
        cin.clear();
        cin.ignore();
    }
    return inputType;
}

template string TrainingUtility::UserInput(string);

template int TrainingUtility::UserInput(int);

template double TrainingUtility::UserInput(double);
