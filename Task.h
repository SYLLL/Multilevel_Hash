#ifndef TASK_H
#define TASK_H

#include <string>
using std::string;

class Task
{
public:
    //constructor
    Task( const string &, int, int);
    //returns string name
    string getname() const;
    //getter
    int getparts() const;
   
    int getlabor() const;
    //prints specifications
    void print() const;

private:
    //private variables
    string taskname;

    int taskparts;

    int tasklabor;

};

#endif
