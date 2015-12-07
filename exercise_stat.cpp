//
// Created by Thomas.f.o on 29-11-2015.
//

#include <iostream>
#include "exercise_stat.h"

using std::string;

ExerciseStat::ExerciseStat(string name, int weight, int reps, int sets)
{
    this->name = name;
    this->weight = weight;
    this->reps = reps;
    this->sets = sets;
}