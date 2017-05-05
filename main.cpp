#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <vector>
using std::vector;

#include "Vehicle.h"
#include "Car.h"
#include "Hybrid.h"
#include "Motor.h"
#include "Bus.h"
#include "Structure.h"

int main()
{ 
    // Creates structure.
    Structure< Vehicle > *a = new Structure< Vehicle >;
    a->MLH_set_print_option(0);
    int choice = 0; 
    int task = 0;
    int t;
    int input = 0;
    int id, year, mileage;
    int engine, poll, battery;

    string gas;
    string color;
    string service;
    Vehicle *v;
    // Variable specifications.
    int front, back, passenger;
    int powerful; 
    int usage;
    int pa, la;
    int init = 0;
 
    while (init != 4)
    {
        cout << ":::::::600.120 Car Center Main Page::::::" << endl;
	cout << "Do you want to: 1.add a vehicle  2.add tasks  3.checkout/print/ohers  4.bye" <<endl;
        cin>>init;
    //switches choice.
    switch (init)
    case 1:
        while (choice != 5) 
        {
            cout << "Enter int id --->" << endl;
            cin >> id;
            cout << "Enter int year Eg.1949 --->" << endl;
            cin >> year;
            cout << "Enter int mileage --->" << endl;
            cin >> mileage;
            cout << "Enter string color ---> Eg.Pink" << endl;
            cin >> color;
            cout << "Choose a vehicle: " << endl;
            cout << "1.car 2.hybrid 3.motor 4.bus 5.stop adding" << endl;
            cin >> choice;
            //swiches vehicle selection.
            switch (choice) 
            {
                case 1:
                    {
                    cout << "Enter int engine --->" << endl;
                    cin >> engine;
                    cout << "Enter string gas(premium/plus/regular) --->" << endl;
                    cin >> gas;
                    cout << "Enter pollution level(int 1-5) --->" << endl;
                    cin >> poll; 
                    //allocates space for a new car.
                    v = new Car(id, year, color, mileage, engine, gas, poll);
                    a->MLH_insert(id, v); 
                    cout << "The car is added! \n";
                    break;
                    }
            case 2:
                    {
                    //Creating hybrid.
                    cout << "Enter int engine --->" << endl;
                    cin >> engine;
                    cout << "Enter string gas(premium/plus/regular) --->" << endl;
                    cin >> gas;
                    cout << "Enter pollution level(int 1-5) --->" << endl;
                    cin >> poll; 
                    cout << "Enter int overall usage --->" << endl;
                    cin >> usage;
                    cout << "Enter int motor power --->" << endl;
                    cin >> powerful;
                    cout << "Enter int Battery capacity --->" << endl;
                    cin >> battery;
                    v = new Hybrid(id, year, color, mileage, engine, gas, poll, powerful, usage, battery);
                    a->MLH_insert(id, v);
                    cout << "The hybrid is added! \n";
                    break;
                    }
            case 3:
                    {
                    //Creating motor.
                    cout << "Enter int engine --->" << endl;
                    cin >> engine;
                    cout << "Enter int front wheel size---> " << endl;
                    cin >> front;
                    cout << "Enter int back wheel size--->" << endl;
                    cin >> back;
                    v = new Motor(id, year, color, mileage, engine, front, back);
                    a->MLH_insert(id, v);
                    cout << "The motor is added! \n";
                    break;
                    }
            case 4:  
                    {     
                    //Creating bus.
                    cout << "Enter int passenger capacity --->" << endl;
                    cin >> passenger;
                    v = new Bus(id, year, color, mileage, passenger);
                    a->MLH_insert(id, v);
                    cout << "The bus is added! \n";
                    break;
                    }
            default:
                    {        
                    cout << "Stop adding/ Invalid selection! "<< endl;
                    break;
                    }				
            }
            /* Setting choice to previous value.*/
            choice = 0;
            break;
     
     case 2:
  
            while (task != 6)
            {
                cout << "Choose a task: 1.maintanance 2.brake change 3.tune_up 4.wash 5.decoration 6.stop adding task" << endl;
                cin >> task;
                // Switches task among 5 options.
                switch (task)
                {
                    case 1: 
                            {
                            cout << "Indicate cost of parts--->" << endl;
                            cin >> pa;
                            cout << "Indicate cost of labors--->" << endl;
                            cin >> la;
                            cout << "Which vehicle to insert a task? Indicate int id here:\n";
                            cin >> id; 
                            Vehicle *g = a->MLH_get(id);
                            if (g == NULL)
                            {
                                cout << "the vehicle doesn not exist! \n";
                                break;
                            }                  
                            service = "maintanance";
                            // Creates a task and wrap it as a node, inserting
                            g->add(service, pa, la);
                            cout<<"Task added!\n";
                            g = NULL;
                            break;
                            }
                    case 2: 
                            {
                            cout << "Indicate cost of parts--->" << endl;
                            cin >> pa;
                            cout << "Indicate cost of labors--->" << endl;
                            cin >> la;
                            cout << "Which vehicle to insert a task? Indicate id here:\n";
                            cin >> id;
                            Vehicle *g = a->MLH_get(id);
                            if (g == NULL)
                            {
                                cout << "the vehicle doesn not exist! \n";
                                break;
                            }                  
 
                            service = "brake change";
                            a->MLH_get(id)->add(service, pa, la);
                            cout<<"Task added!\n"; 
                            g = NULL;                                                 
                            break;
                            }
                    case 3: 
                            {
                            service = "tune_up";
                            cout << "Indicate cost of parts--->" << endl;
                            cin >> pa;
                            cout << "Indicate cost of labors--->" << endl;
                            cin >> la;
                            cout << "Which vehicle to insert a task? Indicate id here:" << endl;
                            cin >> id;
                            Vehicle *g = a->MLH_get(id);
                            if (g == NULL)
                            {
                                cout << "the vehicle doesn not exist! \n";
                                break;
                            }                  
 
                            a->MLH_get(id)->add(service, pa, la);
                            cout<<"Task added!\n"; 
                            g = NULL;
                            break;
                            }
                    case 4: 
                            { 
                            cout << "Indicate cost of parts--->" << endl;
                            cin >> pa;
                            cout << "Indicate cost of labors--->" << endl;
                            cin >> la;
                            cout << "Which vehicle to insert a task? Indicate id here:" << endl;
                            cin >> id;
                            Vehicle *g = a->MLH_get(id);
                            if (g == NULL)
                            {
                                cout << "the vehicle doesn not exist! \n";
                                break;
                            }                  
 
                            service = "wash";
                            a->MLH_get(id)->add(service, pa, la);
                            cout<<"Task added!\n";
                            g = NULL; 
                            break;
                            }
                    case 5: 
                            {
                            cout << "Indicate cost of parts--->" << endl;
                            cin >> pa;
                            cout << "Indicate cost of labors--->" << endl;
                            cin >> la;
                            cout << "Which vehicle to insert a task? Indicate id here:" << endl;
                            cin >> id; 
                            Vehicle *g = a->MLH_get(id);
                            if (g == NULL)
                            {
                                cout << "the vehicle doesn not exist! \n";
                                break;
                            }                  
                            service = "decoration";
                            a->MLH_get(id)->add(service, pa, la);
                            cout<<"Task added!\n";
                            g = NULL;                          
                            break;
                            }
                    default:
                            {
                            cout << "Stop adding/ Invalid task selection! \n";                         
                            break;
                            }
                }
           }
           task = 0; 
           break;
  
      case 3:
      
           while (input != 6)
      
           {
                cout << "1.Checkout a vehicle" << endl;
                cout << "2.View all vehicles" << endl;
                cout << "3.View single vehicle" << endl;
                cout << "4.Check the current bill of the car" << endl;
                cout << "5.Paint a car (change car color)" << endl;
                cout << "6.Exit check/view" << endl;
                cin >> input;
                switch (input)
                {
                //switches selection.     
                    case 1:
                        {
                        cout << "Enter the vehicle id to checkout" << endl;
                        //gets a vehicle
                        cin >> id;
                        //vehicle pointer created
                        Vehicle *m = a->MLH_get(id);
                        if (m == NULL)
                        {   //vehicle not found.
                            cout << "the vehicle doesn not exist! \n";
                            break;
                        }
                        m->printbill();
                        //deletes the vehicle.
                        m = a->MLH_delete(id);
                        cout << "Vehicle deletion complete!\n";
                        //nullifies pointer
                        m = NULL;
                        break;
                        }
                    case 2: 
                        {
                        cout << "Viewing all the vehicles>>>" << endl; 
                        //prints entire structure.
                        cout << *a;
                        break;
                        }
                    case 3:
                        {
                        cout << "Which vehicle to view?" << endl;
                        cin >> id;
                        Vehicle *n = a->MLH_get(id);
                        if (n == NULL)
                        {
                            cout << "the vehicle doesn not exist! \n";
                            break;
                        }
                        //prints vehicle infomation by calling overloaded operator. 
                        cout << *n;
                        n = NULL;                      
                        break;
                        }
                    case 4:
                        {
                        cout << "Which vehicle to view bill, enter id?" << endl;
                        cin >> id;
                        Vehicle *n = a->MLH_get(id);
                        if (n == NULL)
                        {
                            cout << "the vehicle doesn not exist! \n";
                            break;
                        } 
                        //get sum of costs in the tasklist.
                        cout << "Total cost so far is: $"<<n->getcost() << endl;
                        n = NULL;
                        break;
                        }
                    case 5:
                        {
                        cout << "Which vehicle paint, enter id?" << endl;
                        cin >> id;
                        Vehicle *n = a->MLH_get(id);
                        if (n == NULL)
                        {
                            cout << "the vehicle doesn not exist! \n";
                            break;
                        } 
                        cout << "Change to which color? " << endl;
                        cin >> color;
                        //changes vehicle color string representation.
                        n->setcolor(color);
                        cout << "Vehicle No. "<< id << "Is changed to "<< color << "!" << endl;
                        n = NULL; 
                        break;
                        }
                     default:
                        {
                            cout << "Exiting this level of menu for invalid selection/ Quitting" << endl;
                            break;
                        }
                   }  
             }
             //restores input, in case of infinite loop.
             input = 0;
             break; 
        }
    }
    cout<< "Byebye! Thank you for visiting!" << endl;
    //deletes a.
    delete a;
    a = NULL;
    return 0;
}
