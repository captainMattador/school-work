#include <iostream>
#include <iomanip>

using namespace std;

#include "BST.h"

//--- Definition of constructor
BST::BST()
: myRoot(0)
{}

bool BST::empty() const
{ return myRoot == 0; }


bool BST::search(const int & item) const
{
    return recursiveSearch(myRoot, item);
}


bool BST::recursiveSearch(const BinNode * root, const int & item) const
{
    
    if(root == 0)
        return false;
    
    if(root->data == item)
        return true;
    
    else if (item < root->data)
        return recursiveSearch(root->left, item);
    else
        return recursiveSearch(root->right, item);
    
}

void BST::traverseTree(TRAVERSE_STYLE tr) const
{
    switch (tr) {
        case IN_ORDER:
            inOrder(myRoot);
            break;
            
        case PRE_ORDER:
            preOrder(myRoot);
            break;
            
        case POST_ORDER:
            postOrder(myRoot);
            break;
    }
}

void BST::inOrder(const BinNode * root) const
{
    if(root == 0)
        return;
    
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

void BST::postOrder(const BinNode * root) const
{
    if(root == 0)
        return;
    
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}

void BST::preOrder(const BinNode * root) const
{
    if(root == 0)
        return;
    
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

int BST::nodeCount() const
{
    return nodeCount(myRoot);
}

int BST::nodeCount(const BinNode * root) const
{
    int count = 0;
    
    if(root == 0)
        return count;
    
    count += nodeCount(root->left);
    count += nodeCount(root->right);
    
    return count + 1;
}

void BST::insert(const int & item)
{
    BinNode * locptr = myRoot;   // search pointer
    BinNode * parent = 0;        // pointer to parent of current node
    bool found = false;     // indicates if item already in BST
    while (!found && locptr != 0)
    {
        parent = locptr;
        if (item < locptr->data)       // descend left
            locptr = locptr->left;
        else if (locptr->data < item)  // descend right
            locptr = locptr->right;
        else                           // item found
            found = true;
    }
    if (!found)
    {                                 // construct node containing item
        locptr = new BinNode(item);
        if (parent == 0)               // empty tree
            myRoot = locptr;
        else if (item < parent->data )  // insert to left of parent
            parent->left = locptr;
        else                           // insert to right of parent
            parent->right = locptr;
    }
    else
        cout << "Item already in the tree\n";
}