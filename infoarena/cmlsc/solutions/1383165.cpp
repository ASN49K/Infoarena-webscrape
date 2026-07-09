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
		arrayRez[i][0] = 0;
	}
	for ( int j = 0; j < N; ++j )
	{
		arrayRez[0][j] = 0;
	}
	for ( int i = 1; i < M+1; ++i )
	{
		for ( int j = 1; j < N+1; ++j )
		{
			//std::cout << "Compare " << arrayM[i-1] << " " << arrayN[j] << std::endl;
 			if ( arrayM[i-1] == arrayN[j-1] )
			{
				arrayRez[i][j] = arrayRez[i-1][j-1]+ 1;
			}
			else
			{
				arrayRez[i][j] = max( arrayRez[i][j-1], arrayRez[i-1][j] );
			}
		}
	}
	//std::cout << arrayRez[M][N] << std::endl;

	int count = 0;
	for ( int i = M, j = N; i; )
	{
		if ( arrayM[i-1] == arrayN[j-1] )
		{
			arraySol[count++] = arrayM[i-1];
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

	/*for ( int i = 1; i < M+1; ++i )
	{
		for ( int j = 1; j < N+1; ++j )
		{
			std::cout << arrayRez[i][j] << " ";
		}
		std::cout << std::endl;
	}*/
	
	output << count << "\n";
	for ( int i = count-1; i > -1; --i )
	{
		output << arraySol[i] << " ";
	}
	
	input.close();
	output.close();
	return 0;
}
