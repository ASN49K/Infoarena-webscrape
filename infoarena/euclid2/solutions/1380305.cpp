#include <iostream>
#include <fstream>

int cmmdc(int a, int b)
{
	if ( a == b ) return a;
	if ( a > b ) return cmmdc( a-b, b);
	if ( b > a ) return cmmdc( a, b-a);
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
