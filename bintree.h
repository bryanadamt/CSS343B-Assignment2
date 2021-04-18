// ------------------------------------------------ bintree.h --------------------------------------------------------
// Bryan Adam Tjendra, CSS 343B
// Created: 12/4/2021
// Date of Last Modification:
// --------------------------------------------------------------------------------------------------------------------
// Purpose - This project is to create a binary search tree class called
//           BinTree along with some additional functions (remove function is not required).
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
// --------------------------------------------------------------------------------------------------------------------
#ifndef BINTREE_H
#define BINTREE_H

#include <iostream>
#include "nodedata.h"

using namespace std;

class BinTree 
{
	friend ostream& operator<<(ostream& out, const BinTree& toPrint);

public:
	BinTree();						// constructor
	BinTree(const BinTree &toCopy); // copy constructor
	~BinTree();						// destructor, calls makeEmpty

	bool isEmpty() const; // true if tree is empty, otherwise false
	void makeEmpty();	  // make the tree empty so isEmpty returns true

	BinTree& operator=(const BinTree &);
	bool operator==(const BinTree &) const;
	bool operator!=(const BinTree &) const;

	bool insert(NodeData *);
	bool retrieve(const NodeData &, NodeData *&) const;
	void displaySideways() const; // provided below, displays the tree sideways
	int getHeight(const NodeData &) const;

	void bstreeToArray(NodeData* []);
	void arrayToBSTree(NodeData* []);
private:
	struct Node
	{
		NodeData *data; // pointer to data object
		Node *left;		// left subtree pointer
		Node *right;	// right subtree pointer
	};
	Node *root; // root of the tree

	// utility functions
	void sideways(Node *, int) const; // provided below, helper for displaySideways()

	// Helper Functions
	void makeEmptyHelper(Node *&);
	void assignHelper(Node *&, Node *) const;
	bool equalityHelper(const Node *, const Node *) const;
	void outHelper(const Node*) const;
	bool insertHelper(Node *&, NodeData *&);
	void retrieveHelper(const NodeData &, NodeData *&, Node *) const;
	void nodeFinder(Node *, const NodeData * , Node *&) const;
	int getHeightHelper(const Node *) const;
	int toArrayHelper(Node *, NodeData* []);
};

#endif