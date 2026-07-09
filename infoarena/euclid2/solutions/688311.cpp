#include<iostream>
using namespace std;
#include<fstream.h>

int c, a, b;

int ggt(int a, int b)
{
	if(!b)
		return a;
	else
		return ggt(b, a%b);
}

int main()
{
	ifstream fin("euclid2.in");
	ofstream fout("euclid2.out");
	fin>>c;
	for(int i=0; i<c; i++)
	{
		fin>>a>>b;
		fout<<ggt(&a, &b);
	}
	return 1;
}