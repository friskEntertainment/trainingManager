//
// Created by Thomas.f.o on 27-01-2016.
//

#include <iostream>
#include "exercise_program_control.h"
#include "../utility/training_utility.h"
#include "../control/exercise_program_control.h"
#include <boost/filesystem/path.hpp>

using std::string;

string ExerciseProgramControl::pathToExecutable = TrainingUtility::PathToExecutable();
string ExerciseProgramControl::pathToExerciseProgramFolder = pathToExecutable+"/exercise_programs";

ExerciseProgramControl::ExerciseProgramControl()
{

}