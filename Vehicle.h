#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
using std::string;

#include <iostream>
using std::ostream;

#include "List.h" 

class Vehicle
{
public:
    //takes four parameters
    Vehicle( const int, const int, const string &, const int);
    ~Vehicle();
    //all the setting and getting methods
    void setid( const int );
    int getid() const;

    void setyear( const int );
    int  getyear() const;

    void setcolor( const string &);
    string getcolor() const;

    void setmileage( const int );
    int getmileage() const;

    virtual void print() const;

    void printbill() const;    
    
    int getcost() const;    
    //operator overloading
    friend ostream &operator<<(ostream &, const Vehicle &);
    //adding new task into list
    void add(std::string &,const int , const int);
private:
    //tasklist pointer
    List *tasklist;
    //unique id
    int id;
    //model year
    int year;
    //vehicle color
    string color;
    //vehicle mileage
    int mileage;
};

#endif
