#ifndef HYBRID_H
#define HYBRID_H

#include <string>
using std::string;
#include "Vehicle.h"
#include "Car.h"
#include <iostream>
using std::ostream;
//Hybrid inherits car
class Hybrid : public Car
{
public:
    Hybrid( const int, const int, const string &, const int, const int, const string &, const int, const int, const int, const int);
    //destructor 
    ~Hybrid();    
    //getters
    int getpower() const;
    
    int getusage() const;

    int getcapacity() const;
    //virtual print
    virtual void print() const;

private:
    //motor power
    int power;
    //motor usage
    int usage;
    //battery capacity
    int capacity;
};
#endif
