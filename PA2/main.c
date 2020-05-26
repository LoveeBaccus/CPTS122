
/*
Lovee Baccus
PA 2-- First Part of a two part project

Description: Music organizer thing, only required to do the first few thingies

Questions: Can you open a file for reading and writing at the same time? If we need to overload the file when we load and stuff?

is pHead supposed to be of type node?
*/

#include "PA2.h"

int main(void) {

	//File Things
	FILE * infile = NULL;
	infile = fopen("musicPlayList.csv", "r");
	// need to do something for the writing to a file

	//create pHead
	Node *pHead = NULL;

	printf("Welcome to your music!\n");
	//main menu -- will exicute while exit is not selected
	mainMenu(&pHead, infile);

	return 0;
}