#include <fstream>
#include <iostream>

using namespace std;

static const int DIM = 1024;
int arrayM[DIM], arrayN[DIM];
int arrayRez[DIM][DIM];
int arraySol[DIM];

int main( int argc, char* argv[] )
{
	ifstream input("cmlsc.in");
	ofstream output("cmlsc.out");
	int M, N;
	input >> M >> N;
	
	for ( int i = 0; i < M; ++i )
	{
		input >> arrayM[i];
	}
	for ( int i = 0; i < N; ++i )
	{
		input >> arrayN[i];
	}
	for ( int i = 0; i < M; ++i )
	{
		for ( int j = 0; j < N; ++j )
		{
			if ( arrayM[i] == arrayN[j] )
			{
				arrayRez[i][j] = arrayRez[i-1][j-1]	+ 1;
			}
			else
			{
				arrayRez[i][j] = max( arrayRez[i][j-1], arrayRez[i-1][j] );
			}
		}
	}

	int count = 0;
	for ( int i = M, j = N; i; )
	{
		if ( arrayM[i] == arrayN[j] )
		{
			arraySol[count++] = arrayM[i];
			--i;
			--j;
		}
		else
		{
			if ( arrayRez[i-1][j]>arrayRez[i][j-1])
			{
				--i;
			}
			else
			{
				--j;
			}
		}
	}

	
	output << count << "\n";
	for ( int i = 1; i < count; ++i )
	{
		output << arraySol[i] << " ";
	}
	
	input.close();
	output.close();
	return 0;
}
