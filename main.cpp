#include <iostream>
#include "stats_view.h"
#include <boost/filesystem.hpp>

using std::cout;
using std::cin;
using std::string;
using namespace boost::filesystem;


int main() {
    path p{"C:\\Windows\\System"};
    std::cout << p.root_name() << '\n';
    std::cout << p.root_directory() << '\n';
    std::cout << p.root_path() << '\n';
    std::cout << p.relative_path() << '\n';
    std::cout << p.parent_path() << '\n';
    std::cout << p.filename() << '\n';

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