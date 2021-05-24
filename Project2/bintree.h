// --------------------------------------------------bintree.h------------------------------------------------------------
// Kevin Thomas Kehoe CSS502A
// Created: Jan. 14, 2018
// Last Mdofied: Jan. 28, 2018
// --------------------------------------------------------------------------------------------------------------------
// Purpose: Declaration of the methods to create a ADT for a Binary Search Tree
// --------------------------------------------------------------------------------------------------------------------
// Notes: Uses nodedata
// --------------------------------------------------------------------------------------------------------------------

#include "nodedata.h"
#include <cstring>
#include <string>
#include <iostream>
#include <fstream>

class BinTree {
public:
	BinTree();					// constructor
	BinTree(const BinTree &);	// copy constructor
	~BinTree();					// destructor, calls destroy()	
	bool isEmpty() const;		// true if tree is empty, otherwise false
	void makeEmpty();			// make the tree empty so isEmpty returns true
    //---------------------------- operator= ------------------------------------
	BinTree& operator=(const BinTree &); //The assignment operator
	//---------------------------- operator== -----------------------------------
	// Returns true if the two BinTrees are equal. Else, returns false
	bool operator==(const BinTree & tree) const;
	//---------------------------- operator!= -----------------------------------
	// Returns true if the two BinTrees are not equal. Else, returns false
	bool operator!=(const BinTree &) const;
	//----------------------------- insert --------------------------------------
	// Inserts NodeData into BinTree at first leaf where it is less than or 
	// greater than the vlue at parent Node and returns ture if the value is not
	// present in the BinTree. Else, does not insert and returns false
	// Preconditions: NodeData in not NULL
	bool insert(NodeData*);
	//---------------------------- retrieve -------------------------------------
	// Get the NodeData* of a given object in the tree (via pass-by-reference
	// parameter) and to report whether the object is found (true or false).
	bool retrieve(const NodeData &, NodeData *&) const;
	//---------------------------- getHeight ------------------------------------
	// Return the height of the node (lowest reachable point) in the BinTree if 
	// exists else return 0.
	int getHeight(const NodeData &) const;
	//-------------------------- bstreeToArray ----------------------------------
	// Using in order traversal, inserts all data from BinTree into an array 
	// using addToArrayTFromBST
	// Preconditions: Array only contains NULL values
	// Postconditions: Tree is empty
	void bstreeToArray(NodeData*[]);
	//-------------------------- arrayToBSTree ----------------------------------
	// Inserts all data from an array into the BinTree object using 
	// addToBSTFromArray
	// Preconditions: Tree is empty
	// Postconditions:  Array only contains NULL values
	void arrayToBSTree(NodeData*[]);
    //------------------------- displaySideways ---------------------------------
	// Displays a binary tree as though you are viewing it from the side;
	// hard coded displaying to standard output.
	// Preconditions: NONE
	// Postconditions: BinTree remains unchanged.
	void displaySideways() const; // provided below, displays the tree sideways
	//---------------------------- operator<< -----------------------------------
	// Displays a list of tree data in order. Calls inorderHelper
	friend ostream& operator<<(ostream&, BinTree&);
private:
	struct Node {
		NodeData* data;						// pointer to data object
		Node* left;							// left subtree pointer
		Node* right;						// right subtree pointer
	};
	Node* root;								// root of the tree
	int size = 0;							// stores array size
	int pos;
	// utility functions

	//-------------------------- inorderHelper ----------------------------------
	// Uses in oreder traversal, assigns values of BinTree to ostream reference
	void inorderHelper(Node*, ostream &) const;
	//----------------------------- height --------------------------------------
	// Returns the height of passed Node in the Tree if exists. Else returns 0 
	// Preconditions: Root node exists
	int height(Node*) const;
	//---------------------------- copyTree -------------------------------------
	// Copies all values of a BinTree into this BinTree 
	// Preconditions: Both root nodes exists
	void copyTree(Node*&, Node*) const;
	//---------------------------- destroy --------------------------------------
	// Deletes the passed Node and all children of the passed Node
	void destroy(Node*&) const;
	//----------------------- subTreeEqualityCheck ------------------------------
	// Determines if nodes are equal and returns true if they are else false
	// Preconditions: Both root nodes exists
	// Postconditions: N/A
	bool subTreeEqualityCheck(Node*, Node*) const;
	//---------------------------- treeSize -------------------------------------
	// Returns number of nodes in the Bintree.
	// Preconditions: Root node exists
	// Postconditions: N/A
	int treeSize(Node*);
	//------------------------ addToArrayTFromBST -------------------------------
	// Using in order traversal, inserts all data from BinTree into an array
	// Preconditions: Array only contains NULL values
	// Postconditions: Tree is empty
	void addToArrayTFromBST(NodeData*[], Node*);
	//------------------------ addToBSTFromArray---------------------------------
	// Inserts all data from an array into the BinTree object
	// Preconditions: Tree is empty
	// Postconditions:  Array only contains NULL values
	void addToBSTFromArray(NodeData *treeArray[], int start, int end);
	//---------------------------- sideways -------------------------------------
	void sideways(Node*, int) const;	// Helper for displaySideways()
};

ostream& operator<< (ostream&, BinTree&);