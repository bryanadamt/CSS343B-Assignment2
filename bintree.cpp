// ------------------------------------------------ bintree.cpp --------------------------------------------------------
// Bryan Adam Tjendra, CSS 343B
// Created: 12/4/2021
// Date of Last Modification:
// --------------------------------------------------------------------------------------------------------------------
// Purpose - This project is to create a binary search tree class called
//           BinTree along with some additional functions (remove function is not required).
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
// --------------------------------------------------------------------------------------------------------------------

#include "bintree.h"
#include "nodedata.h"

#include <iostream>

using namespace std;

//------------------------- displaySideways ---------------------------------
// Displays a binary tree as though you are viewing it from the side;
// hard coded displaying to standard output.
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
void BinTree::displaySideways() const {
	sideways(root, 0);
}

//---------------------------- Sideways -------------------------------------
// Helper method for displaySideways
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
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

BinTree::BinTree()
{
	root = NULL;
}

BinTree::BinTree(const BinTree &toCopy)
{
	// *this = toCopy;
	root = NULL;
	if (root != toCopy.root && toCopy.root != NULL)
	{
		makeEmpty();
		assignHelper(root, toCopy.root);
	}
}

BinTree::~BinTree()
{
	cout << "yaer" <<endl;
	makeEmpty();
}

bool BinTree::isEmpty() const 
{
	return root == NULL;
}

void BinTree::makeEmpty() 
{
	if (root != NULL)
	{
		makeEmptyHelper(root);
	}
}

void BinTree::makeEmptyHelper(Node* curNode)
{
	if (curNode != NULL)
	{
		makeEmptyHelper(curNode->left);
		makeEmptyHelper(curNode->right);
		delete curNode->data;
		delete curNode;
		curNode = NULL;
	}
}

BinTree& BinTree::operator=(const BinTree &toCopy)
{
	if (root != toCopy.root)
	{
		makeEmpty();
		assignHelper(root, toCopy.root);
	}
	return *this;
}

void BinTree::assignHelper(Node* curr, Node* toCopy) const
{
	if (toCopy != NULL)
	{
		Node *clone = new Node;
		NodeData *cloneND = new NodeData(*toCopy->data);
		clone->data = cloneND;
		curr = clone;

		assignHelper(curr->left, toCopy->left);
		assignHelper(curr->right, toCopy->right);
	}
	else 
	{
		// delete curr->data;
		curr = NULL;
	}
}

bool BinTree::retrieve(const NodeData &toFind, NodeData *&address) const
{
	retrieveHelper(toFind, address, root);
	return true;
}

void BinTree::retrieveHelper(const NodeData &toFind, NodeData *&address, Node *curNode) const
{
	
}

int main()
{
	BinTree test;

	// if (test.isEmpty()) {
	// 	cout <<"asd" <<endl;
	// }

	BinTree a(test);
}