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
// void BinTree::displaySideways() const {
// 	sideways(oot, 0);
// }

//---------------------------- Sideways -------------------------------------
// Helper method for displaySideways
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
// void BinTree::sideways(Node* current, int level) const {
// 	if (current != NULL) {
// 		level++;
// 		sideways(current->right, level);

// 		// indent for readability, 4 spaces per depth level 
// 		for (int i = level; i >= 0; i--) {
// 			cout << "    ";
// 		}

// 		cout << *current->data << endl;        // display information of object
// 		sideways(current->left, level);
// 	}
// }

BinTree::BinTree() {
	root = new Node();
	root->data = new NodeData();
}

int main() {
	return 0;
}