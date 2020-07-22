#include <iostream>
#include <string>
#include "intBinaryTree.h"
using namespace std;

int main()
{
	intBinaryTree tree;

	 // Insert some values into the tree.
	 cout << "Inserting nodes.\n";
	 tree.insertNode(5);
	 tree.insertNode(8);
	 tree.insertNode(3);
	 tree.insertNode(12);
	 tree.insertNode(9);

	 // Display the values.
	 cout << "Here are the values in the tree:\n";
	 tree.displayInOrder();

	 // Delete the value 8.
	 cout << "Deleting 8...\n";
	 tree.remove(8);

	 // Displays amount of nodes
	 cout << "Here are the amount of nodes: ";
	 tree.size();
	 cout << endl;


	 return 0;
}