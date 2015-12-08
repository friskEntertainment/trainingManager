//
// Created by Thomas.f.o on 29-11-2015.
//

#ifndef TRAININGMANAGER_EXERCISE_H
#define TRAININGMANAGER_EXERCISE_H

#include <iostream>

class ExerciseStat
{
public:
    ExerciseStat(std::string, int, int, double);
    std::string name;
    int sets = 0;
    int reps = 0;
    int weight = 0;
};


#endif //TRAININGMANAGER_EXERCISE_H
