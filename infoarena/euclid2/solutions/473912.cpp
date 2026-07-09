
#include <fstream>
#include <iostream>
#include <stdio.h>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");



int main()
{

	int t,a,b,r;

	f >> t;

	for (int i = 0; i < t ; i++ ) 
	{
		f >> a >> b;
		
		do{
			
			r = a % b;
			a = b;
			b = r;


		}while ( r != 0 ) 


		g << a << "\n";
	}

	return 0;
}

