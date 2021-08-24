// binary search tree program

#include <iostream>

using namespace std;

class Node {

    int data;
    Node* left;
    Node* right;

    public:
        Node(); // default constructor
        Node(int value); // constructor
        Node* Search(Node* wn, int value);
        Node* Insert(Node* wn, int value); // inserts number into tree
        // InOrder function
        Node* Smallest(Node* wn); // returns smallest node in tree
        Node* Delete(Node* wn, int value); // removes number from tree
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

    return wn; // get rid of those pesky warnings
}

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

    return wn; // get rid of those pesky warnings
}

Node* Node::Delete(Node* wn, int value) {

    // code somewhat resembles Find and Insert, could probably use Find in here 

    // base case
    if (wn == NULL) {
        return wn;
    
    // if the value is less than wn's then the value we're looking for is left
    } else if (wn->data > value) {
        wn->left = Delete(wn, value);
    
    // if the value is more than wn's then the value we're looking for is right
    } else if (wn->data < value) {
        wn->right = Delete(wn, value);
    
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

    return wn; // get rid of warnings
}

int main() {

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

    //Node* test = tree.Smallest(&tree);


    return 0;
}