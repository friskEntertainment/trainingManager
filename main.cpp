#include <iostream>
#include "stats_view.h"

using std::cout;
using std::cin;
using std::string;


int main() {
    cout << "my directory is " << __FILE__ << "\n";
    cout << "What do you wish to do?\n"
    <<"Press 1 - Create program\n"
    <<"Press 2 - Load program\n"
    <<"Press 3 - Display stats\n"
    <<"Press 4 - Change stats\n";
    int operationCode = 0;
    cin >> operationCode;

    switch (operationCode)
    {
        case 1 :
            //call create program function
        case 2 :
            //call load program function
        case 3 :
            StatsView::DisplayStats();
            //call your stats function
        case 4 :
            StatsView::ChangeStats();
            //change stats
        default:
            break;
    }


    return 0;
}