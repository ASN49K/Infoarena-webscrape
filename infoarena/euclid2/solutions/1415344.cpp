#include <iostream>
#include <stdio.h>

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
public: 
	int binaryEuclidAlgorithm()
	{

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
};

int main()
{
	FileStream* stream      = new FileStream();
	EuclidAlgorithm* euclid = new EuclidAlgorithm();

	for (int i = 0; i < stream->getNumberOfLines(); i++) {
		int gcd = euclid->repeatedSubstractionsEuclidAlgorithm(stream->readNextNumber(), stream->readNextNumber());
		stream->writeLineInFile(gcd);
	}
}