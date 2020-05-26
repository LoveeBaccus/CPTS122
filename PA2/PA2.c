/*
Lovee Baccus
PA 2-- First Part of a two part project

Description: Music organizer thing, only required to do the first few thingies

Questions: 

how should I make load repeat to do all of the songs? While(infile != eof) ??

searching by artist --- what if there are multiple songs by an artist? what should it return?

making the node and then storing it somewhere?? in load

did I get the double stars right everywhere?

store --> syntax errors? idk??

main menu breaks when invalid nput is scanned in & doesn't exit when told to
*/

#include "PA2.h"

/*
Main Menu: repeats till exit
(1) load
(2) store
(3) display
(6) edit
(8) rate
(9) play
(11) exit
*/
void mainMenu(Node **pHead, FILE *infile) {
	int choice = 0, keepGoing = 1;

	while (keepGoing != 0) {
		//validate input
		//print screen
		printf("Would you like to:\n(1) load\n(2) store\n(3) display\n(6) edit\n(8) rate\n(9) play\n(11) exit ");
		//get user input
		scanf("%d", &choice);
		while (choice >= 0 && choice < 12) {
			switch (choice) {
			case 1://load
				loadSongs(infile, pHead);
				break;
			case 2://store
				break;
			case 3://display
				break;
			case 6://edit
				break;
			case 8://rate
				break;
			case 9://play
				break;
			case 11://exit
				keepGoing = 0;
				//
				break;
			}

		}

		
	}
}
		


//makeNode
Node *makeNode(Record newSong){
	Node *pMem = NULL;

	// allocate space on the heap, requesting the number
	// of bytes for a Node type
	pMem = (Node *)malloc(sizeof(Node));

	if (pMem != NULL)
	{
		// we succeeded at allocating space on heap
		pMem->song = newSong; // struct assignment, shallow copy
		pMem->pLink = NULL;
		// doubly linked list
		pMem->pPrev = NULL; 
	}

	return pMem;
}

//insertFront
//Does this take into consideration the double links? 
int insertAtFront(Node **pList, Record newSong)
{
	Node *pMem = NULL;
	int success = 0;

	// allocate space for a Node and set it to data
	pMem = makeNode(newSong);

	//needs work it needs to check the corner cases
	if (pMem != NULL)
		success = 1;
	{
		if (*pList == NULL) {
			// what happens if the list is empty
			*pList = pMem;
		}
		else {
			//makes sure that the new node is connected to the list
			pMem->pLink = *pList;
			//point the head pointer at the new node, breaks the link
			*pList = pMem;
			//change the next node's pPrev to point at the newest node
			pMem->pLink->pPrev = pMem;
		}
	}
	return success;
}


/*
load: must read all records from a file called musicPlayList.csv
into a dynamic doubly linked list. The doubly linked list is 
considered the main playlist. As each record is read from the 
file, it must be inserted at the front of the list. 
*/
//creates the list itself
//needs to be doubly linked, should be circularly! for bonus points
void loadSongs(FILE *infile, Node **pList) {
	//make the struct--> parse through the line and stick the feilds in the right spot

	char tempLine[BUFFER] = { "" };
	fgets(tempLine, BUFFER, infile);
	char tempDuration[BUFFER];
	Record newSong;
	if (tempLine[0] == '\"') {
		strcpy(newSong.artist, strtok(tempLine, "\""));
	}
	else {
		strcpy(newSong.artist, strtok(tempLine, ","));

	}
	strcpy(newSong.album, strtok(NULL, ","));
	strcpy(newSong.song, strtok(NULL, ","));
	strcpy(newSong.genre, strtok(NULL, ","));
	//store the duration into a temp line
	strcpy(tempDuration, strtok(NULL, ","));
	newSong.numTimesPlayed = atoi(strtok(NULL, ","));
	newSong.rating = atoi(strtok(NULL, ","));
	
	//store the duration into the struct Record
	newSong.songLength.minutes = atoi(strtok(tempDuration, ":"));
	newSong.songLength.seconds = atoi(strtok(NULL, ":"));

	//attatch the struct to the list --> insert will create a node for the record
	insertAtFront(pList,newSong);
}

/*
Store : writes the current records, in the dynamic 
doubly linked list, to the musicPlayList.csv file. 
The store will completely overwrite the previous 
contents in the file. 
//print the list out
*/


//duration needs to be concatinated to be printed as a string
void store(FILE *outfile, Node *pList) {
	//traverse the list
	//print the feilds to the screen seperated by commas
	while (pList!= NULL) {
		fprintf(outfile, "%s,%s,%s,%d:%d,%d,%d\n", pList->song.artist, pList -> song.album, pList ->song.song, pList ->song.songLength.minutes, pList ->song.songLength.seconds, pList->song.numTimesPlayed, pList->song.rating );
		pList = pList->pLink;
	}
	

}

//search by artist
//returns a pointer to the node where the artist is
//how to handle if there are multiple by an artist?? -- handle this in the play function
Node * searchByArtist(Node **pList) {

	return *pList;
}

/*
Display: prints records to the screen. This command must support 
two methods, one of which is selected by the user:
1.    Print all records. 
2.    Print all records that match an artist. 
*/
void display(Node **pHead) {
	int choice = 0;
	printf("Would you like to play all songs (1) or play an artist(2)?");
	scanf("%d", &choice);

	if (choice == 1) {
		//play all till pLink == null
	}
	else if (choice == 2) {
		//search for the artist
		//when found, display it
		//keep going till the pLink == null
	}
}

/*
Edit: allow the user to find a record in the list by artist. If 
there are multiple records with the same artist, then your program 
must prompt the user which one to edit. The user may modify all
of the attributes in the record. 
*/
void edit(Node **pList) {
	char targetArtist[BUFFER];
	char targetSong[BUFFER];
	printf("Which artist would you like to edit?");
	scanf("%s", &targetArtist);
	printf("Which song would you like to edit?");
	scanf("%s", &targetSong);

	//search for it by artist
	//when found check the song field to make sure its the right one

	//find out what they want to change
	int choice = 0;
	printf("What do you want to edit? \nArtist (1) \nAlbum (2) \nSong (3) \nGenere (4) \nDuration (5) \nRating (6) ");
	scanf("%d", &choice);

	switch (choice) {
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	}
}

/*
Rate: allow the user to assign a value of 1 – 5 to a song; 1 is the
lowest rating and 5 is the highest rating. The rating will replace 
the previous rating.
*/

/*
Play: allow the user to select a song, and must start “playing” 
each song in order from the current song. “Playing” the song for 
this assignment means displaying the contents of the record that 
represents the song for a short period of time, clearing the 
screen and showing the next record in the list, etc. This 
continues until all songs have been played.
could be circularly linked or just double
*/

/*
Exit: saves the most recent list to the musicPlayList.csv file. 
This command will completely overwrite the previous contents in the file.
*/
//calls the store function