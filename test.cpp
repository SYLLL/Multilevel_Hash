#include "Structure.h"
#include <iostream>

using std::cout;
using std::endl;
main()
{
	Structure< int > *hash;
	int i;
	int *data;
	int key;
cout << "STARTED\n";
	hash = new Structure< int >();
	data = new int;

	cout << endl << "Address of data is  " << data;
	i = 0;
	for( i=0; i< 1000; i++ )
	{	
		data = new int;
		*data = i + 1;
		cout << "\nAdding key " << i+1 << " with data " << *data << "\n";
		bool echo = hash->MLH_insert( i + 1, data );
	        cout << "\nOperation report:  " << echo << "\nPrinting List:";// <<  hash << "n";
	//	hash->MLH_set_print(1);
		cout << *hash;
	}
        cout << "Counter is " << hash->getcounter() << endl;


	for (i = 0; i < 1000; i++)
	{	
		cout << "\nnow delete " << i + 1 << "\n";
		hash->MLH_delete(i + 1);
		cout << "after deletion\n";
	//	hash->MLH_set_print(1);
		cout << *hash;
	}
        cout << "Counter is " << hash->getcounter() << endl;

	for( i=0; i< 100; i++ )
        {
                *data = i + 1;
                cout << "\nAdding key " << i+1 << " with data " << *data << "\n";
                bool echo = hash->MLH_insert( i + 1, data );
                cout << "\nOperation report:  " << echo << "\nPrinting List:";
		cout << *hash;
	}

}


