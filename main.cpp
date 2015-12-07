#include <iostream>
#include <boost/filesystem.hpp>
#include "stats_view.h"
#include "training_utility.h"

using std::cout;
using std::cin;
using std::string;
using boost::filesystem::portable_directory_name;


int main()
{
    boost::filesystem::path nigger;
    nigger = boost::filesystem::current_path();
    //nigger = full_path(boost::filesystem::current_path());
    //full_path(boost::filesystem::current_path());
    std::cout << "Current path is: " << nigger << std::endl;
    cout << "What do you wish to do?\n"
    <<"Press 1 - Display stats\n"
    <<"Press 2 - Change stats\n";
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
        default:
            break;
    }


    return 0;
}