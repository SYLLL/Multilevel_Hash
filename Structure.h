/* Suyi Liu
 * sliu92@jhu.edu
 * 600.233
 * Final Project
 * Part 1
 */

#ifndef STRUCTURE_H
#define STRUCTURE_H

#include <iostream>
using std::ostream;
using std::cout;
using std::endl;

#include "random_op.h"
#include "HashNode.h"
#include "ML_hash.h"
#include <stdlib.h>
template< typename T >
ostream & operator<< (ostream &, const Structure< T > &);

template< typename T >
class Structure
{
public:
    /* Constructor and destructor. */
    Structure();
    ~Structure();
    /* Helper method that deletes children nodes of the root. */
    void deleteNode( HashNode< T >* );
    
    /* Insertion method that receives key and pointer to object. */
    bool MLH_insert( int, T* );
    /* Helper method that inserts from a certain root. */
    bool MLH_insert( int, T* , HashNode< T >* );
    /* Hashes the node and inserts its keys and values to sub level.*/
    void HashtheNode( HashNode< T >* );
    /* Simply inserts a key and pointer to object into the node.*/
    bool simpleinsert(int, int , T*, HashNode< T >* );    
    
    /* Main deletion method receiving key as parameter. */ 
    T* MLH_delete( int key );
    /* Finds the leaf node that the key is found. */
    HashNode< T >* findNode(int , HashNode< T >* );
    /* Collapse the node if it has exactly 5 children. */
    void wrap( HashNode< T >* );
    
    /* Main get method receiving a key as parameter. */
    T* MLH_get( int );
    /* Helper method that locates on a root for recursion. */
    T* MLH_get( int, HashNode< T >* );
    
    /* Overloading operator. */
    friend ostream &operator<< <>(ostream &, const Structure< T > &);
    /* Set print option that prints all keys and values. */
    void MLH_print_option( HashNode< T >* ) const;
    /* Method that counts max number of levels of deepest path. */
    int maxlevel( HashNode< T >* ) const;
    /* Specifies print option*/
    void MLH_set_print_option(int opt);
    /* Gets program counter*/
    int getcounter();
private:
    /* Root of the tree. */
    HashNode< T > *root; 
    /* Number of all nodes. */   
    int numnode;
    /* The option of set print. */
    int option;
    /* Counter.*/
    int steps;
};


/* Constructor that creates a root. */
template< typename T >
Structure< T >::Structure()
{   
    /* Constructor allocates space*/
    root = new HashNode< T >();
    numnode = 1;
    option = 1;
    steps = 0;
}

/* Destructor. */
template< typename T >
Structure< T >::~Structure()
{   
    //calls hashnode destructor
    delete root;
    root = NULL;
}


/* Insertion method receiving key and pointer to object T. 
 * Returns true if the object is successfully inserted.
 * Returns false if the combination already exists.*/
template< typename T >
bool Structure< T >::MLH_insert( int k, T *object)
{   
  // cout<< "## Inserting node with key: "<<k<<endl;
   T *obj = MLH_get(k);
   /* If object is not found, insert a new one. 
 *    If it is found and matches our input, meaning already exists, do nothing.
 *    If it is found but doesn't match, update the pointer to object.*/
   if ( obj == NULL )
   {
      // cout << "didn't get" << endl;
       /* Inserts the new key and object into repository.*/
       return MLH_insert(k, object, root);
   } else {
      // cout << "Object already exists!" << endl;
       return false;
   }     
}

/* Helper method that locates root.
 * Returns true if insertion is successfully performed. 
 * Returns false if something wrong happened. */
template< typename T >
bool Structure< T >::MLH_insert( int k, T *object, HashNode< T > *root)
{
  //  cout << "insert called, inserting["<< k <<"]" << endl;
    int b, c;
    /* If the node to be operated is not full, simply insert key and value.
 *     If it contains 5 objects, hashes it and insert the object to sublevel.
 *     If it still has children, hash the index of the root's level and 
 *     insert it again into its indexed children. */
    if (root->numobject < 5) 
    {   
        /* Simple insertion inserting key and value to arrays. */
        return simpleinsert(0, k, object, root);
    } else if (root->numobject == 5) {
        /* Inserts all its five keys and objects into their hashed indices. */
        HashtheNode( root );
      //  cout<<"root hashed! it has numobject: "<<root->numobject<<endl;
        /* Finds the index of inserted key and inserts it into sublevel. */
        b = ML_hash( root->level+1, k ) - 1;
        steps++;
        /* If the node is not created, creates space for it. */
        if (root->next[b] == NULL)
        {
            root->next[b] = new HashNode< T >();
            root->next[b]->parent = root;
            root->next[b]->level = root->level+1;
            numnode++;
        }
        /* Recursion, incase the indexed node still needs hashing. */
        MLH_insert( k, object, root->next[b]);
        steps++;
    } else {
        /* Tries to insert it into the position it should be. */
        c = ML_hash( root->level+1, k ) - 1;
        /* Creates space for the index if it is not created. */
        if (root->next[c] == NULL)
        {
            root->next[c] = new HashNode< T >();
            root->next[c]->parent = root;
            root->next[c]->level = root->level+1;
            numnode++;
        }
        //insert after hashing
        MLH_insert( k, object, root->next[c]);
        steps++;
    }
}

/* The method receives a node, hashes the node if it has 5 objects.*/
template< typename T >
void Structure< T >::HashtheNode( HashNode< T > *nod)
{ 
 //   cout << "Hashcalled" << endl;  
    int key, h;
    T *val;
    /* Hash its keys and objects one by one. */
    for (int j = 0; j < 5; j++) 
    {   
        /* Stores keys and values. */
        key = nod->keys[j];
        val = nod->values[j];
        /* Get the index of the object. */
        h = ML_hash(nod->level+1 , key) - 1;
        /* Creates space for the node if it is not created.*/
        if (nod->next[h] == NULL)
        {   
            nod->next[h] = new HashNode< T >();
            nod->next[h]->parent = nod;
            nod->next[h]->level = nod->level+1;
           //increases number of total nodes
            numnode++;
            steps++;
        }
        /* Simply insert the combination into indexed node
 *         since there won't be insufficient space for it.*/
        simpleinsert( 1, key, val, nod->next[h]);
        steps++;
    }

}

/* Very simple insertion if the node has less than 4 objects. 
 * opt represents whether there is a need to increase all its
 * chain of parents numobjects.
 * If simpleinsert is called by hash the node, no total change
 * in number of nodes.
 * If it is called by insertion, a new node inserted, all its
 * parents should increase numobject by one.
 *
 * Returns true if operation is successfully performed.
 * Returns false if object is not successfully inserted. */
template< typename T >
bool Structure< T >::simpleinsert(int opt, int key, T *v, HashNode< T > *root)
{  
   // cout << "simple called"<<endl;
    /* Finds the first empty space. */
    for (int k = 0; k < 5; k++)   
    {    
        /* Assume a valuable key cannot be zero. */
        if (root->keys[k] == 0)
        {
            root->keys[k] = key;
            root->values[k] = v;
            /* Increase its parents' numobject by one.*/
            if (opt == 0)
            {
                while (root != NULL)
                {
                    root->numobject++;
                    root = root->parent;
                }
            } else {
                /* For the children of newly hashed node. */
                root->numobject++;
            }
            return true;
        }
    }
    return false;
}

/* Deletion method that receives a key integer
 * and deletes its associated object and itself
 * returns pointer to the object if it exists in
 * returns null if it does not exist. */
template< typename T >
T* Structure< T >::MLH_delete(int key)
{   
   // cout << "Deleting k =  " << key << endl;
   // cout<< "## deleting object with key: " << key << endl;
    HashNode< T > *n;
    T *temp;
    int hash;
    bool deletion = false;

    /* Searches potential node first
 *     If the object doesn't exist, return null meaning 
 *     nothing to delete.*/
    n = findNode(key, root);
    //node with key not found
    if (n  == NULL)
    {
        return NULL;
    } else {
        /* Locates specific index of the key. */
        while (n != NULL) {
            /* Searches exact index*/            
            for (int j=0; j<5; j++)
            {   
               /* Don't delete if it is not a leaf*/
               if (n->numobject > 5)
               {
                   break;
               } 
                /* n->keys[j] is the right thing if key exists in
 *                 this node.
 *                 If it does not, just decrease numobjects by one.*/
                if (n->keys[j] == key) 
                {  
                     //saves temp pointer
                     temp = n->values[j];
                     //deletes keys and values in the node   
                     n->keys[j] = 0;
                     n->values[j] = NULL;                            
                }
                             
            } 
            //deletes n's number of objects   
            n->numobject--;
                
            /* Deletes the node if it does not have anything.*/
            if (n->numobject == 0 && n->level != 0)
                {   
                    //records its index from its parent
                    hash = ML_hash(n->level,key) -1;
                    //signals deletion
                    deletion = true;
                }           
           
            /* Collapse all of its children's objects into this node,
 *             making it a leaf.*/
            if (n->numobject == 5 )
            {
                //calling frunction called wrap
                wrap(n);
            }
            /* Traverse up.*/
            n = n->parent;
           
            if (deletion) {
                delete n->next[hash];
                n->next[hash] = NULL;
                //restores deletion signal
                deletion = false;
                numnode--;
            }
        }
        /* Returns pointer to object.*/
        return temp;   
    }
    //not found
    return NULL;
}

/* Finds the leaf where the key we look for exists. 
 * Receives the pointer to root and key
 * and returns the hashnode we find.*/
template< typename T >
HashNode< T >* Structure< T >::findNode(int key, HashNode< T > *root)
{   

    int i;
    /* If it has less than 5 elements, it is a leaf.*/
    if (root->numobject <= 5)
    {   
        // traverse all index in node, once found returns
        for (int j=0; j<5; j++)
        {
            if (root->keys[j] == key)
            {
                return root;
            }
            steps++;
        }
        //not in the leaf
        return NULL;    
    } else {
        /* Keep finding it in the hashed index.*/
        i = ML_hash(root->level+1, key)-1;
        if ( root->next[i] == NULL )
        {   
            //supposed slot has not been created
            return NULL;
        }
        steps++;
        //traverse its children
        return findNode(key, root->next[i]);
    }
}

/* Receives a pointer to the hashnode and
 * collapses all of its children into itself.*/
template< typename T >
void Structure< T >::wrap( HashNode< T > *root)
{ 
  
    //   cout << "wrapping called"<< root->numobject << endl;
    /* z is currently next empty slot of the root's arrays.*/
    int z=0;
    /* Traverse through next[] to get their keys and values.*/
    for (int j=0; j<5; j++) 
    {    
        if (root->next[j] != NULL)
        {
            /* Drags all its keys and values out to root. */
            for (int i=0; i<5; i++)
            {   
                //once it has values
                if (root->next[j]->keys[i] != 0)
                {
                /* Copies and pastes to next avalable spot in parent node.*/ 
                root->keys[z] = root->next[j]->keys[i];
                root->values[z] = root->next[j]->values[i];
                z++;
                }
                steps++;
            }
            /* Deletes the node that has been copied. */
            delete root->next[j];
            root->next[j] = NULL;
            numnode--;
        }
    }
}

/* Getting method that receives a key and returns a pointer
 * to the object we are looking for.*/
template< typename T >
T* Structure< T >::MLH_get(int key)
{
    return MLH_get(key, root);
}

/* Helper method that gets root pointer parameter and a key
 * we are looking for.
 * Returns null if key doesn't exist.
 * Otherwise returns pointer to the associated object.*/
template< typename T >
T* Structure< T >::MLH_get(int key, HashNode< T > *root)
{
    int i;
    
    /* If current root is a leaf, traverse through keys. 
 *     if it contains more than 5 elements, keep searching
 *     the right indexed child.*/
    if (root->numobject <= 5) 
    {
        for (int j=0; j<5; j++)
        {   
            /* Returns pointer to object if it exists.*/
            if (root->keys[j] == key)
            {
                return root->values[j];
                cout << "found\n";
            }
            steps++;
        }
        /* Returns null if key is not in the leaf.*/
        return NULL;
    } 
        /* Finds the hashed index*/
        i = ML_hash(root->level+1, key)-1;
        /* If the child does not exist, return null.*/
        if (root->next[i] == NULL) 
        {
            return NULL;
        }
        /* Recursion, using the child as new root.*/
        return  MLH_get(key, root->next[i]);
}

template< typename T >
/* Operator overloading, taking ostream and structure as input parameters
 * and prints out max number of levels and total number of objects,
 * and number of nodes in the entire structure.
 * It prints all the keys and associated values as an option.*/
ostream &operator<<( ostream &output, const Structure< T > &s )
{   
    //first prints numobjects by calling getnumobjects on the root, which shows all
    cout << "printing-----------"<<endl;
    cout << "[Number of objects:]" << s.root->getnumobject() << endl;
    //calls maxlevel counting method
    cout << "[Number of levels:]" << s.maxlevel(s.root)+1 << endl;
    //prints total number of nodes
    cout << "[Number of nodes:]" << s.numnode << endl;
    if ( s.option == 0 ) 
    {   
        //prints all if set print is 0
        s.MLH_print_option( s.root );
    }
}

template< typename T >
/* Optional print method.
 * Traverses through the structure 
 * and prints all keys and values in the leaves.
 */ 
void Structure< T >::MLH_print_option( HashNode< T > *root) const
{   
    /* If it is the leaf.*/
    if (root->numobject <= 5)
    {
        /* Prints all keys and values it contains by traversing through arrays.*/
        for (int j=0; j<root->numobject; j++)
        {
            if (root->keys[j] != 0)
            {
                cout << "[ K ]: " << root->keys[j] << "  [ V ]: " << *root->values[j];             
                cout << endl;
            }   
        }
    } else {
        /* Print all of its children by recursion. */
        for (int k=0; k<5; k++)
        {
            /* In case the indexed child does not exist.*/
            if( root->next[k] != NULL) 
            {
                /* Its children become new roots.*/
                MLH_print_option( root->next[k] );
            }
        }
    }
}

/* Counts the number of levels the deepest root.
 * Takes pointer to root hashnode as parameter
 * returns integer max level.*/
template< typename T >
int Structure< T >::maxlevel( HashNode< T > *root ) const
{
    /* Max number of objects so far.*/
    int max = 0;
    int index = 0;
    /* Returns the number of levels if it is leaf.*/
    if (root->numobject <= 5)
    {
        return root->level;
    }
    /* Traverse through root's children to see which has potential.*/ 
    for (int i=0; i<5; i++)
    {   
        /* The child shouldn't be null,
 *         and will contain most number of objects among its siblings.*/
        if (root->next[i] != NULL)
        {   
            if (root->next[i]->numobject > max)
            {
            /* Replace max with new largest number of objects.*/
            max = root->next[i]->numobject;
            /* Stores the index of that child.*/
            index = i;
            }
        }
    }
    /* Recursion.*/
    return maxlevel(root->next[index]);    
}

/* Sets print option.*/
template < typename T >
void Structure< T >::MLH_set_print_option(int opti)
{
    option = opti;
}

/* Gets the int counter.*/
template< typename T >
int Structure< T >::getcounter()
{
    return steps;
}
#endif
