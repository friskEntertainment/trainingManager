//
// Created by Thomas.f.o on 28-11-2015.
//

#include <iostream>
#include "training_exception.h"

using std::string;

TrainingException::TrainingException()
{

}

const char* TrainingException::what() const throw()
{
    return "Unable to retrieve exercise names\n";
}

