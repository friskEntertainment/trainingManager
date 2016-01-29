//
// Created by Thomas.f.o on 15-01-2016.
//

#include <iostream>
#include <vector>
#include "exercise_program_view.h"
#include "../utility/training_utility.h"

using std::cout;
using std::cin;
using std::string;

string ExerciseProgram::pathToExecutable = TrainingUtility::PathToExecutable();
string ExerciseProgram::pathToExercisePrograms = pathToExecutable + "/exercise_programs";

ExerciseProgram::ExerciseProgram()
{ }

void ExerciseProgram::ChooseExerciseProgram()
{
    int operationCode = 0;
    cin >> operationCode;

    string exerciseProgramName;
}

void DisplayExerciseProgram()
{

}