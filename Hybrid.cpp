#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;
#include "Car.h"
#include "Hybrid.h"
//Hybrid has all car's functionallities
Hybrid::Hybrid( const int identity, const int theyear, const string& colorful, const int miles, const int eng, const string& ga, const int pol, const int pow, const int use, const int cap)
    : Car(identity, theyear, colorful, miles, eng, ga, pol)
{   
    //sets new values
    power = pow;
    usage = use;
    capacity = cap;
}

// returns motor power
int Hybrid::getpower() const
{
    return power;
}
// returns motor usage
int Hybrid::getusage() const
{
    return usage;
}
// returns battery capacity
int Hybrid::getcapacity() const
{
    return capacity; 
}
// printing method using car's print
void Hybrid::print() const
{
    cout << "{{{printing hybrid specifications:}}}" << endl;
    cout << "Power: "<< getpower() <<endl;
    cout << "Usage: " << getusage() << endl;
    cout << "Capacity: " << getcapacity() << endl;
    Car::print();
}
