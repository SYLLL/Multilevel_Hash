#ifndef BUS_H
#define BUS_H

#include <string>
using std::string;
#include <ostream>
using std::ostream;
#include "Vehicle.h"
//Bus is a vehicle
class Bus : public Vehicle
{
public:
    //constructor and destructor
    Bus( const int, const int, const string &, const int, const int);
    
    ~Bus();
    //gets passenger capacity
    int getpassenger() const;
    //overloading print
    virtual void print() const;

    friend ostream &operator<<( ostream &output, const Bus &);
private:
    //passenger capacity
    int passenger;
};
#endif
