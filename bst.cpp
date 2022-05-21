// binary search tree program
// TODO: proper documentation, makefile, seperate functions and test code into individual files

#include <iostream>

using namespace std;

class Node {

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

// default constructor function
Node::Node() {
    left = NULL;
    right = NULL;
    data = 0;
}

// constructor function
Node::Node(int value) {
    left = NULL;
    right = NULL;
    data = value;
}

// finds node in tree with particular data value
Node* Node::Search(Node* wn, int value) {
    // search
    if (wn->data > value) {
        // if value is greater than wn's number, cont. search right
        Search(wn->right, value);
    } else if (wn->data < value) {
        // if value is greater than wn's number, cont. search left
        Search(wn->left, value);
    } else {
        // the correct node has been found
        return wn;
    }

    return wn; // get rid of those pesky warnings
}

// inserts number into tree
Node* Node::Insert(Node* wn, int value) {

    if (!wn) {
        // if wn is null, make it
        return new Node(value);
    }

    // insertion process begins
    // insert to right child if number is larger than wn's
    if (value > wn->data) {
        wn->right = Insert(wn->right, value);
    
    // insert to left child if number is less than wn's
    } else if (value < wn->data) {
        wn->left = Insert(wn->left, value);
    
    // this means an attempt was made to insert a duplicate value
    } else {
        return wn;
    }

    return wn; // get rid of those pesky warnings, maybe do stuff with it too
}

// returns smallest node in tree
Node* Node::Smallest(Node* wn) {

    // base case
    if (wn == NULL) {
        return wn;
    // have arrived at smallest node
    } else if (wn->left == NULL) {
        return wn;
    // need to keep going
    } else {
        return wn->Smallest(wn->left);
    }

    return wn; // get rid of those pesky warnings, maybe do stuff with it too
}

// deletes an item from the tree
Node* Node::Delete(Node* wn, int value) {

    // code somewhat resembles Find and Insert, could probably use Find in here 

    // base case
    if (wn == NULL) {
        return wn;
    
    // if the value is less than wn's then the value we're looking for is left
    } else if (wn->data > value) {
        wn->left = Delete(wn->left, value); // parameter changed from wn to wn->left
    
    // if the value is more than wn's then the value we're looking for is right
    } else if (wn->data < value) {
        wn->right = Delete(wn->right, value); // parameter changed from wn to wn->right
    
    // this should be the only case where the wn is the node we're looking for
    } else {

        // no child (is leaf)
        if (wn->left == NULL and wn->right == NULL) {
            return NULL;

        // one child
        } else if (wn->left == NULL) {
            Node* temp = wn->right;
            free(wn); // doesn't call deconstructor
            return temp;
        } else if (wn->right == NULL) {
            Node* temp = wn->left;
            free(wn); // doesn't call deconstructor
            return temp;
        
        // two children
        } else {
            // get sucessor node
            Node* temp = wn->Smallest(wn->right);
            // replace data in current node with successor data
            wn->data = temp->data;
            // delete original successor node
            wn->right = Delete(wn->right, temp->data);
        }
    }

    return wn; // get rid of warnings, can maybe do stuff with it too
}

// TODO: test - problem i could see happening is that it tries to access somewhere it can't, but i'm not too worried
Node* Node::InOrder(Node* wn) {

    // if wn isn't empty, do stuff
    if (wn != NULL) {
        // wn isn't NULL so it must have data, print it
        cout << wn->data << endl;

        // if it has a left child, run InOrder with left node
        if ( wn->left != NULL ) {
            //wn->left = 
            wn->InOrder(wn->left);
        }

        // if it has a right child, run InOrder with right node
        if ( wn->right != NULL ) {
            //wn->right = 
            wn->InOrder(wn->right);
        }
    }

    return wn; // this is actually more crucial here than it is in the other methods
}

int main() {

    // all test code

    /*Node tree, *root = NULL;
    root = tree.Insert(root, 5);*/
    /*Node tree(5);
    Node* root = &tree;*/
    /*tree.Insert(root, 7);
    tree.Insert(root, 4);
    tree.Insert(root, 9);*/

    Node tree(5);

    tree.Insert(&tree, 7);
    tree.Insert(&tree, 4);
    tree.Insert(&tree, 9);
    tree.Insert(&tree, 6);

    tree.Delete(&tree, 7);

    tree.InOrder(&tree);
    // test

    //Node* test = tree.Smallest(&tree);

    return 0;
}