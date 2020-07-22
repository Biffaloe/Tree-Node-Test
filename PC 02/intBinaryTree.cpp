#include "intBinaryTree.h"
#include <iostream>
using namespace std;

void intBinaryTree::insert(TreeNode *&nodePtr, TreeNode *&newNode)
{
	if (nodePtr == nullptr)
		nodePtr = newNode; //inserts the node.
	else if (newNode->value < nodePtr->value)
		insert(nodePtr->left, newNode); //Searches the left branch
	else
		insert(nodePtr->right, newNode); //Searches the right branch.
}


//Deletes all nodes in the tree
void intBinaryTree::destroySubTree(TreeNode *nodePtr)
{
	if (nodePtr)
	{
		if (nodePtr->left)
			destroySubTree(nodePtr->left);
		if (nodePtr->right)
			destroySubTree(nodePtr->right);
		delete nodePtr;
	}
}

void intBinaryTree::deleteNode(int num, TreeNode *&nodePtr)
{
	if (num < nodePtr->value)
		deleteNode(num, nodePtr->left);
	else if (num > nodePtr->value)
		deleteNode(num, nodePtr->right);
	else
		makeDeletion(nodePtr);
}

void intBinaryTree::makeDeletion(TreeNode *&nodePtr)
{
	//Define a temporary pointer to use in reattaching
	//the left subtree.
	TreeNode *tempNodePtr = nullptr;

	if (nodePtr == nullptr)
		cout << "Cannot delete empty node.\n";
	else if (nodePtr->right == nullptr)
	{
		tempNodePtr = nodePtr;
		nodePtr = nodePtr->left;  //Reattach the left child.
		delete tempNodePtr;
	}
	else if (nodePtr->left == nullptr)
	{
		tempNodePtr = nodePtr;
		nodePtr = nodePtr->right;  //Reattach the right child.
		delete tempNodePtr;
	}

	//If the node has two children
	else
	{
		// Move one node to the right
		tempNodePtr = nodePtr->right;
		// Go to the end left node
		while (tempNodePtr->left)
			tempNodePtr = tempNodePtr->left;
		// Reattach the left subtree
		tempNodePtr->left = nodePtr->left;
		tempNodePtr = nodePtr;
		// Reattach the right subtree.
		nodePtr = nodePtr->right;
		delete tempNodePtr;

	}
}


//***************************************************
// Displays all values via inorder traversal		*
//***************************************************
void intBinaryTree::displayInOrder(TreeNode *NodePtr) const
{
	if (NodePtr)
	{
		displayInOrder(NodePtr->left);
		cout << NodePtr->value << endl;
		displayInOrder(NodePtr->right);
	}
}


//***************************************************
// Displays all values via preorder traversal		*
//***************************************************
void intBinaryTree::displayPreOrder(TreeNode *nodePtr) const
{
	if (nodePtr)
	{
		cout << nodePtr->value << endl;
		displayPreOrder(nodePtr->left);
		displayPreOrder(nodePtr->right);
	}
}


//***************************************************
// Displays all values via postorder traversal		*
//***************************************************
void intBinaryTree::displayPostOrder(TreeNode *nodePtr) const
{
	if (nodePtr)
	{
		displayPostOrder(nodePtr->left);
		displayPostOrder(nodePtr->right);
		cout << nodePtr->value << endl;
	}
}

int intBinaryTree::size(TreeNode *nodePtr) const
{
	if (nodePtr == NULL)  //This node doesn't exist. Therefore there are no nodes in this 'subtree'
		return 0;

	else //Add the size of the left and right trees, then add 1 (which is the current node)
		return size(nodePtr->left) + size(nodePtr->right) + 1;
}



void intBinaryTree::insertNode(int num)
{
	TreeNode *newNode = nullptr; //pointer to a new node

	// Create a new node and store num in it.
	newNode = new TreeNode;
	newNode->value = num;
	newNode->left = newNode->right = nullptr;

	// Insert the node.
	insert(root, newNode);
}

bool intBinaryTree::searchNode(int num)
{
	TreeNode *nodePtr = root;

	while (nodePtr)
	{
		if (nodePtr->value == num)
			return true;
		else if (num < nodePtr->value)
			nodePtr = nodePtr->left;
		else
			nodePtr = nodePtr->right;
	}
	return false;
}

void intBinaryTree::remove(int num)
{
	deleteNode(num, root);
}
