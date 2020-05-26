/*
Lovee Baccus

Questions:
the file isnt reading right????
*/

#include "newPA3.h"

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
void mainMenu(Node **pHead) {
	int choice = 0, keepGoing = 1;

	while (keepGoing != 0) {
		//validate input
		//print screen
		printf("Would you like to:\n(1) load\n(2) store\n(3) display\n(6) edit\n(8) rate\n(9) play\n(11) exit ");
		//get user input
		scanf("%d", &choice);
		while (choice >= 0 && choice < 12) {
			system("cls");
			switch (choice) {
			case 1://load
				choice = -1;
				printf("You chose to load!\n\n");
				loadSongs(pHead);
				break;
			case 2://store
				   //FILE * outfile = fopen("musicPlayList.csv", "w");
				   //choice = -1;
				   //printf("You chose to store!\n\n");
				   //store(outfile,*pHead);
				break;
			case 3://display
				choice = -1;
				printf("You chose to display!\n\n");
				display(pHead);
				break;
			case 4:
				choice = -1;
				break;
			case 5:
				choice = -1;
				break;
			case 6://edit
				choice = -1;
				printf("You chose to edit!\n\n");
				edit(pHead);
				break;
			case 7:
				choice = -1;
				printf("You chose number 7!\n\n");
				break;
			case 8://rate
				choice = -1;
				printf("You chose to rate!\n\n");
				break;
			case 9://play
				choice = -1;
				printf("You chose to play!\n\n");
				break;
			case 10:
				choice = -1;
				break;
			case 11://exit
				choice = -1;
				keepGoing = 0;
				//
				break;
			}
		}
	}
}



//makeNode
Node *makeNode(Record newSong) {
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
void loadSongs(Node **pList) {
	//make the struct--> parse through the line and stick the feilds in the right spot
	FILE * infile = fopen("data.csv", "r");

	while (infile != EOF) {
		char tempLine[200];
		fgets(tempLine, 100, infile);

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
		insertAtFront(pList, newSong);
	}
}

/*
Precondition: infile must be closed
Store : writes the current records, in the dynamic
doubly linked list, to the musicPlayList.csv file.
The store will completely overwrite the previous
contents in the file.
//print the list out
//duration needs to be concatinated to be printed as a string
*/
void store(FILE *outfile, Node *pList) {
	//traverse the list
	//print the feilds to the screen seperated by commas
	while (pList != NULL) {
		fprintf(outfile, "%s,%s,%s,%d:%d,%d,%d\n", pList->song.artist, pList->song.album, pList->song.song, pList->song.songLength.minutes, pList->song.songLength.seconds, pList->song.numTimesPlayed, pList->song.rating);
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
void display(Node *pList) {
	int choice = 0;
	printf("Would you like to play all songs (1) or play an artist(2)?");
	scanf("%d", &choice);

	if (choice == 1) {
		//play all till pLink == null
		while (pList != NULL) {
			printf("%s,%s,%s,%d:%d,%d,%d\n", pList->song.artist, pList->song.album, pList->song.song,
				pList->song.songLength.minutes, pList->song.songLength.seconds, pList->song.numTimesPlayed, pList->song.rating);
			pList = pList->pLink;
		}
	}
	else if (choice == 2) {
		printf("Which artist do you want to print?\n");
		char targetArtist[BUFFER];
		scanf("%s", targetArtist);
		//search for the artist
		//when found, display it
		//keep going till the pLink == null
		while (pList != NULL) {
			if (strcmp(pList->song.artist, targetArtist) == 0) {
				printf("%s,%s,%s,%d:%d,%d,%d\n", pList->song.artist, pList->song.album, pList->song.song,
					pList->song.songLength.minutes, pList->song.songLength.seconds, pList->song.numTimesPlayed, pList->song.rating);
				pList = pList->pLink;
			}
			else {
				pList = pList->pLink;
			}
		}
	}
}

/*
Edit: allow the user to find a record in the list by artist. If
there are multiple records with the same artist, then your program
must prompt the user which one to edit. The user may modify all
of the attributes in the record.
*/
void edit(Node *pList) {
	char targetArtist[BUFFER];
	char targetSong[BUFFER];
	printf("Which artist would you like to edit?");
	scanf("%s", &targetArtist);
	printf("Which song would you like to edit?");
	scanf("%s", &targetSong);

	//search for it by artist
	//when found check the song field to make sure its the right one
	while (pList != NULL) {
		if (strcmp(pList->song.artist, targetArtist) == 0) {
			if (strcmp(pList->song.song, targetSong) == 0) {
				//find out what they want to change
				int choice = 0;
				printf("What do you want to edit? \nArtist (1) \nAlbum (2) \nSong (3) \nGenere (4) \nDuration (5) \nRating (6) ");
				scanf("%d", &choice);
				char newField[BUFFER];

				switch (choice) {
				case 1:
					printf("You chose to edit the artist. What would you like to change it to?\n");
					scanf("%s", newField);
					//store the string in the artist field
					break;
				case 2:
					printf("You chose to edit the album. What would you like to change it to? \n");
					scanf("%s", newField);
					//store it into the album field
					break;
				case 3:
					printf("You chose to edit the song. What would you like to change it to?\n");
					scanf("%s", newField);
					//store it into the song field
					break;
				case 4:
					printf("You chose to edit the genera. What would you like to change it to?\n");
					scanf("%s", newField);
					//store into the genera field
					break;
				case 5:
					printf("You chose to edit the duration field. What would you like to change it to?\n");
					scanf("%s", newField);
					//store it the the genera field
					break;
				case 6:
					printf("You chose to edit the rating. What would you like to change it to?\n");
					scanf("%s", newField);
					//validate
					//store it into the rating
					break;
				}
			}
			else {
				pList = pList->pLink;
			}

		}
		else {
			pList = pList->pLink;
		}
	}


	//store the new list to the file
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