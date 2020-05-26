/*
Lovee Baccus
January 20, 2019
PA 2

Description: Me starting over pa 2 because my first one sucked.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Constants
#define INVALID 1000
#define SIZE 1440

//structs and stuff
typedef enum sleep {
	NONE = 0, ASLEEP = 1, AWAKE = 2, REALLYAWAKE = 3
} Sleep;

typedef struct fitbit {
	char patient[100];
	char minute[90];
	double calories;
	double distance;
	unsigned int floors;
	unsigned int heartRate;
	unsigned int steps;
	Sleep sleepLevel;
}FitbitData;

char * cleanseLine(char * line);
//precondition: must pass in a line that hasn't been tokenized yet, but must be cleansed
FitbitData parseLine(char * line, int lineNumber);
double calculateTotalCalories(FitbitData dataArr[]);
double calculateTotalDistance(FitbitData dataArr[]);
int CalculateTotalFloors(FitbitData dataArr[]);
int calculateTotalSteps(FitbitData dataArr[]);
double calculateAverageHeartrate(FitbitData dataArr[]);
int calculateMaxSteps(FitbitData dataArr[]);
void printData(FILE * outfile, FitbitData dataArr[]);