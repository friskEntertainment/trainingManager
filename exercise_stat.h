//
// Created by Thomas.f.o on 29-11-2015.
//

#ifndef TRAININGMANAGER_EXERCISE_H
#define TRAININGMANAGER_EXERCISE_H

#include <iostream>

class ExerciseStat
{
public:
    ExerciseStat(std::string, int, int, int);
    std::string name;
    int weight = 0;
    int reps = 0;
    int sets = 0;
};


#endif //TRAININGMANAGER_EXERCISE_H
