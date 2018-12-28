#include <iostream>
//#include <iomanip>

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
   BinNode * locptr = myRoot;
   bool found = false;
   while (!found && locptr != 0)
   {
      if (item < locptr->data)       // descend left
        locptr = locptr->left;
      else if (locptr->data < item)  // descend right
        locptr = locptr->right;
      else                           // item found
        found = true;
   }
   return found;
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

BinNode* new_Node(int key)
{
    BinNode* node;
    node=myRoot;
    node->data   = data;
    node->left   = NULL;
    node->right  = NULL;
    node->height = 1;
    return(node);
}

BinNode *right_Rotate(BinNode *rot){
    BinNode *obj1 = rot->left;
    BinNode *obj2 = x->right;

    obj1->right = rot;
    rot->left = obj2;

    rot->height = max(height(rot->left), height(rot->right))+1;
    obj1->height = max(height(obj1->left), height(obj1->right))+1;

    return obj1;}

BinNode *left_Rotate(BinNode *rot){
    BinNode *obj1 = rot->right;
    BinNode *obj2 = obj1->left;

    obj1->left = rot;
    rot->right = obj2;

    rot->height = max(height(rot->left), height(rot->right))+1;
    obj1->height = max(height(obj1->left), height(obj1->right))+1;

    return obj1;}

int get_Balance(BinNode *N){
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);}

BinNode* insert(BinNode* node, int key){
    if (node == NULL)
        return(new_Node(key));

    if (key < node->data)
        node->left  = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);
   else
        return node;

    node->height = 1 + max(height(node->left),
                           height(node->right));

    int balance = get_Balance(node);

    if (balance > 1 && key < node->left->key)
        return right_Rotate(node);

    if (balance < -1 && key > node->right->key)
        return left_Rotate(node);

    if (balance > 1 && key > node->left->key)
    {
        node->left =  left_Rotate(node->left);
        return right_Rotate(node);
    }

    if (balance < -1 && key < node->right->key)
    {
        node->right = right_Rotate(node->right);
        return left_Rotate(node);
    }

    return node;
}

