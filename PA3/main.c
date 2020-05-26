
/*
Lovee Baccus
PA 3: Second part of the assignment. Finishing up PA 2 requirments, and adding in PA3 things.

Description: Music organizer

Questions: Can you open a file for reading and writing at the same time? If we need to overload the file when we load and stuff?

is pHead supposed to be of type node?
*/


#include "newPA3.h"

int main(void) {

	//File Things
	//FILE * infile = fopen("musicPlayList.csv", "r");
	// need to do something for the writing to a file
	//if (!infile)
	//printf("failed");

	//char temp[100];

	//fgets(temp, 100, infile);

	//create pHead
	Node *pHead = NULL;

	printf("Welcome to your music!\n");
	//main menu -- will exicute while exit is not selected
	mainMenu(&pHead);

	return 0;
}