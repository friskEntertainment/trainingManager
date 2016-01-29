#include <iostream>
#include <boost/filesystem.hpp>
#include "view/stats_view.h"
#include "view/exercise_program_view.h"
#include "utility/training_utility.h"

using std::cout;
using std::cin;
using std::string;
using boost::filesystem::portable_directory_name;


int main()
{
    bool operateProgram = true;

    while(operateProgram == true)
    {
        boost::filesystem::path nigger;
        nigger = boost::filesystem::current_path();
        //nigger = full_path(boost::filesystem::current_path());
        //full_path(boost::filesystem::current_path());
        std::cout << "Current path is: " << nigger << std::endl;
        cout << "What do you wish to do?\n"
        <<"Press 1 - Display stats\n"
        <<"Press 2 - Change stats\n"
        <<"Press 3 - Choose program\n"
        <<"Press 4 - Exit\n";
        int operationCode = 0;
        cin >> operationCode;

        switch (operationCode)
        {
            case 1 :
                StatsView::DisplayStats();
                break;
            case 2 :
                StatsView::ChangeStats();
                break;
            case 3 :
                ExerciseProgram::ChooseExerciseProgram();
            case 4 :
                operateProgram = false;
            default:
                break;
        }
    }

    return 0;
}