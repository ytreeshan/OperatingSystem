//
// Created by Treeshan 60
// on 4/28/2019.
//

#ifndef TREESHANHOMEPROJECT4_OPERATINGSYSTEM_H
#define TREESHANHOMEPROJECT4_OPERATINGSYSTEM_H

#include <iostream>
#include <list>
#include <cstdlib>
#include <string>
#include <vector>
#include "Memory.h"
#include "CPU.h"
#include "disk.h"
using namespace std;

class OS
{
public:

    OS(const long int &r, const long int &ps, const short int &nd);
    void doCommand(string command);

    //commands to all function
    void command_A();
    void command_Q();
    void command_exit();
    void command_d(const int &number, const string &filename);
    void command_D(const int &number);
    void command_m(const int &address);
    void command_Sr();
    void command_Si();
    void command_Sm();

//variables
private:
    long int ram;
    long int pageSize;
    short int numbDisk;
    long int numbFrame;
    long int numbProcess;

    Memory myMem;
    vector<Disk> myDisk;
    CPU myCPU;

};

#endif //TREESHANHOMEPROJECT4_OPERATINGSYSTEM_H
