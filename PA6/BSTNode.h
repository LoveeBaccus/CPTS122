#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;
using std::fstream;

#include <iostream>
#include <fstream>
#include <string>

class BSTNode {
private:
	char identifier;
	string morseCode;
	BSTNode *leftBranch;
	BSTNode *rightBranch;
public:
	//constructor that accepts arguements for the identifier and morse code
	BSTNode(char plaintextChar, string morseCode);
	//destructor?
	~BSTNode();
	//getters to be able to convert from english to morse code
	string getMorseCode();
	char getIdentifier();
	BSTNode * getLeftBranch();
	BSTNode * getRightBranch();
	void setLeftBranch(BSTNode &newNode);
	void setRightBranch(BSTNode &newNode);
};


