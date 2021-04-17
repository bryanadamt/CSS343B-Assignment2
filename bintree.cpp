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
void BinTree::displaySideways() const 
{
	sideways(root, 0);
}

//---------------------------- Sideways -------------------------------------
// Helper method for displaySideways
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
void BinTree::sideways(Node* current, int level) const 
{
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
	root = NULL;
	*this = toCopy;
	
	// if (root != toCopy.root && toCopy.root != NULL)
	// {
	// 	makeEmpty();
	// 	assignHelper(root, toCopy.root);
	// }
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
	makeEmptyHelper(root);
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

bool BinTree::operator==(const BinTree &toCopy) const 
{
	return equalityHelper(root, toCopy.root);
}

bool BinTree::operator!=(const BinTree &toCopy) const 
{
	return !equalityHelper(root, toCopy.root);
}

bool BinTree::equalityHelper(const Node* curr, const Node* toCompare) const 
{
	if (curr == NULL && toCompare == NULL)
	{
		return true;
	}

	// Checks if one of the Node is NULL, since we checked that both are not NULL
	// This will also make sure that there is data to be compared
	if (curr == NULL || toCompare == NULL)
	{
		return false;
	}

	// Compare data
	if (*curr->data != *toCompare->data)
	{
		return false;
	}

	// If it reaches this line, means that the data are the same, so check left and right children
	return (equalityHelper(curr->left, toCompare->left) && equalityHelper(curr->right, toCompare->right));
}

ostream& operator<<(ostream& out, const BinTree& toPrint)
{
	toPrint.outHelper(toPrint.root);
	out << endl;
	return out;
}

void BinTree::outHelper(const Node* curr) const
{
	if (curr != NULL)
	{
		outHelper(curr->left);
		cout << *curr->data << " ";
		outHelper(curr->right);
	}
}

bool BinTree::insert(NodeData* toInsert) 
{
	if (root == NULL) {
		cout << "failure" <<endl;
	}
	return insertHelper(root, toInsert);
}

bool BinTree::insertHelper(Node* curr, NodeData* toInsert) 
{
	if (curr == NULL)
	{
		Node *newNode = new Node;
		newNode->data = toInsert;
		newNode->left = NULL;
		newNode->right = NULL;
		curr = newNode;
		cout << " 1 " <<endl;
		return true;
	}
	else if (curr->data == toInsert)
	{
		cout << " 2 " <<endl;
		return false;
	}
	else if (curr->data < toInsert) 
	{
		cout << " 3 " <<endl;
		insertHelper(curr->left, toInsert);
	}
	else if (curr->data > toInsert)
	{
		cout << " 4 " <<endl;
		insertHelper(curr->right, toInsert);
	}
	return true;
}

// bool BinTree::retrieve(const NodeData &toFind, NodeData *&address) const
// {
// 	retrieveHelper(toFind, address, root);
// 	return true;
// }

// void BinTree::retrieveHelper(const NodeData &toFind, NodeData *&address, Node *curNode) const
// {
	
// }

// int main()
// {
// 	BinTree test;
// 	BinTree a(test);

// 	if (test == a) {
// 		cout <<"asd" <<endl;
// 	}
// }