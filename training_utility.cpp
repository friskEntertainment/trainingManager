//
// Created by Thomas.f.o on 22-10-2015.
//

#include <limits>
#include <boost/filesystem.hpp>
#include <windows.h>
#include <exception>
#include "training_utility.h"
#include "stats_control.h"

using std::string;
using std::cin;
using std::cout;
using std::exception;

TrainingUtility::TrainingUtility() {

}

string TrainingUtility::ConvertStringToLowerCase(string stringToLower) {
    for (int i = 0; i < stringToLower.length(); i++) {
        stringToLower[i] = tolower(stringToLower[i]);
    }
    return stringToLower;
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
