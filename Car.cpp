#include <iostream>
using std::cout;
using std::endl;

#include "Car.h"
//constructor using vehicle constructor
Car::Car( const int identity, const int theyear, const string& colorful, const int miles, const int eng, const string& ga, const int pol)
    : Vehicle(identity, theyear, colorful, miles)
{   
    //sets new things according to parameter
    engine = eng;
    gas = ga;
    poll = pol;
}
//getters
int Car::getengine() const
{
    return engine;
}

string Car::getgas() const
{
    return gas;
}

int Car::getpoll() const
{
    return poll; 
}
//print method overloading
void Car::print() const
{
    cout << "{{{printing car}}}" << endl;
    cout << "Engine: "<< getengine() <<endl;
    cout << "Gas: " << getgas() << endl;
    cout << "Pollution: " << getpoll() << endl;
    //calls vehicle's print
    Vehicle::print();
    
}

//operator overloading
ostream &operator<<( ostream &output, const Car &c)
{
    c.print();
}
