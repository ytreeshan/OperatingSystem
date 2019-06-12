//
// Created by Treeshan on 4/28/2019.
//

#include "OperatingSystem.h"
using namespace std;

OS::OS(const long int &r, const long int &ps, const short int &nd)
{
    ram = r;
    pageSize = ps;
    numbDisk = nd;
    numbFrame = ram / ps;
    numbProcess = 1;
    string command = "";

    //memory how many frames are available
    myMem.setupFrame(numbFrame);

    //number of disks there are
    for(int i = 0; i < numbDisk; i++)
    {
        Disk tempDisk;
        myDisk.push_back(tempDisk);
    }

}

void OS::doCommand(string command)
{

    if(command[0] == 'A' && command.length() == 1)
    {
        command_A();
    }
    else if(command[0] == 'Q' && command.length() == 1)
    {
        command_Q();
    }
    else if(command[0] == 't' && command.length() == 1)
    {
        command_exit();
    }
    else if(command[0] == 'd')
    {
        //variables
        string cmd;
        int number;
        string filename;


        stringstream ss;
        string temp;
        ss << command;

        //error checking
        ss >> cmd;
        if(!(cmd.length() == 3))
        {
            cerr << "Error, bad command given to OS! " << endl;
            exit(1);
        }
        if(!(ss >> number) || number < 0)
        {
            cerr << "Error, bad command given OS!" << endl;
            exit(1);
        }
        ss >> filename;
        if(filename.empty())
        {
            cerr << "Error, bad command given OS!" << endl;
            exit(1);
        }
        ss >> temp;
        if(!temp.empty())
        {
            cerr << "Error, bad command given OS!" << endl;
            exit(1);
        }

        command_d(number, filename);
    }
    else if(command[0] == 'D')
    {

        string cmd;
        int number;


        stringstream ss;
        string temp;
        ss << command;

        //some more error checking
        ss >> cmd;
        if(!(cmd.length() == 3))
        {
            cerr << "bad command enter! " << endl;
            exit(2);
        }
        if(!(ss >> number) || number < 0)
        {
            cerr << "bad command enter" << endl;
            exit(1);
        }
        ss >> temp;
        if(!temp.empty())
        {
            cerr << "bad command enter!" << endl;
            exit(1);
        }

        command_D(number);
    }
    else if(command[0] == 'm')
    {

        string cmd;
        int number;


        stringstream ss;
        string temp;
        ss << command;


























        ss >> cmd;
        if(!(cmd.length() == 2))
        {
            cerr << "Error! " << endl;
            exit(1);
        }
        if(!(ss >> number) || number < 0)
        {
            cerr << "Error!" << endl;
            exit(1);
        }
        ss >> temp;
        if(!temp.empty())
        {
            cerr << "Error!" << endl;
            exit(1);
        }

        command_m(number);
    }
    else if(command[0] == 'S' && command[1] == ' ' &&  command[2] == 'r' && command.length() == 3)
    {
        command_Sr();
    }
    else if(command[0] == 'S' && command[1] == ' ' &&  command[2] == 'i' && command.length() == 3)
    {
        command_Si();
    }
    else if(command[0] == 'S' && command[1] == ' ' &&  command[2] == 'm' && command.length() == 3)
    {
        command_Sm();
    }
    else
    {

        cout << "You entered a bad command!!" << endl;
    }

    command = "";
}

void OS::command_A()
{

    //Create new process
    Process temp(numbProcess);
    numbProcess ++;
    myCPU.addToCPU(temp);
    int memPID = temp.pidAccess();

    myMem.allocate(memPID, 0);

    cout << "Process created! Please enter next command" << endl;
}

void OS::command_Q()
{
    myCPU.addTime();

    cout << "GO BACK IN READY QUEUE " << endl;
}

void OS::command_exit()
{
    int memPID = myCPU.getCurrentPID();

    myCPU.termCurrent();

    myMem.deallocate(memPID);

    cout << "Executing exit command" << endl;
}

void OS::command_d(const int &number, const string &filename)
{
    //Since there are no process that are in CPU right now, we are not doing anything
    if(myCPU.isIdle())
        return;

    Process temp;
    myCPU.exitCPU(temp);//copy the process that was in cpu before to temp
    temp.diskInfoMutate(number, filename);

    if(number > numbDisk -1)
    {
        cerr << "Error, no such Disk " << endl;
        exit(1);
    }

    myDisk[number].addToDisk(temp);

    cout << "Hard disk number enter. Please enter next command. " << endl;
}

void OS::command_D(const int &number)
{
    if(number > numbDisk -1)
    {
        cerr << "Error, no such Disk" << endl;
        exit(1);
    }

    //Since there are no process that are in this Disk right now, we are not doing anything
    if(myDisk[number].isIdle())
        return;

    Process temp;
    myDisk[number].exitDisk(temp);//copy the process that was in Disk to temp

    myCPU.addToCPU(temp);

    cout << "Disk number has finish " << endl;
}

void OS::command_m(const int &address)
{
    int memPID = myCPU.getCurrentPID();
    int page = address / pageSize;
    myMem.updatePM(memPID, page);

    cout << "Request Memory. Please enter Next Command. " << endl;
}

void OS::command_Sr()
{
    cout << "---------------------------------------" << endl;

    myCPU.print();

    cout << "---------------------------------------" << endl;

    cout << "Showing process in ready queue" << endl;
}

void OS::command_Si()
{
    cout << "-----------------------------------" << endl;

    int counter = 0;
    for(auto x : myDisk)
    {
        x.print(counter);
        counter++;
    }
    cout << "Showing hard disk " << endl;

    cout << "----------------------------------" << endl;
}

void OS::command_Sm()
{
    cout << "---------------------------------" << endl;
    cout <<"Show memory. Please enter next command."<<endl;
    myMem.print();

    cout << "---------------------------------" << endl;
}
//void OS::command_fork()
//{


//}