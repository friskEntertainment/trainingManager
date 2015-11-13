//
// Created by Thomas.f.o on 22-10-2015.
//

#include "stats_view.h"
#include "stats_control.h"
#include "training_utility.h"
using std::cout;
using std::string;
using std::cin;
using std::getline;
using trainingUtility::TrainingUtility;

StatsView::StatsView()
{

}

void StatsView::DisplayStats()
{
    cout << "You mad bro";
}

void StatsView::ChangeStats()
{
    cout << "Press 1 - Create exercise stat\n"
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
            cout << "number of sets"; ", then weight\n";
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

