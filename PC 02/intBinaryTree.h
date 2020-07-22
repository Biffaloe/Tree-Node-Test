#include <iostream>
using namespace std;

#pragma once
#ifndef INTBINARYTREE_H
#define INTBINARYTREE_H


class intBinaryTree
{
protected:
	struct TreeNode
	{
		int value;
		TreeNode *left;
		TreeNode *right;
	};

	TreeNode *root;

	//private member functions
	void insert(TreeNode *&, TreeNode *&);
	void destroySubTree(TreeNode *);
	void deleteNode(int, TreeNode *&);
	void makeDeletion(TreeNode *&);
	void displayInOrder(TreeNode *) const;
	void displayPreOrder(TreeNode *) const;
	void displayPostOrder(TreeNode *) const;
	int size(TreeNode *) const;

public:
	//constructer
	intBinaryTree()
	{ root = nullptr;	}

	// Destructor
	~intBinaryTree()
		{ destroySubTree(root); }
	
	// Binary tree operations
	void insertNode(int);
	bool searchNode(int);
	void remove(int);

	void size() const
		{cout << size(root);}

	void displayInOrder() const
		{ displayInOrder(root); }
	
	void displayPreOrder() const
		{ displayPreOrder(root); }
	
	void displayPostOrder() const
		{ displayPostOrder(root); }
};

#endif // !INTBINARYTREE_H
