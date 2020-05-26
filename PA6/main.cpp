//Lovee Baccus 
//PA 6 --> BST Stuff

/*
To Do:
1) the newline character isn't being echo'd and I don't know why
*/

#include "BST.h"

int main(void) {
	//will open the file, read it, and make the tree
	BST Tree;

	//print tree
	Tree.printTreeRec(Tree.getRoot());
	
	//open convert.txt
	fstream infile;
	infile.open("Convert.txt");
	
	//go through file and search for each character
	while (!infile.eof()) {
		string line = "",morseLine = "";
		getline(infile, line);
		
		for (int i = 0; i < line.size(); i++) {
			if (line[i] == ' ')
			{
				cout << "   ";
			}
			else if (line[i] == '\n') {
				cout <<"\n"<< endl;
			}
			else {
				morseLine = Tree.search(Tree.getRoot(), line[i]);
				cout << morseLine << " ";
			}
		}
		cout << endl;
	}
	
	system("pause");
	return 0;
}



