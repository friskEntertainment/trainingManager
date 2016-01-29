//
// Created by Thomas.f.o on 15-01-2016.
//

#ifndef TRAININGMANAGER_EXERCISE_PROGRAM_H
#define TRAININGMANAGER_EXERCISE_PROGRAM_H

#include <iostream>
#include <string>

class ExerciseProgram
{
    private:
        static std::string pathToExecutable;
        static std::string pathToExercisePrograms;

    public:
        ExerciseProgram();
        static void ChooseExerciseProgram();
        static void DisplayExercisePrograms();
};


#endif //TRAININGMANAGER_EXERCISE_PROGRAM_H
