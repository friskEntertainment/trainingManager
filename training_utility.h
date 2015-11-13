//
// Created by Thomas.f.o on 22-10-2015.
//

#ifndef TRAINING_UTILITY_H
#define TRAINING_UTILITY_H
#include <iostream>

namespace trainingUtility
{
    class TrainingUtility
    {
    public:
        TrainingUtility();
        static std::string ConvertStringToLowerCase(std::string stringToLower);
        static std::string PathToExecutable();
        template <typename T>
        static T UserInput(T inputType);
        static bool CheckIfDirExist(std::string dirName);
    };
}

#endif // TRAINING_UTILITY_H
