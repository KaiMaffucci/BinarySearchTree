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

    // insertion
    if (value > wn->data) {
        // insert to right child if number is larger than wn's
        wn->right = Insert(wn->right, value);
    } else if (value < wn->data) {
        // insert to left child if number is less than wn's
        wn->left = Insert(wn->left, value);
    } else {
        // this means an attempt was made to insert a duplicate value
        return wn;
    }

    return wn; // get rid of those pesky warnings
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

    return 0;
}