/* Suyi Liu
 * sliu92@jhu.edu
 * 600.120 Final Project
 * HashNode.h
 */
#ifndef HASHNODE_H
#define HASHNODE_H
#include <iostream>
using std::cout;
using std::endl;
#include "ML_hash.h"
template< typename T > class Structure;

template< typename T >

#define MAX_SIZE 5
//single node of type T in structure
class HashNode
{ 
    friend class Structure< T >;

public: 
    //constructor
    HashNode();
    //destructor
    ~HashNode();
    //num objects stored
    int getnumobject();
    
//    friend ostream &operator<<( ostream &, T* &);
private:
    //array of keys
    int keys[MAX_SIZE];
    //array of pointers to values
    T *values[MAX_SIZE];
    //array of children
    HashNode< T > *next[MAX_SIZE];
    //parent pointer
    HashNode< T > *parent;
    //numobject
    int numobject;
    //in which level is the node
    int level;

};

template< typename T >
HashNode< T >::HashNode()
{   
    //basic construction
    parent = NULL;
    numobject = 0;
    level = 0;
    for (int i=0; i<MAX_SIZE; i++)
    {
        next[i] = NULL;
        keys[i] = 0;
        values[i] = NULL;
    }
}

template< typename T >
HashNode< T >::~HashNode()
{   
    //destructor deleting dynamic memory
    for (int i=0; i<MAX_SIZE; i++)
    {   
        if ( values[i] != NULL)
        {
            values[i] = NULL;
        }
     
        if ( next[i] != NULL)
        {
            delete next[i];
        }
    }   
}

template< typename T >
int HashNode< T >::getnumobject()
{   
    //returns int total number of objects stored beneath
    return numobject;
}
#endif




