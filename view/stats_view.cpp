//
// Created by Thomas.f.o on 22-10-2015.
//

#include "stats_view.h"
#include "../control/stats_control.h"
#include "../utility/exercise_stat.h"
#include <unordered_map>

using std::cout;
using std::endl;
using std::string;
using std::cin;
using std::getline;
using std::vector;
using std::unordered_map;

StatsView::StatsView()
{

}

void StatsView::DisplayStats()
{
    vector<string> exerciseNames = TrainingUtility::RetrieveNamesOfFilesInFolder(StatsControl::pathToExerciseStatsFolder);
    StatsView::DisplayExerciseStatsNames(exerciseNames);

    int operationCode = 0;
    operationCode = TrainingUtility::UserInput(operationCode);

    cout << "chosen exercise is: " << exerciseNames[operationCode-1] << endl;

    unordered_map<int, ExerciseStat*> statsForExercise = StatsControl::RetrieveExerciseStats(exerciseNames[operationCode-1]);

    unordered_map<int, ExerciseStat*>::const_iterator itr = statsForExercise.cbegin();
    unordered_map<int, ExerciseStat*>::const_iterator endItr = statsForExercise.cend();

    for(itr ; itr != endItr ; itr++)
    {
        std::cout << "key: " << itr->first << " values: " << itr->second->name << " sets: " << itr->second->sets << " reps: " << itr->second->reps  << " weight: " << itr->second->weight << endl;
    }
}

void StatsView::DisplayExerciseStatsNames(const vector<string>& exerciseNames)
{
    for (int i = 0; i < exerciseNames.size(); ++i)
    {
        cout << "Press " << i+1 << " - To view stats on: " << exerciseNames[i] << endl;
    }
}

void StatsView::ChangeStats()
{
    cout
    << "Press 1 - Create exercise stat\n"
    << "Press 2 - Edit exercise stats\n";
    int operationCode = 0;
    cin >> operationCode;

    string exerciseName;
    int numberOfSets = 0;
    int numberOfReps = 0;
    double weight = 0;

    string stringType;
    int intType;
    double doubleType;

    switch(operationCode)
    {
        case 1 :
            cout << "Enter name of exercise\n";
            exerciseName = TrainingUtility::UserInput(stringType);
            cout << "number of sets\n";
            numberOfSets = TrainingUtility::UserInput(intType);
            cout << "number of reps\n";
            numberOfReps = TrainingUtility::UserInput(intType);
            cout << "weight\n";
            weight = TrainingUtility::UserInput(doubleType);
            StatsControl::CreateExerciseStat(exerciseName, numberOfSets,  numberOfReps, weight);
            break;
        default:
            break;
    }
}

