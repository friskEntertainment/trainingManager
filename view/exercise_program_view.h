//
// Created by Thomas.f.o on 15-01-2016.
//

#ifndef TRAININGMANAGER_EXERCISE_PROGRAM_H
#define TRAININGMANAGER_EXERCISE_PROGRAM_H

#include <iostream>
#include <string>
#include <vector>

class ExerciseProgramView
{
    public:
        ExerciseProgramView();
        static void ChooseExerciseProgram();
        static void DisplayExercisePrograms(const std::vector<std::string>& allExercisePrograms);
};


#endif //TRAININGMANAGER_EXERCISE_PROGRAM_H
