#include <iostream>

#ifndef BST_H
#define BST_H

class Node {

    private:
        // attributes, instance variables, whatever you'd like to call them
        int data;
        Node* left;
        Node* right;

    public:

        // constructors
        Node(); // default constructor
        Node(int value); // constructor

        // methods
        // note: 'data' is an integer
        Node* Search(Node* wn, int value);
        Node* Insert(Node* wn, int value); // inserts data into tree
        Node* Smallest(Node* wn); // returns smallest node in tree
        Node* Delete(Node* wn, int value); // removes data from tree
        Node* InOrder(Node* wn); // prints all data in the tree in order
};

#endif