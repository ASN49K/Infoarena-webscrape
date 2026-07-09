#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

unsigned long int a, b, n;

int EU(int a, int b)
{
	if(!b)		return a;
	  else		return (b, b%a);
}

int main(void)
{
	fin>>n;

	for(; n; n--)
	{
		fin>>a>>b;
		fout<<EU(a,b)<<"\n";
	}


	fin.close();
	fout.close();
	return 0;
}
