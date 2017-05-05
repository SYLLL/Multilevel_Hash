#include <iostream>
using std::cout;
using std::endl;

#include "Motor.h"
#include "Vehicle.h"
//constructor
Motor::Motor( const int identity, const int theyear, const string& colorful, const int miles, const int eng, const int fro, const int bac)
    : Vehicle(identity, theyear, colorful, miles)
{   
    //setting new things only for motor
    engine = eng;
    front = fro;
    back = bac;
}

// returns engine size
int Motor::getengine() const
{
    return engine;
}
// returns front wheel size
int Motor::getfront() const
{
    return front;
}
// returns back wheel size
int Motor::getback() const
{
    return back; 
}
// virtual print
void Motor::print() const
{
    cout << "{{{printing motor}}}" << endl;
    cout << "Engine: "<< getengine() <<endl;
    cout << "Front: " << getfront() << endl;
    cout << "Back: " << getback() << endl;
    Vehicle::print();
}

//operator overloading
ostream &operator<<( ostream &output, const Motor &c)
{
    c.print();
}
