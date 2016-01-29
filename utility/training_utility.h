//
// Created by Thomas.f.o on 22-10-2015.
//

#ifndef TRAINING_UTILITY_H
#define TRAINING_UTILITY_H
#include <iostream>
#include "training_utility.h"


class TrainingUtility
{
public:
    TrainingUtility();
    static std::string ConvertStringToLowerCase(std::string stringToLower);
    static std::vector<std::string> splitString(std::string stringToSplit, std::string stringToFind);
    static std::string PathToExecutable();
    template <typename T>
    static T UserInput(T inputType);
    static bool CheckIfDirExist(const std::string &dirName);
};

#endif // TRAINING_UTILITY_H
