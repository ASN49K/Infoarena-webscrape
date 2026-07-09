#include <iostream>
#include <stdio.h>
#include <math.h>

class FileStream
{
private: 
	char* inputFileName  = "euclid2.in";
	char* outputFileName = "euclid2.out";

	FILE* inputStream  = NULL;
	FILE* outputStream = NULL;

	 // the number of lines from input file
	 int T = 0;

public:
	FileStream()
	{
		this->inputStream  = fopen(this->inputFileName, "r");
		this->outputStream = fopen(this->outputFileName, "w");

		this->T = this->readNextNumber();
	}

	int getNumberOfLines()
	{
		return this->T;
	}

	int readNextNumber()
	{
		int nextNumber = NULL;
		int readStatus = fscanf(this->inputStream, "%d", &nextNumber);

		return nextNumber;
	}

	void writeLineInFile(int value)
	{
		int writeStatus = fprintf(this->outputStream, "%d\n", value);
	}

	void writeLineOnConsole(int value)
	{
		int writeStatus = printf("%d\n", value);
	}
};

class EuclidAlgorithm
{
private:
	// used in binary algorithm
	int d = 0;

public: 
	int binaryEuclidAlgorithm(int a, int b)
	{
		if (a == b) {
			return this->calculateBinaryGcd(a);
		}
		else if ((a % 2 == 0) && (b % 2 == 0)) {
			this->d++;
			return this->binaryEuclidAlgorithm(a / 2, b / 2);
		}
		else if (a % 2 == 0) {
			return this->binaryEuclidAlgorithm(a / 2, b);
		}
		else if (b % 2 == 0) {
			return this->binaryEuclidAlgorithm(a, b / 2);
		}
		else if (a > b) {
			return this->binaryEuclidAlgorithm(a - b, b);
		}
		else {
			return this->binaryEuclidAlgorithm(a, b - a);
		}
		
	}

	int binaryEuclidAlgorithmWithBitShift(int a, int b)
	{
		
	}

	int repeatedDivisionsEuclidAlgorithm(int a, int b)
	{
		if (b) {
			return this->repeatedDivisionsEuclidAlgorithm(b, a % b);
		}

		return a;
	}

	int repeatedSubstractionsEuclidAlgorithm(int a, int b)
	{
		if (a > b) {
			return this->repeatedSubstractionsEuclidAlgorithm(a-b, b);
		}
		else if (a < b) {
			return this->repeatedSubstractionsEuclidAlgorithm(a, b-a);
		}

		return a;
	}

private:
	int calculateBinaryGcd(int finalResult)
	{
		int gcd = finalResult * pow(2, this->d);
		this->d = 0;

		return gcd;
	}
};

int main()
{
	FileStream* stream      = new FileStream();
	EuclidAlgorithm* euclid = new EuclidAlgorithm();

	for (int i = 0; i < stream->getNumberOfLines(); i++) {
		int gcd = euclid->binaryEuclidAlgorithm(stream->readNextNumber(), stream->readNextNumber());
		stream->writeLineInFile(gcd);
		//stream->writeLineOnConsole(gcd);
	}
}