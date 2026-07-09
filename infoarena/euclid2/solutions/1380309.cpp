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

std::ifstream inputFile("euclid2.in");
std::ofstream outputFile("euclid2.out");

int main( int argc, char* argv[] )
{
	int nrRows;
	inputFile >> nrRows;
	for ( int i = 0; i < nrRows; ++i )
	{
		int first, second;
		inputFile >> first >> second;
		outputFile << cmmdc(first,second) << std::endl;
	} 
	return 0;
};
