//
// Created by Thomas.f.o on 29-11-2015.
//

#include <iostream>
#include "exercise_stat.h"

using std::string;

ExerciseStat::ExerciseStat(string name, int sets, int reps, double weight)
{
    this->name = name;
    this->sets = sets;
    this->reps = reps;
    this->weight = weight;
}