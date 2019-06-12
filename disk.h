//
// Created by Treeshan on 5/2/2019.
//

#ifndef TESTINGHOMEPROJECT4_DISK_H
#define TESTINGHOMEPROJECT4_DISK_H

#include <iostream>
#include <list>
#include <string>
#include <cstdlib>
#include "process.h"
using namespace std;

class Disk
{
public:
    Disk();
    bool isIdle();
    void addToDisk(Process p);
    void exitDisk(Process &p);
    void print(const int &x);
private:
    Process current;
    list <Process> diskQue;
    bool idle;

};

#endif //TESTINGHOMEPROJECT4_DISK_H
