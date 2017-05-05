#ifndef CAR_H
#define CAR_H

#include <string>
using std::string;
using std::ostream;
#include "Vehicle.h"
//has all vehicle things
class Car : public Vehicle
{
public:
    Car( const int, const int, const string &, const int, const int, const string &, const int poll);
    ~Car();
    //gets engine
    int getengine() const;
    //gets gas
    string getgas() const;
    //gets pollution level
    int getpoll() const;
    //virtual print function
    virtual void print() const;
    //operator overloading
    friend ostream &operator<<( ostream &output, const Car &);

private:
    //engine size
    int engine;
    //gas type(premium regular or plus)
    string gas;
    //pollution level
    int poll;
};
#endif
