#include<iostream>
#include<fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int main()
{
	
	int a,b,d,i,r,j,t;
	fin>>t;
	for(j = 1; j <= t; j ++)
	{
		fin>>a;
		fin>>b;
		d = a;
		i = b;
		do 
		{
			r = d % i;
			d = i;
			i = r;
		}
		while(r != 0);
		fout << d << '\n';
	}
	return 0;
}
