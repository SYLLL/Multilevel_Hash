#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <iomanip>
#include "Structure.h"
#include "random_op.h"

main()
{  
    //creates structure pointer
    Structure< int > *a;
    //random seed
    unsigned int seed;
    //number of opearions and range
    int numop, range;
    int key;
    //to switch
    char rand_op;
    //int data pointer
    int *data;
    //recording number of operations
    int g, d, u;
    int q;
    //allocating spaces
    a = new Structure< int >();
    data = new int;
   
    //getting user inputs
    cout << "Please indicate a range: " << endl;
    cin >> range;
    cout << "Please indicate number of operations: " << endl;
    cin >> numop;
    cout << "Please indicate seed: " << endl;
    cin >> seed;
    cout << "------------------------------" << endl;
    //creates random operator
    Random_operation Rand_op( seed, range);
    //initialization
    g = 0;
    d = 0;
    u = 0;
 
    for ( q = 1; q <= numop; q++) 
    {
        //cout << "Operation: "<< q << endl;
        //randomizes
        Rand_op.Randomize_next_op();
        key = Rand_op.Get_key();
        switch (Rand_op.Get_op())
        {     
            case 'G': 
                //getter
                data = a->MLH_get(key);
                g++;
                break;
            case 'D':
                //deleting
                data = a->MLH_delete(key);
                d++;
                //in case of memory leak
                data = NULL;
                break;
            case 'I':
                data = new int;
                *data = q;
                //insertion
                a->MLH_insert(key, data);
                u++;
                break;
        }

        if (q % (numop/10) == 0 )
        {   
            //prints 10 times
            if ( range > 100 ) {
                a->MLH_set_print_option(1);
            }   else { 
                //prints every node
                a->MLH_set_print_option(0);
            }
            //prints entire structure
            cout << *a;
        }
    }   
    //summary
    cout << "Update: " << u << " times" <<endl;
    cout << "Delete: " << d << " times" <<endl;
    cout << "Get " << g << " times" <<endl;
    cout << "Counter is " << a->getcounter() << endl;
    //frees memory
    delete a;
    a = NULL;
}
