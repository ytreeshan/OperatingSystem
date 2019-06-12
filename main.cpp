//Treeshan
//Os Simulation
//May 12 2019



#include "OperatingSystem.h"
#include <cstdlib>
#include <climits>
using namespace std;


void startup(long int &ram, long int &pageSize, short int &numbDisk);

int main()
{
    long int ram;
    long int pageSize;
    short int numbDisk;


    startup(ram, pageSize, numbDisk);


    OS mySim(ram, pageSize, numbDisk);

    string command;

    while(getline(cin, command))
    {

        mySim.doCommand(command);
    }

}

void startup(long int &ram, long int &pageSize, short int &numbDisk)
{
    cout << "  Enter the Memory: ";
    if(!(cin >> ram))
    {
        cerr << "Invalid input, " << endl;
        exit(1);
    }

    cout <<" Enter the page/frame size:  ";
    if(!(cin >> pageSize))
    {
        cerr <<"Invalid input" << endl;
        exit(1);
    }

    cout << "Enter the number of hard disk: ";
    if(!(cin >> numbDisk))
    {
        cerr << "Invalid input" << endl;
        exit(1);
    }

    if(ram > 4000000000)
    {
        cerr << "Error: Enter RAM 4000000000 or less" << endl;
        exit(1);
    }

    if(pageSize > ram)
    {
        cerr << "bad input program exiting!" << endl;
        exit(1);
    }

    if(ram <= 0 || pageSize <= 0 || numbDisk <= 0)
    {
        cerr << "Error: You entered value that are less than or equal to 0" << endl;
        exit(1);
    }

    cout << "Thank you!. Welcome to Treeshan Yeadram SimulationA : " << endl;
    cin.clear();
    cin.ignore(INT_MAX, '\n');

}