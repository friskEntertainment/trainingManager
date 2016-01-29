//
// Created by Thomas.f.o on 22-10-2015.
//

#ifndef STATS_H
#define STATS_H

#include <iostream>
#include <vector>

class StatsView
{
public:
    StatsView();
    static void DisplayStats();
    static void ChangeStats();
    static void DisplayExerciseStatsNames(const std::vector<std::string>& exerciseNames);
};

#endif // STATS_H

