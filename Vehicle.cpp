#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include "Vehicle.h"

#include <string>
using std::string;

#include "List.h"
//constructor setting identity, model year, color and mileage
Vehicle::Vehicle(
    const int identity, const int theyear, const string &colorful, const int miles ) : id(identity), year(theyear), mileage(miles)
{
    setcolor(colorful);
    //mallocs tasklist
    tasklist = new List();
}

//destructor
Vehicle::~Vehicle()
{
    delete tasklist;
    tasklist = NULL;
}
//sets unique id
void Vehicle::setid(const int identity)
{
    id = identity;
}
//returnd unique id
int Vehicle::getid() const
{
    return id;
}
//sets model year
void Vehicle::setyear(const int theyear)
{
    year = theyear;
}
//returns model year
int Vehicle::getyear() const
{
    return year;
}
//sets color
void Vehicle::setcolor(const string &colorful)
{
    color = colorful;
}
//returns color string
string Vehicle::getcolor() const
{
    return color;
}
//sets mileage
void Vehicle::setmileage(const int miles)
{
    mileage = miles;
}
//returns mileage
int Vehicle::getmileage() const
{
    return mileage;
}
//prints id, year, color mileage and current firsttask
void Vehicle::print() const
{   
    cout << "ID: "<< getid() << endl;
    cout << "Year: "<< getyear() << endl;
    cout << "Color: "<< getcolor() << endl;
    cout << "Mileage "<< getmileage() << endl;
    cout << "Current task: " << endl;
    tasklist->printfirst();
}
//adds new task by calling list's method
void Vehicle::add(std::string &tname, const int i, const int j)
{
    tasklist->insert(tname, i, j);
}
//operator overloading
ostream &operator<<(ostream &output, const Vehicle &v)
{
	v.print();
}
//gets total charge
int Vehicle::getcost() const
{
    return tasklist->getbill();
}
//printsbill in task
void Vehicle::printbill() const
{
    tasklist->print();
}
