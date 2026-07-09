
#include <fstream>
#include <iostream>
#include <stdio.h>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");



int main()
{

	int t,a,b;

	f >> t;

	for (int i = 0; i < t ; i++ ) 
	{
		f >> a >> b;
		while ( a != b ) 
		{
			if ( a > b ) 
			{
				a -=b;
			}
			else 
			{
				b -= a;
			}
		}
		g << a << "\n";
	}

	return 0;
}

