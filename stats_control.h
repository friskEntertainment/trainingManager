//
// Created by Thomas.f.o on 22-10-2015.
//

#ifndef STATSCONTROL_H
#define STATSCONTROL_H
#include <iostream>

using std::string;

class StatsControl
{
public:
    StatsControl();
    static void CreateExerciseStat(
            string exerciseName,
            int numberOfSets,
            int numberOfReps,
            double oneRM);
};
#endif // STATSCONTROL_H

