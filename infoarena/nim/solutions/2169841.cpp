#include <iostream>
#include <fstream>


using namespace std;

ifstream fcin("nim.in");
ofstream fcout("nim.out");

int t;
int n;
int x;
int sum;

int main()
{
	fcin >> t;
	while( t-- )
	{
		sum = 0;
		fcin >> n;
		for( int i = 0; i < n; ++i )
		{
			fcin >> x;
			sum ^= x;
		}

		if( sum > 0 )
			fcout << "DA";
		else
			fcout << "NU";
		fcout << "\n";
	}

}