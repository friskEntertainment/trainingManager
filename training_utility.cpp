//
// Created by Thomas.f.o on 22-10-2015.
//

#include "training_utility.h"
#include "stats_control.h"
#include <limits>

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

void TrainingUtility::CheckIfDirExist(std::string dirName)
{

}

template <typename tempType>
tempType TrainingUtility::UserInput(tempType inputType)
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