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
    copy_1 = myRoot;
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

/*
int BST::node_count()
{
int b;
BinNode *llocrptr=copy3;
if(llocrptr!=NULL)
{
b++;
b=node_count();
}
cout<<x;
}

*/
int BST::inorder()
{
int a;
BinNode *locrptr=copy_1;
        if(locrptr!=NULL)
        {
        copy_1=locrptr->left;
        a=inorder();
        cout<<locrptr->data;
        copy_1=locrptr->right;
        a=inorder();
        }
return 0;
}

int BST::preorder()
{

BinNode *locrptr=myRoot;
 while (locrptr)
    {
        if (locrptr->left == NULL)
        {
            cout<<locrptr->data;
            locrptr = locrptr->right;
        }
	    else
            {
            	BinNode* preorder = locrptr->left;
            	while (preorder->right && preorder->right != locrptr)
                preorder = preorder->right;

            	if (preorder->right == locrptr)
            	{
                	preorder->right = NULL;
                	locrptr = locrptr->right;
            	}
	
            	else
            	{
                	cout<<locrptr->data;
                	preorder->right = locrptr;
                	locrptr = locrptr->left;
            	}
       	    }
      }
return 0;
}
void BST::delete_Node(const int & item)
 {
    if (myRoot == 0)
        cout << "\nTree is empty\n";
    else
    {
        BinNode *locptr = myRoot;   
        BinNode *parent = 0;       
        bool found = false;    
        while (!found && locptr != 0)
	{
            if(!found && locptr->data!=item)
                parent = locptr;

            if (item < locptr->data)        
                locptr = locptr->left;

            else if (locptr->data < item)  
                locptr = locptr->right;

            else                           
                found = true;
         }


        if (found)
	{
            if (locptr->left == 0 && locptr->right == 0)
	    {
                if(parent->left==locptr)
                    parent->left = 0;
                else
                    parent->right = 0;
            }

            if((locptr->left != 0 && locptr->right == 0) || (locptr->left == 0 && locptr->right != 0))
	    {
                if(parent->left==locptr)
		{
                        if(locptr->left!=0)
                            parent->left=locptr->left;
                        else
                            parent->left=locptr->right;
                }

                else
		{
                    if(locptr->left!=0)
                        parent->right=locptr->left;
                    else
                        parent->right=locptr->right;
                }

            }

	}

     }
}


