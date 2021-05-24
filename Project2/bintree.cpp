// -----------------------------------------------bintree.cpp----------------------------------------------------------
// Kevin Thomas Kehoe CSS502A
// Created: Jan. 14, 2018
// Last Mdofied: Jan. 28, 2018
// --------------------------------------------------------------------------------------------------------------------
// Purpose: Implimentation of the methods to create a ADT for a Binary Tree called BinTree  
// --------------------------------------------------------------------------------------------------------------------
// Notes: Uses nodedata
// --------------------------------------------------------------------------------------------------------------------

#include "bintree.h"

BinTree::BinTree() { // constructor
	root = NULL;
}

BinTree::BinTree(const BinTree & original) { // copy constructor
	if (original.root == NULL)
		root = NULL;
	else {
		makeEmpty();
		copyTree(root, original.root);
	}
}

BinTree::~BinTree() { // destructor, calls destroy()	
	destroy(root);
}

bool BinTree::isEmpty() const { // true if tree is empty, otherwise false
	return (root == NULL);
}

void BinTree::makeEmpty() { // make the tree empty so isEmpty returns true
	if (!isEmpty()) {
		destroy(root->left);
		destroy(root->right);
		delete root;
		root = NULL;
	}
}

//---------------------------- operator= ------------------------------------
BinTree & BinTree::operator=(const BinTree &original) {
	if (this != &original) {
		if (root != NULL)
			destroy(root);
		if (original.root == NULL)
			root = NULL;
		else {
			makeEmpty();
			copyTree(root, original.root);
		}
	}
	return *this;
}

//---------------------------- operator== -----------------------------------
bool BinTree::operator==(const BinTree &tree) const {
	if (this == &tree)
		return true;
	if (this->isEmpty() && tree.isEmpty())
		return true;
	if ((!(this->isEmpty()) && tree.isEmpty()) || (this->isEmpty() && !(tree.isEmpty())))
		return false;
	else {
		return tree.subTreeEqualityCheck(this->root, tree.root);
	}
	return true;
}

//---------------------------- operator!= -----------------------------------
bool BinTree::operator!=(const BinTree &tree) const {
	if (*this == tree)
		return false;
	return true;
}

//----------------------------- insert --------------------------------------
bool BinTree::insert(NodeData *value) {
	Node* curr, *tail = NULL, *newNode;
	newNode = new Node;
	newNode->data = value;
	newNode->left = NULL;
	newNode->right = NULL;
	// Find Location for insertion
	if (root == NULL)
		root = newNode;
	else {
		curr = root;
		while (curr != NULL) {
			tail = curr;
			if (*curr->data == *value) { // Checks if value is already present
				return false;
			}
			else if (*curr->data > *value)
				curr = curr->left;
			else {
				curr = curr->right;
			}
		}
		// Insert node in proper location
		if (*tail->data > *value)
			tail->left = newNode;
		else
			tail->right = newNode;
	}
	return true;
}

//---------------------------- retrieve -------------------------------------
bool BinTree::retrieve(const NodeData & item, NodeData *& value) const {
	Node *curr = NULL;
	if (root == NULL) {
		return false;;
	}
	else {
		curr = root;
		while (curr != NULL) {
			if (*curr->data == item) {
				value = curr->data;
				return true;
			}
			else if (*curr->data > item)
				curr = curr->left;
			else
				curr = curr->right;
		}
	}
	return false;
}

//---------------------------- getHeight ------------------------------------
int BinTree::getHeight(const NodeData &item) const {
	Node *curr = root;
	if (root == NULL) {
		return 0;
	}
	while (curr != NULL) {
		if (*curr->data == item) {
			return height(curr) + 1;
		}
		else if (*curr->data > item)
			curr = curr->left;
		else
			curr = curr->right;
	}
	return 0;
}

//---------------------------- operator<< -----------------------------------
ostream & operator<<(ostream &out, BinTree &tree) {
	tree.inorderHelper(tree.root, out);
	out << endl;
	return out;
}

//------------------------- displaySideways ---------------------------------
void BinTree::displaySideways() const {
	sideways(root, 0);
}

//-------------------------- inorderHelper ----------------------------------
void BinTree::inorderHelper(Node *p, ostream &out) const {
	if (p != NULL) {
		if (p->left) inorderHelper(p->left, out);
		out << *p->data << " ";
		if (p->right) inorderHelper(p->right, out);
	}
	else 
		return;
}

//----------------------------- height --------------------------------------
int BinTree::height(Node *h) const {
	int l = 0, r = 0;
	if (h == NULL) {
		return 0;
	}
	if (h->left == NULL && h->right == NULL) {
		return 0;
	}
	else {
		l = height(h->left);
		r = height(h->right);

		if (l>r) {
			l = l + 1;
			return l;
		}
		else {
			r = r + 1;
			return r;
		}
	}
}

//---------------------------- copyTree -------------------------------------
void BinTree::copyTree(Node *& treeCopy, Node *original) const {
	if (original == NULL) {
		treeCopy = NULL;
	}
	else {
		treeCopy = new Node;
		treeCopy->data = original->data;
		copyTree(treeCopy->left, original->left);
		copyTree(treeCopy->right, original->right);
	}
}

//---------------------------- destroy --------------------------------------
void BinTree::destroy(Node *& p) const {
	if (p != NULL) {
		destroy(p->left);
		destroy(p->right);
		delete p;
		p = NULL;
	}
}

//----------------------- subTreeEqualityCheck ------------------------------
bool BinTree::subTreeEqualityCheck(Node * r1, Node * r2) const {
	if (r1 == NULL && r2 == NULL) // Nothing left in the subtree
		return true;
	if (r1 == NULL || r2 == NULL) // Big tree empty and subtree not found
		return false;
	if (*r1->data == *r2->data)	// Not matching 
		return true;
	return (subTreeEqualityCheck(r1->left, r2->left) && subTreeEqualityCheck(r1->right, r2->right));
}

//---------------------------- treeSize -------------------------------------
int BinTree::treeSize(Node *n) {
	if (n == NULL)
		return 0;
	else
		return 1 + treeSize(n->left) + treeSize(n->right);
}

//-------------------------- bstreeToArray ----------------------------------
void BinTree::bstreeToArray(NodeData *treeArray[]) {
	size = 0;
	pos = 0;
	size = treeSize(root);
	addToArrayTFromBST(treeArray, root);
	pos = 0;
	makeEmpty();
}

//------------------------ addToArrayTFromBST -------------------------------
void BinTree::addToArrayTFromBST(NodeData *treeArray[], Node* n) {
	if (n != NULL) {
		addToArrayTFromBST(treeArray, n->left);
		treeArray[pos++] = n->data;
		addToArrayTFromBST(treeArray, n->right);
	}
}

//-------------------------- arrayToBSTree ----------------------------------
void BinTree::arrayToBSTree(NodeData *treeArray[]) {
	addToBSTFromArray(treeArray, 0, size - 1);
	size = 0;
}

//------------------------ addToBSTFromArray---------------------------------
void BinTree::addToBSTFromArray(NodeData *treeArray[], int start, int end) {
	int mid = (start + end) / 2;
	if (start <= end && treeArray[mid] != NULL) {
		insert(treeArray[mid]);
		treeArray[mid] = NULL;
		addToBSTFromArray(treeArray, start, mid - 1);
		addToBSTFromArray(treeArray, mid + 1, end);
	}
}

//---------------------------- sideways -------------------------------------
void BinTree::sideways(Node* current, int level) const {
	if (current != NULL) {
		level++;
		sideways(current->right, level);

		// indent for readability, 4 spaces per depth level 
		for (int i = level; i >= 0; i--) {
			cout << "    ";
		}

		cout << *current->data << endl;        // display information of object
		sideways(current->left, level);
	}
}