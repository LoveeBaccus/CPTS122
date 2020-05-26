#include "BSTNode.h"

BSTNode::~BSTNode() {
	//cout << "BSTNode destructor" << endl;
}

BSTNode::BSTNode(char plaintextChar, string morseCode){
	identifier = plaintextChar;
	this->morseCode = morseCode;
	leftBranch = nullptr;
	rightBranch = nullptr;
}

string BSTNode::getMorseCode(void) {
	return this->morseCode;
}
char BSTNode::getIdentifier(void) {
	return this->identifier;
}


//this works because it is a copy of a pointer which is an address
BSTNode * BSTNode::getLeftBranch(void) {
	return leftBranch;
}
BSTNode * BSTNode::getRightBranch(void) {
	return rightBranch;
}

void BSTNode::setLeftBranch(BSTNode &newNode) {
	leftBranch = &newNode;
}

void BSTNode::setRightBranch(BSTNode &newNode) {
	rightBranch = &newNode;
}