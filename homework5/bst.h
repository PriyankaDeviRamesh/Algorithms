#include <iostream>
using namespace std;  

//#ifndef BINARY_SEARCH_TREE
//#define BINARY_SEARCH_TREE

class BinNode;
class BST
{
 public:
  /***** Function Members *****/
  BST();
  bool empty() const;
  bool search(const int & item) const; 
  void insert(const int & item);
  void delete_Node(const int &);
  int preorder();
  int inorder();
  //int postorder();
  int node_count();
  private:
  /***** Node class *****/
  class BinNode
  {
   public:
    int height;
    int data;
    BinNode * left;
    BinNode * right;
    BinNode * parent;
    // BinNode constructors
    // Default -- data part is default int value; both links are null.
    BinNode()
    : left(0), right(0)
    {}

    // Explicit Value -- data part contains item; both links are null.
    BinNode(int item)
    : data(item), left(0), right(0)
    {}
 
  };// end of class BinNode declaration
  
  /***** Data Members *****/
  BinNode * myRoot;
  BinNode * copy_1;
}; // end of class declaration

//#endif

