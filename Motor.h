#ifndef MOTOR_H
#define MOTOR_H

#include <string>
using std::string;
#include <iostream>
using std::ostream;
#include "Vehicle.h"
//motor is a vehicle
class Motor : public Vehicle
{
public:
    //constructor
    Motor( const int, const int, const string &, const int, const int, const int, const int);

    ~Motor();
    //new getters
    int getengine() const;
    
    int getfront() const;

    int getback() const;
    
    virtual void print() const;

    friend ostream &operator<<( ostream &output, const Motor&);
private:
    //engine power
    int engine;
    //front wheel size
    int front;
    //back wheel size
    int back;
};
#endif
