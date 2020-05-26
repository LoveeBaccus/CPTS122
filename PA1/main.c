/*
Lovee Baccus
January 20, 2019
PA 2

Description: Me starting over pa 2 because my first one sucked.
*/

#include "PA2.h"

int main(void) {
	//file stuff
	FILE * infile = NULL;
	infile = fopen("FitbitData.csv", "r");

	FILE * outfile = NULL;
	outfile = fopen("Output.csv", "w");

	//begin setting things up to get all the lines
	int lineCounter = 0;
	FitbitData dataArr[SIZE];


	char line[255];
	char targetId[10];

	//only executes once, gets the target ID 
	if (!feof("FitbitData.csv"))
	{
		fgets(line, 255, infile);
		strtok(line, ",");
		strcpy(targetId, strtok(NULL, ","));
	}
	else return -1;

	//get rid of the header line
	fgets(line, 255, infile);

	//loops through the whole file line by line
	while (!feof("FitbitData.csv") && lineCounter < SIZE) 
	{
		fgets(line, 255, infile);
		//need a copy since strtok will mess up the original
		char lineCopy[255];
		strcpy(lineCopy, line);

		//check to see if it matches target id
		if (strcmp(targetId, strtok(line, ",")) == 0 && lineCounter < SIZE) 
		{
			char newTempLine[255];
			strcpy(newTempLine, cleanseLine(lineCopy));
			strcpy(lineCopy, malloc((size_t)strlen(newTempLine)));
			strcpy(lineCopy, newTempLine);

			//create the struct resulting from the ine
			FitbitData newFbdItem = parseLine(lineCopy, lineCounter);
			
			//store the struct in the array
			if (lineCounter < SIZE)
			{
				dataArr[lineCounter] = newFbdItem;
				lineCounter = lineCounter + 1;
			}
		}
	}

	//calculate totals
	
	double totalCalories = calculateTotalCalories(dataArr);
	double totalDistance = calculateTotalDistance(dataArr);
	int totalFloors = CalculateTotalFloors(dataArr);
	int totalSteps = calculateTotalSteps(dataArr);
	double averageHeartRate = calculateAverageHeartrate(dataArr);
	int maxSteps = calculateMaxSteps(dataArr);
	int longestRange = 0;//calculateLongestRange(dataArr);
	int startIdx = 0;
	int endIdx = 0;

	//write out to screen
	printf("Total Calories,Total Distance,Total Floors,Total Steps,Avg Heartrate,Max Steps,Sleep\n");
	printf("%lf,%lf,%d,%d,%lf,%d,%d,%d\n", totalCalories, totalDistance, totalFloors, totalSteps,
		averageHeartRate, maxSteps, startIdx, endIdx);
	for (int i = 0; i < SIZE; i++) {
		printf("%s,%s,%lf,%lf,%d,%d,%d, %d\n", dataArr[i].patient, dataArr[i].minute,
			dataArr[i].calories, dataArr[i].distance, dataArr[i].floors, dataArr[i].heartRate,
			dataArr[i].steps, dataArr[i].sleepLevel);
	}

	//write to the file
	fprintf(outfile, "Total Calories,Total Distance,Total Floors,Total Steps,Avg Heartrate,Max Steps,Sleep\n");

	//print out all the dataArr
	fprintf(outfile, "%lf,%lf,%d,%d,%lf,%d,%d,%d\n", totalCalories, totalDistance, totalFloors, totalSteps,
		averageHeartRate, maxSteps, startIdx, endIdx);
	printData(outfile, dataArr);

	//close the files
	fclose(infile);
	fclose(outfile);

	return 0;
}
