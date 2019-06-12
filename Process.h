//
// Created by Treeshan on 5/1/2019.
//

#ifndef TREESHANHOMEPROJECT4_PROCESS_H
#define TREESHANHOMEPROJECT4_PROCESS_H
#include <iostream>
#include <list>
#include <string>
#include <sstream>
#include <cstdlib>
using namespace std;

class Process
{
public:
    //constructors
    Process();
    Process(const int new_pid);
    //copy constructor
    Process& operator = (const Process &p);
    friend bool operator == (const Process &p1, const Process &p2);
    void timeqMutate(const int &x);
    void pidMutate(const int &x);
    int timeqAccess();
    int pidAccess();
    int queLevelAccess();
    void queLevelMutate(const int &x);
    void diskInfoAccess(int &number, string &file_name);
    void diskInfoMutate(const int &number, const string &file_name);
    void terminate();

//Check if active
    bool active();
    //Increase Time
    void incre_timeq();
    void incre_queLevel();

    string getFilename();
    int getDiskNumb();

private:
    int pid;
    int timeq;
    int queLevel;
    int usingDisk;
    string workFile;
    int pages;
    bool terminated;
};




#endif //TREESHANHOMEPROJECT4_PROCESS_H
