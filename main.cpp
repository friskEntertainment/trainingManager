#include <iostream>
#include "stats_view.h"
#include "training_utility.h"

using std::cout;
using std::cin;
using std::string;


int main()
{
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