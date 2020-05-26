/*
Lovee Baccus
PA 2-- First Part of a two part project

Description: Music organizer thing, only required to do the first few thingies
*/

#define _CRT_SECURE_NO_WARNINGS
#define BUFFER 100
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//duration struct
typedef struct duration {
	int minutes;
	int seconds;
}Duration;
//record struct
typedef struct record {
	char artist[BUFFER];
	char album[BUFFER];
	char song[BUFFER];
	char genre[BUFFER];
	Duration songLength;
	int numTimesPlayed;
	int rating;
}Record;

//node struct
typedef struct node {
	Record song;
	struct node *pLink;
	struct node *pPrev;
}Node;


//functions!!
void mainMenu(Node **pHead, FILE *infile);
Node *makeNode(Record newSong);
int insertAtFront(Node **pList, Record newSong);
void loadSongs(FILE *infile, Node **pList);
void store(FILE *outfile, Node **pList);
Node * searchByArtist(Node **pList);
void display(Node **pHead);
void edit(Node **pList);
