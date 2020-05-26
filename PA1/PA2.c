/*
Lovee Baccus
January 20, 2019
PA 2

Description: Me starting over pa 2 because my first one sucked.
*/

#include "PA2.h"

//returns 1 if the string was a match to the target, 0 if it was discarded
//modifies the line in a pointer, so if it worked, we can do stuff with it
char * cleanseLine(char * line) 
{
	char * newLine = "a";
	int length = strlen(line);
	for (int i = 1; i < length; i++)
	{
		char a = line[i - 1];
		char b = line[i];

		if (a == ',' && b == ',')
		{
			char firstHalf[255];
			strcpy(firstHalf, line);
			strcpy(firstHalf + i, "\0");

			char secondHalf[255];
			strcpy(secondHalf, line + i);

			char insertedString[4] = "-1";

			newLine = malloc((size_t)(strlen(firstHalf) + strlen(secondHalf) + strlen(insertedString) + 2));

			sprintf(newLine, "%s%s%s", firstHalf, insertedString, secondHalf);
			length = length + 2;
		}
		if (a == ',' && b == '\n')
		{
			char * newNewLine;
			newNewLine = malloc((size_t)(length + 1));

			if (newLine[0] != 'a')
			{
				strcpy(newNewLine, newLine);
				strcpy(newNewLine + length, "0\n");
				return newNewLine;
			}
			else
			{
				strcpy(newNewLine, line);
				strcpy(newNewLine + length, "0\n");
			}
		}
	}
	if (newLine[0] != 'a') return newLine;
	else return line;
}

//precondition: must pass in a line that hasn't been 
//tokenized yet, but must be cleansed
FitbitData parseLine(char * line, int lineNum) 
{
	FitbitData fbd;

	strcpy(fbd.patient, strtok(line, ","));
	strcpy(fbd.minute, strtok(NULL, ","));
	fbd.calories = atof(strtok(NULL, ","));
	fbd.distance = atof(strtok(NULL, ","));
	fbd.floors = atoi(strtok(NULL, ","));
	fbd.heartRate = atoi(strtok(NULL, ","));
	fbd.steps = atoi(strtok(NULL, ","));
	fbd.sleepLevel = (Sleep)atoi(strtok(NULL, ","));

	return fbd;
}

//total calories
double calculateTotalCalories(FitbitData dataArr[]) {
	double total = 0;
	//traverse the array and sum the calories
	for (int i = 0; i < 1440; i++) {
		if (dataArr[i].calories > -1) {
			total += dataArr[i].calories;
		}
	}
	return total;
}

//total distance
double calculateTotalDistance(FitbitData dataArr[]) {
	double total = 0;
	//traverse the array and sum the distance
	for (int i = 0; i < 1440; i++) {
		if (dataArr[i].distance > -1) {
			total += dataArr[i].distance;
		}
	}
	return total;
}


int CalculateTotalFloors(FitbitData dataArr[]) {
	int total = 0;
	for (int i = 0; i < 1440; i++) {
		if (dataArr[i].floors != -1) {
			total += dataArr[i].floors;
		}
	}
	return total;
}

//total steps
int calculateTotalSteps(FitbitData dataArr[]) {
	int total = 0;
	for (int i = 0; i < 1440; i++) {
		if (dataArr[i].steps >-1 ) {
			total += dataArr[i].steps;
		}
	}
	return total;
}

//average heartrate
double calculateAverageHeartrate(FitbitData dataArr[]) {
	//calculate total and keep track of how many
	int total = 0, ave = 0, counter = 0;
	for (int i = 0; i < SIZE; i++) {
		if (dataArr[i].heartRate > -1) {
			counter++;
			total += dataArr[i].heartRate;
		}
	}
	ave = total / counter;
	return ave;
}

// find the max steps in one minute
//returns the index of the max
int calculateMaxSteps(FitbitData dataArr[]) {
	int max = dataArr[0].steps, i = 0;
	for (i = 0; i < SIZE; i++) {
		if (dataArr[i].steps >= max) {
			max = dataArr[i].steps;
		}
	}
	return i;
}

//find the longest range of bad sleep
int calculateLongestRange(FitbitData dataArr) {
	//maxRange = 0;
	//find the first index of bad sleep
	//while its still bad sleep increment Temprange
	//if temp range > max range, replace it
	//repeat this for the whole dataArr
	return -1;
}

void printData(FILE * outfile,FitbitData dataArr[]) {
	for (int i = 0; i < SIZE; i++) {
		fprintf(outfile, "%s,%s,%lf,%lf,%d,%d,%d, %d\n", dataArr[i].patient, dataArr[i].minute,
			dataArr[i].calories, dataArr[i].distance, dataArr[i].floors, dataArr[i].heartRate,
			dataArr[i].steps, dataArr[i].sleepLevel);
	}
}