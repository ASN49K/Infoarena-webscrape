#include <fstream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <stdlib.h>
using namespace std;


ifstream fi ("nim.in");
ofstream fo ("nim.out");

int main ()
{
	int T, N, S, X;
	
	fi >> T;
	while (T --)
	{
		fi >> N;
		S = 0;
		while (N --)
		{
			fi >> X;
			S ^= X;
		}
		if (S == 0)
			fo << "NU\n";
		else
			fo << "DA\n";
	}
	
	return 0;
}

