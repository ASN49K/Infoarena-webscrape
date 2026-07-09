#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main()
{
	int a,b,n;
	fin>>n;
	for(int i = 0; i < n; i++)
	{
		fin>>a>>b;
		while(a != 0 || b != 0)
		{
			if(a < b) b %= a;
			else a %= b;
		}
		if(b == 0) fout<<a;
		else fout<<b;
	}
	
	return 0;
}
