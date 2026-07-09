#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>

int main( int argc, char* argv[] )
{
	std::ifstream file("datorii.in");
	std::ofstream fileOut("datorii.out");
	std::string aux;
	file >> aux;
	int N = atoi( aux.c_str() );
	file >> aux;
	int M = atoi( aux.c_str() ); 
	std::vector<int> datorii;
	for ( int i = 0; i < N; ++i )
	{
		file >> aux;
		datorii.push_back( atoi( aux.c_str() ) );
	}
	for ( int i = 0; i < M; ++i )
	{
		std::string cod;
		std::string first;
		std::string second;
		file >> cod;
		file >> first;
		file >> second;
		if ( cod == "0" )
		{
			datorii[atoi(first.c_str())-1] -= atoi(second.c_str());
		}
		else
		{
			int tmp = 0;
			for ( int j = atoi(first.c_str())-1; j < atoi(second.c_str()); ++j )
			{
				tmp += datorii[j];
			}
			fileOut << tmp << std::endl;
		}
	}
	file.close();
	fileOut.close();
	return 0;
}
