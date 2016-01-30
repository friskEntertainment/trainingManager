//
// Created by Thomas.f.o on 15-01-2016.
//

#include <iostream>
#include <vector>
#include <string>
#include "exercise_program_view.h"
#include "../utility/training_utility.h"
#include "../control/stats_control.h"
#include "../control/exercise_program_control.h"

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::endl;

ExerciseProgramView::ExerciseProgramView()
{ }

void ExerciseProgramView::ChooseExerciseProgram()
{
    vector<string> allExercisePrograms = TrainingUtility::RetrieveNamesOfFilesInFolder(ExerciseProgramControl::pathToExerciseProgramFolder);

    DisplayExercisePrograms(allExercisePrograms);
    int operationCode = 0;
    operationCode = TrainingUtility::UserInput(operationCode);

    cout << "chosen exercise is: " << allExercisePrograms[operationCode-1] << endl;
    string exerciseProgramName;
}

void ExerciseProgramView::DisplayExercisePrograms(const vector<string>& allExercisePrograms)
{
    for(int i = 0 ; i < allExercisePrograms.size() ; ++i)
    {
        cout << "Press " << i+1 << " - To view: " << allExercisePrograms[i] << endl;
    }
}