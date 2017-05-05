#ifndef LIST_H
#define LIST_H
#include <iostream>
using std::cout;
using std::endl;
#include <string>
#include "Task.h"

//Inner type listnode class
class ListNode
{
public :
    //ListNode constructor
    ListNode(const Task &ta);
    //returns task
    Task getTask() const;

private:
    //real task
    Task content;
    //next pointer
    ListNode *next;
    
    friend class List;
};

//list of tasks
class List
{
public:
    //constructor
    List();
    //destructor
    ~List();
    //returns total cost
    int getbill();
    //inserts new task
    void insert(const string &fa, const int, const int);
    //printer
    void print() const;
    //only prints first task
    void printfirst() const;

private:
    //first node in task
    ListNode *first;
    //total cost
    int bill;
};
#endif
