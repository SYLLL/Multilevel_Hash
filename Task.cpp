#include <string>
#include <iostream>
using std::cout;
using std::endl;
#include "Task.h"

Task::Task( const string &name, int parts, int labor)
{   
    //pass in variables
    taskname = name;
    taskparts = parts;
    tasklabor = labor;
}

//constant returing string method
string Task::getname() const
{
    return taskname;
}
//gets cost of parts
int Task::getparts() const
{
    return taskparts;
}
//returns cost of labors
int Task::getlabor() const
{
    return tasklabor;
}

void Task::print() const
{  
    //prints task name, part cost and labor cost
    cout << "{{{Printing task}}}" << endl;
    cout << "Taskname: "<< getname() << endl;
    cout << "$Taskparts cost: "<< getparts() << endl;
    cout << "$Tasklabor cost: "<< getlabor() << endl;
}
