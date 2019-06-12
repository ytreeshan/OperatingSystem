//
// Created by Treeshan on 4/29/2019.
//

#ifndef TREESHANHOMEPROJECT4_CPU_H
#define TREESHANHOMEPROJECT4_CPU_H

#include <iostream>
#include <list>
#include <string>
#include <cstdlib>
#include "process.h"
using namespace std;

class CPU
{
    //public variables for OS
public:
    CPU();
    bool isIdle();
    void addToCPU(Process p);
    void addTime();
    void termCurrent();
    void exitCPU(Process &p);
    void print();
    int getCurrentPID();
private:
    void assignToCPU();
    Process current;
    list <Process> readyQue[3];
    bool idle;

};


#endif //TREESHANHOMEPROJECT4_CPU_H
