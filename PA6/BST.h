#include "BSTNode.h"

class BST {
private:
	BSTNode *root;
public:
	BSTNode * getRoot(void);

	//constructor--open and read file, create the children nodes, and insert the node into the tree
	BST();
	//destructor -- should call the destructor for each node to destroy everything at once
	~BST();
	//insert
	void insert(BSTNode *root,BSTNode &newNode);
	//print tree -- recursive
	void printTreeRec(BSTNode * nodeToPrint);
	//search tree -- returns the morse code for the plaintext entered
	string search(BSTNode *tree, char plaintext);
	void destroyTree(BSTNode *tree);
};
