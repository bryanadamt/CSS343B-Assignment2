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

//---------------------------- BinTree() -------------------------------------
// Default Constructor
// Preconditions: NONE
// Postconditions: Allocate memory for a BinTree object

BinTree::BinTree()
{
	root = NULL;
}

//---------------------------- BinTree(Bintree &) -------------------------------------
// Copy Constructor
// Preconditions: There has to be another BinTree to copy
// Postconditions: Create a deep copy for a BinTree object.
BinTree::BinTree(const BinTree &toCopy)
{
	*this = toCopy;
}

//---------------------------- ~BinTree -------------------------------------
// Destructor
// Preconditions: There has to be a BinTree object
// Postconditions: BinTree object is deleted completely
BinTree::~BinTree()
{
	makeEmpty();
}

//---------------------------- isEmpty -------------------------------------
// Checks is BinTree object is empty
// Preconditions: There has to be a BinTree object
// Postconditions: BinTree is unchanged
bool BinTree::isEmpty() const 
{
	return root == NULL;
}

//---------------------------- makeEmpty -------------------------------------
// Completely deletes current BinTree object
// Preconditions: There has to be a BinTree object
// Postconditions: BinTree object is deleted completely
void BinTree::makeEmpty() 
{
	makeEmptyHelper(root);
}

//---------------------------- makeEmptyHelper -------------------------------------
// Helper function to makeEmpty
// Preconditions: There has to be a BinTree
// Postconditions: BinTree deleted
void BinTree::makeEmptyHelper(Node*& curNode)
{
	if (curNode != NULL)
	{
		makeEmptyHelper(curNode->left);
		makeEmptyHelper(curNode->right);

		delete curNode->data;
		curNode->data = NULL;
		delete curNode;
		curNode = NULL;
	}
}

//---------------------------- operator= -------------------------------------
// Overload assignment operator
// Preconditions: There has to be another BinTree
// Postconditions: The current BinTree is a deep copy of the other BinTree
BinTree& BinTree::operator=(const BinTree &toCopy)
{
	if (root != toCopy.root)
	{
		makeEmpty();
		assignHelper(root, toCopy.root);
	}
	return *this;
}

//---------------------------- assignHelper -------------------------------------
// Helper function for operator=
// Preconditions: There has to be another BinTree
// Postconditions: The current BinTree is a deep copy of the other BinTree
void BinTree::assignHelper(Node*& curr, Node* toCopy) const
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

//---------------------------- operator== -------------------------------------
// Overload equality operator
// Preconditions: There has to be 2 BinTree objects
// Postconditions: BinTree is unchanged
bool BinTree::operator==(const BinTree &toCopy) const 
{
	return equalityHelper(root, toCopy.root);
}

//---------------------------- operator!= -------------------------------------
// Overload inequality operator
// Preconditions: There has to be 2 BinTree objects
// Postconditions: BinTree is unchanged
bool BinTree::operator!=(const BinTree &toCopy) const 
{
	return !equalityHelper(root, toCopy.root);
}

//---------------------------- equalityHelper -------------------------------------
// Helper function to operator==
// Preconditions: There has to be 2 BinTree objects
// Postconditions: BinTree
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

//---------------------------- operator<< -------------------------------------
// Overload << operator
// Preconditions: NONE
// Postconditions: NONE
ostream& operator<<(ostream& out, const BinTree& toPrint)
{
	toPrint.outHelper(toPrint.root);
	out << endl;
	return out;
}

//---------------------------- outHelper -------------------------------------
// Helper function to operator<<
// Preconditions: NONE
// Postconditions: NONE
void BinTree::outHelper(const Node* curr) const
{
	if (curr != NULL)
	{
		outHelper(curr->left);
		cout << *curr->data << " ";
		outHelper(curr->right);
	}
}

//---------------------------- insert -------------------------------------
// Inserts a new Node to the BinTree
// Preconditions: There has to be a NodeData object
// Postconditions: BinTree is changed if a new Node is inserted
// 				   stays the same if it doesn't
bool BinTree::insert(NodeData* toInsert) 
{
	return insertHelper(root, toInsert);
}

//---------------------------- insertHelper -------------------------------------
// Helper function to insert
// Preconditions: There has to be a NodeData object
// Postconditions: BinTree is changed if a new Node is inserted
// 				   stays the same if it doesn't
bool BinTree::insertHelper(Node*& curr, NodeData*& toInsert) 
{
	if (curr == NULL)
	{
		curr = new Node;
		curr->data = toInsert;
		curr->left = NULL;
		curr->right = NULL;
		return true;
	}
	else if (*curr->data == *toInsert)
	{
		return false;
	}
	else if (*curr->data > *toInsert) 
	{
		insertHelper(curr->left, toInsert);
	}
	else if (*curr->data < *toInsert)
	{
		insertHelper(curr->right, toInsert);
	}
	return true;
}

//---------------------------- retrieve -------------------------------------
// Retrieve the NodeData* of a given object in the tree (via pass-by-reference parameter)
// and to report whether the object is found (true or false).
// Preconditions: There has to be a NodeData object
// Postconditions: address is updated with the address of the 
//  			   NodeData if it's found.
bool BinTree::retrieve(const NodeData &toFind, NodeData *&address) const
{
	retrieveHelper(toFind, address, root);
	return (address != NULL);
}

//---------------------------- retrieveHelper -------------------------------------
// Helper Fucntion to retrieve function
// Preconditions: There has to be a NodeData object
// Postconditions: address is updated with the address of the 
//  			   NodeData if it's found.
void BinTree::retrieveHelper(const NodeData &toFind, NodeData *&address, Node *curr) const
{
	if (curr != NULL) {
		if (*curr->data == toFind)
		{
			address = curr->data;
		}
		else if (*curr->data < toFind)
		{
			retrieveHelper(toFind, address, curr->right);
		}
		else 
		{
			retrieveHelper(toFind, address, curr->left);
		}
	} 
	else 
	{
		address = NULL;
	}
}

//---------------------------- getheight -------------------------------------
// Function to find the maximum height of a given  value in the tree
// Preconditions: There has to be a NodeData object
// Postconditions: BinTree is unchanged
int BinTree::getHeight(const NodeData &nodeToFind) const 
{
	NodeData *address;
	if (!retrieve(nodeToFind, address))
	{
		// Node not found so height is 0;
		return 0;
	}
	Node *goal = NULL;
	nodeFinder(root, address, goal);
	return getHeightHelper(goal);
}

//---------------------------- nodeFinder -------------------------------------
// Attempt to find a node in the tree, given a NodeData
// Preconditions: There has to be a NodeData object
// Postconditions: BinTree is unchanged
void BinTree::nodeFinder(Node* curr, const NodeData* address, Node*& goal) const
{
	if (goal == NULL)
	{
		if (*curr->data == *address)
		{
			goal = curr;
		} 
		else if (*curr->data < *address)
		{
			nodeFinder(curr->right, address, goal);
		}
		else 
		{
			nodeFinder(curr->left, address, goal);	
		}
	}
}

//---------------------------- getheightHelper -------------------------------------
// Helper fucntion to getHeight
// Preconditions: There has to be a NodeData object
// Postconditions: BinTree is unchanged
int BinTree::getHeightHelper(const Node *goal) const
{
	if (goal == NULL)
	{
		return 0;
	}
	int maxLeft, maxRight;
	maxLeft = getHeightHelper(goal->left);
	maxRight = getHeightHelper(goal->right);
	if (maxLeft > maxRight) 
	{
		return maxLeft + 1;
	}
	return maxRight + 1;
}

//---------------------------- bstreeToArray -------------------------------------
// Fill an array of Nodedata* by using an inorder traversal of the tree.
// Preconditions: NONE
// Postconditions: BinTree is deleted, array is filled with the contents of BinTree inorder
void BinTree::bstreeToArray(NodeData* ndArray[]) 
{
	toArrayHelper(root, ndArray);
	makeEmpty();
}

//---------------------------- toArrayHelper -------------------------------------
// Helper fucntion to bsstreeToArray
// Preconditions: NONE
// Postconditions: BinTree is deleted, array is filled with the contents of BinTree inorder
int BinTree::toArrayHelper(Node* curr, NodeData* ndArray[])
{
	if (curr != NULL)
	{
		int left = toArrayHelper(curr->left, ndArray);

		NodeData *nd = curr->data;
		ndArray[left + 1] = nd;
		cout << *ndArray[left + 1] <<endl;

		int right = toArrayHelper(curr->right, ndArray);

		return left + 1 + right;
	} 
	else
	{
		return 0;
	}
}

//---------------------------- arrayToBSTree -------------------------------------
// Builds a balanced BinTree from a sorted array of NodeData* leaving the array filled with NULLs.
// Preconditions: NONE
// Postconditions: A balanced BinTree is created and everything in the array is set to NULL.
void BinTree::arrayToBSTree(NodeData* [])
{

}

//---------------------------- toBSTreeHelper -------------------------------------
// Helper function to arrayToBSTree
// Preconditions: NONE
// Postconditions: A balanced BinTree is created and everything in the array is set to NULL.
void BinTree::toBSTreeHelper(Node* curr, NodeData* ndArray[])
{

}

// int main()
// {
// 	BinTree T, TA, TB;
// 	NodeData *a = new NodeData("a");
// 	NodeData *b = new NodeData("b");
// 	NodeData *c = new NodeData("c");
// 	NodeData *d = new NodeData("d");
// 	NodeData *e = new NodeData("e");
// 	NodeData *f = new NodeData("f");

// 	T.insert(e);
// 	T.insert(f);
// 	T.insert(c);
// 	T.insert(d);
// 	T.insert(b);
// 	T.insert(a);
// 	cout << T << endl;

// 	T.displaySideways();

// 	NodeData *temp;
// 	NodeData ace("c");
// }