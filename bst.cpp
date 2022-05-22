// binary search tree program
// TODO: proper documentation, makefile, seperate functions and test code into individual files

#include <iostream>
#include "includes/BST.h"

using namespace std;

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

    //Node* test = tree.Smallest(&tree);

    return 0;
}