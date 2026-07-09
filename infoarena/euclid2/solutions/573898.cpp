#include <stdio.h>

FILE* inputFile;
FILE* outputFile;

char* inputFileName  = "euclid2.in";
char* outputFileName = "euclid2.out";

void openFiles()
{
	inputFile  = fopen(inputFileName,  "r");
	outputFile = fopen(outputFileName, "w");
}

int cmmdc(int a, int b)
{
	int r = a % b;
	while(r > 0) {
		int tempA = a;
		a = b;
		b = tempA % b;
		r = a % b;
	}
	return b;
}

void readInput()
{
	int n;
	fscanf(inputFile, "%d", &n);
	for(int i = 0; i < n; i++) {
		int a, b;
		fscanf(inputFile, "%d %d", &a, &b);
		if(a > b) {
			fprintf(outputFile, "%d\n", cmmdc(a, b));
		} else {
			fprintf(outputFile, "%d\n", cmmdc(b, a));
		}
	}
}



void closeFiles()
{
	fclose(inputFile);
	fclose(outputFile);
}


int main()
{
	openFiles();
	readInput();

	closeFiles();
	return 0;
}