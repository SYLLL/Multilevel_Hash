#include <iostream>
using std::cout;
using std::endl;
#include "List.h"
#include "Task.h"
//Creates a new listnode
ListNode::ListNode(const Task &task)
        : content( task ), next (0)
{ 
//empty 
}
//gets real task
Task ListNode::getTask() const
{
    return content;
}
//constructor
List::List()
{
    first = NULL;
    bill = 0;
};
//destructor deleting entire list
List::~List()
{
    ListNode *pnode;
    
    while (first != NULL)
    {
        pnode = first;
        first = pnode->next;
        delete pnode;
    }
}
//returns int total charge
int List::getbill()
{
    return bill;
}

//insertion taking taskname, parts cost and labor cost
void List::insert( const string &ta, const int i, const int j)
{   
    //traversing
    ListNode *pnode;
    Task *task;
    //task pointer mallocing space
    task = new Task(ta, i, j);
    //creates corresbonding task node
    pnode = new ListNode(*task);    
    //pnode inserted before first
    pnode->next = first;
    //pnode is new first
    first = pnode;
    //updating bill
    bill += i;
    bill += j;
}

//only prints first
void List::printfirst() const
{
    if (first != NULL) {
        //prints single first task
        first->getTask().print();
    } else {
       cout << "no current task"<<endl;
    }
}

//prints all tasks
void List::print() const
{
    cout << "{{{Printing the vehicle tasks}}}" << endl;
    ListNode *pnode;
    pnode = first;
    if (first == NULL)
    {
        cout << "No task exists!" << endl;
    }
    //traverse and print all tasks
    while (pnode != NULL)
    {
        pnode->getTask().print();
        cout << "     |" << endl;
        cout << "     |" << endl;
        pnode = pnode->next; 
    }
    //total charge
    cout << "$Total bill so far: " << bill << endl;
    cout << "{{{Bill complete}}}" << endl;
}
