//
// Created by Thomas.f.o on 22-10-2015.
//

#ifndef TRAINING_UTILITY_H
#define TRAINING_UTILITY_H
#include <iostream>

class TrainingUtility
{
public:
    TrainingUtility();
    static std::string ConvertStringToLowerCase(std::string stringToLower);
    template <typename tempType>
    static tempType UserInput(tempType inputType);
    static void CheckIfDirExist(std::string dirName);
};


#endif // TRAINING_UTILITY_H
