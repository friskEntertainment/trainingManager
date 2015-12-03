//
// Created by Thomas.f.o on 28-11-2015.
//

#ifndef TRAININGMANAGER_TRAINING_EXCEPTION_H
#define TRAININGMANAGER_TRAINING_EXCEPTION_H

#include <exception>
#include <iostream>

class TrainingException: public std::exception
{
public:
    TrainingException();
    virtual const char* what() const throw();
};

#endif //TRAININGMANAGER_TRAINING_EXCEPTION_H
