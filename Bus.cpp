#include <iostream>
using std::cout;
using std::endl;

#include "Bus.h"
//constructor
Bus::Bus( const int identity, const int theyear, const string& colorful, const int miles, const int pas)
    : Vehicle(identity, theyear, colorful, miles)
{   
    //sets passenger capacity
    passenger = pas;
}
// returns passenger capacity
int Bus::getpassenger() const
{
    return passenger;
}
// print overloading
void Bus::print() const
{
    cout << "{{{printing bus}}}" << endl;
    cout << "Passenger capacity: "<< getpassenger() <<endl;
    Vehicle::print();    
}

//operator overloading
ostream &operator<<( ostream &output, const Bus &c)
{
    c.print();
}
