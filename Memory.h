//
// Created by Treeshan on 4/27/2019.
//

#ifndef TREESHANHOMEPROJECT4_MEMORY_H
#define TREESHANHOMEPROJECT4_MEMORY_H

#include <stack>
#include "process.h"
using namespace std;

class MemEntry
{
public:

    MemEntry(const int &new_pid, const int &new_page, const int &new_frame);
    int getFrame();
    int getPID();
    int getPage();
    void changePID(const int &x);
    void print();

    MemEntry& operator = (const MemEntry &m);
    friend bool operator == (const MemEntry &m1, const MemEntry &m2);


private:
    int frame;
    int page;
    int pid;
};


class Memory
{
public:

    void allocate(const int &processPID, const int &pageNumb);
    void deallocate(const int &processPID);
    void updatePM(const int &processPID, const int &pageNumb);
    void setupFrame(const int &x);
    void print();
private:
    list <MemEntry> memTable;
    stack <int> availFrame;
};

#endif //TREESHANHOMEPROJECT4_MEMORY_H
