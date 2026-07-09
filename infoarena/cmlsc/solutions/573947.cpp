#include <stdio.h>
#include <stdlib.h>

FILE* inputFile;
FILE* outputFile;

char* inputFileName  = "cmlsc.in";
char* outputFileName = "cmlsc.out";

int n1;
int n2;

int* A;
int* B;

int** lungime;

void openFiles()
{
	inputFile  = fopen(inputFileName,  "r");
	outputFile = fopen(outputFileName, "w");
}

void cmlsc()
{
	//n2 pe latime
	//n1 pe inaltime
	lungime = (int**) malloc ((n2+1) * sizeof(int*));
	for(int i = 0; i <= n2; i++) {
		lungime[i] = (int*) malloc ((n1+1) * sizeof(int*));
	}
	for(int i = 0; i <= n2; i++) {
		lungime[i][0] = 0;
	}
	for(int i = 0; i <= n1; i++) {
		lungime[0][i] = 0;
	}

	for(int i = 1; i <= n2; i++) {
		for(int j = 1; j <= n1; j++) {
			int val1 = lungime[i][j-1];
			int val2 = lungime[i-1][j];
			int val3 = lungime[i-1][j-1] + ((A[j- 1] == B[i - 1]) ? 1 : 0);
			int valFinal = (val1 > val2) ? val1 : val2;
			valFinal = (valFinal > val3) ? valFinal : val3;
			lungime[i][j] = valFinal;
		}
	}
}

void readInput()
{
	fscanf(inputFile, "%d %d", &n1, &n2);
	A = (int*) malloc (n1 * sizeof(int));
	B = (int*) malloc (n2 * sizeof(int));
	for(int i = 0; i < n1; i++) {
		fscanf(inputFile, "%d", &A[i]);
	}
	for(int i = 0; i < n2; i++) {
		fscanf(inputFile, "%d", &B[i]);
	}
}



void closeFiles()
{
	fclose(inputFile);
	fclose(outputFile);
}

void printSolution()
{
	fprintf(outputFile, "%d\n", lungime[n2][n1]);
	int i = n2;
	int j = n1;
	int* temp = (int*)malloc(lungime[n2][n1] * sizeof(int));
	int index = 0;
	while(i > 0 && j > 0) {
		int val1 = lungime[i][j-1];
		int val2 = lungime[i-1][j];
		int val3 = lungime[i-1][j-1] + ((A[j- 1] == B[i - 1]) ? 1 : 0);
		if(val1 > val2) {
			if(val1 > val3) {
				j--;
			} else if(val2 > val3) {
				i--;
			} else {
				if(val3 > lungime[i-1][j-1]) {
					temp[index] = A[j-1];
					index++;
				}
				i--;
				j--;
			}
		} else if(val2 > val3) {
			i--;
		} else {
			if(val3 > lungime[i-1][j-1]) {
				temp[index] = A[j-1];
				index++;
			}
			i--;
			j--;
		}
	}
	for(int i = index - 1; i >= 0; i--) {
		fprintf(outputFile, "%d ", temp[i]);
	}
	delete temp;
}

int main()
{
	openFiles();
	readInput();

	cmlsc();
	printSolution();

	closeFiles();
	return 0;
}