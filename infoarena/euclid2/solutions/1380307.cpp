#include <iostream>
#include <fstream>

int cmmdc(int a, int b)
{
	int rez = a % b;
	while ( rez )
	{
		a = b;
		b = rez;
		rez = a % b;
	}
	return b;
}

int main( int argc, char* argv[] )
{

	std::ifstream inputFile("euclid2.in");
	std::ofstream outputFile("euclid2.out");
	int nrRows;
	inputFile >> nrRows;
	for ( int i = 0; i < nrRows; ++i )
	{
		int first;
		int second;
		inputFile >> first >> second;
		outputFile << cmmdc(first,second) << std::endl;
	} 

	inputFile.close();
	outputFile.close();
	return 0;
};
