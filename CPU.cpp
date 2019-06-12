//
// Created by Treeshan  on 4/29/2019.
//


#include "cpu.h"
using namespace std;

CPU::CPU()
{
    //set idle to true
    idle = true;
}

int CPU::getCurrentPID()
{
    //get current PIDAccess
    return current.pidAccess();
}


bool CPU::isIdle()
{
    return idle;
}
//If no process in CPU
void CPU::addToCPU(Process p)
{
    if(idle)
    {
        current = p;
        idle = false;
    }
    else if(current.queLevelAccess() > p.queLevelAccess())
    {
        readyQue[current.queLevelAccess()].push_front(current);
        current = p;
    }
    else if(current.queLevelAccess() <= p.queLevelAccess())
    {
        readyQue[p.queLevelAccess()].push_back(p);
    }
    else
    {
        cerr << "Unexpected Error exiting now !" << endl;
    }
}
//assign PID to cpu for usage.
void CPU::assignToCPU()
{
    if(!readyQue[0].empty())
    {
        current = readyQue[0].front();
        readyQue[0].pop_front();
        idle = false;
    }
    else if(!readyQue[1].empty())
    {
        current = readyQue[1].front();
        readyQue[1].pop_front();
        idle = false;
    }
    else if(!readyQue[2].empty())
    {
        current = readyQue[2].front();
        readyQue[2].pop_front();
        idle = false;
    }
    else //all the queues are empty
    {

        current.terminate();
        idle = true;
    }
}

void CPU::addTime()
{

    if(idle)
        return;

    current.incre_timeq();
    if(current.queLevelAccess() == 0)
    {
        current.queLevelMutate(1);
        current.timeqMutate(0);
        readyQue[current.queLevelAccess()].push_back(current);
        assignToCPU();
    }
    else if(current.queLevelAccess() == 1)
    {

        if(current.timeqAccess() >= 2)
        {
            current.queLevelMutate(2);
            current.timeqMutate(0);
            readyQue[current.queLevelAccess()].push_back(current);
            assignToCPU();
        }
    }
    else if(current.queLevelAccess() == 2)
    {

    }
    else
    {
        cerr << "Unexpected Error program exiting!" << endl;
        exit(1);
    }

}

void CPU::termCurrent()
{
    current.terminate();
    assignToCPU();
}

void CPU::exitCPU(Process &p)
{
    p = current;
    assignToCPU();
}

void CPU::print()
{
    //print table in with PID and ready Queue
    cout << "Process currently using CPU: " << endl;
    if(current.pidAccess() >= 0)
    {
        cout << "\t" << "Process PID: " << current.pidAccess() << " | ";
        cout << "Queue Level: " << current.queLevelAccess() << endl;
    }

    cout << "Process in Ready Queue Level 0: " << endl;
    for(auto x : readyQue[0])
    {
        cout << "\t" << "Process PID: " << x.pidAccess() << endl;
    }

    cout << "Process in Ready Queue Level 1: " << endl;
    for(auto x : readyQue[1])
    {
        cout << "\t" << "Process PID: " << x.pidAccess() << endl;
    }

    cout << "Process in Ready Queue Level 2: " << endl;
    for(auto x : readyQue[2])
    {
        cout << "\t" << "Process PID: " << x.pidAccess() << endl;
    }
}

