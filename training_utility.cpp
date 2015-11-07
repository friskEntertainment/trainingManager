//
// Created by Thomas.f.o on 22-10-2015.
//

#include "training_utility.h"
#include "stats_control.h"
#include <limits>
#include <boost/filesystem.hpp>
#include <windows.h>

using std::string;
using std::cin;
using std::cout;

TrainingUtility::TrainingUtility()
{

}

string TrainingUtility::ConvertStringToLowerCase(string stringToLower)
{
    for(int i = 0 ; i < stringToLower.length() ; i++)
    {
        stringToLower[i] = tolower(stringToLower[i]);
    }
    return stringToLower;
}

void TrainingUtility::CheckIfDirExist(std::string dirPath)
{
    boost::filesystem::is_directory(dirPath);
}

string TrainingUtility::PathToExecuteable()
{
    //current working directory
    char buffer[MAX_PATH];
    std::cout << GetModuleFileName( NULL, buffer, MAX_PATH );
    string::size_type pos = string( buffer ).find_last_of( "\\/" );
    return string( buffer ).substr( 0, pos);
    //string::size_type pos = string( buffer ).find_last_of( "\\/" );
}

template <typename T>
T TrainingUtility::UserInput(T inputType)
{
    while(!(cin >> inputType))
    {
        cout << "invalid input\n";
        cin.clear();
        cin.ignore();
    }
    return inputType;
}
template string TrainingUtility::UserInput(string);
template int TrainingUtility::UserInput(int);
template double TrainingUtility::UserInput(double);