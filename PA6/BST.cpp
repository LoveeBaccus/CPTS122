#include "BST.h"

BSTNode * BST::getRoot(void)
{
	return root;
}

//constructor--open and read file, create the children nodes, and insert the node into the tree
//why are we using the starts there???
BST::BST() {
	fstream infile;
	infile.open("MorseTable.txt");

	root = nullptr;

	while (!infile.eof()) {
		char tempChar;
		string tempString;

		//parse the line -- space is somewhere weird??
		infile >> tempChar;
		infile >> tempString;
		BSTNode *tempNode = new BSTNode(tempChar,tempString);

		//instert the new BSTNode into the tree
		insert(root, *tempNode);
	}
	infile.close();
}
//destructor -- should call the destructor for each node to destroy everything at once
BST::~BST() {

}

void BST::insert(BSTNode *pRoot, BSTNode &tempNode) {
	if (pRoot == nullptr) { //the tree is empty
		//we already have a node so we dont need to make one
		this->root = &tempNode;
	}
	else {//the tree is not empty and we need to find a place to put the node
		if (tempNode.getIdentifier() < pRoot->getIdentifier()) 
		{
			//check if the branch is filled
			if (pRoot->getLeftBranch() != nullptr) 
			{ 
				insert(pRoot->getLeftBranch(), tempNode);
			}
			else 
			{//the branch is not filled, so we can store the node
				pRoot->setLeftBranch(tempNode);
			}
		}
		else if (tempNode.getIdentifier() > pRoot->getIdentifier()) 
		{
			if (pRoot->getRightBranch() != nullptr) 
			{
				insert(pRoot->getRightBranch(), tempNode);
			}
			else 
			{
				pRoot->setRightBranch(tempNode);
			}
		}
	}

}

//print tree -- recursive
void BST::printTreeRec(BSTNode * nRoot) {
	//go left, if you cant go left, go right, if you can't go right process the node and then pop up 
	if (nRoot->getLeftBranch() != nullptr) 
		printTreeRec(nRoot->getLeftBranch());

	cout << "Identifier: "<< nRoot->getIdentifier();
	cout << " Morse Code: " << nRoot->getMorseCode() << endl;

	if (nRoot->getRightBranch() != nullptr) 
		printTreeRec(nRoot->getRightBranch());
	
}

//search tree -- returns the morse code for the plaintext entered
//**put all letters into caps**
string BST::search(BSTNode *tree, char plaintext) 
{
	string morseCode = "";
	plaintext = toupper(plaintext);

	if (tree->getIdentifier() == plaintext)
	{
		//we found it 
		morseCode = tree->getMorseCode();
	}
	else 
	{
		if (plaintext < tree->getIdentifier()) 
		{
			morseCode = search(tree->getLeftBranch(), plaintext);
		}
		if(plaintext > tree->getIdentifier())
		{
			morseCode = search(tree->getRightBranch(), plaintext);
		}
	}

	return morseCode;
}

void BST::destroyTree(BSTNode *tree) {
	if (tree->getLeftBranch() != nullptr) {
		//means there are more nodes to process
		destroyTree(tree->getLeftBranch());
	}
	 if (tree->getRightBranch() != nullptr) {
		//more nodes to the right
		destroyTree(tree->getRightBranch());
	}
		delete tree;

}



