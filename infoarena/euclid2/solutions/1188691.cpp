#include<iostream>
#include<fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int main()
{
	int t,x,y,r;
	fin>>t;
	while(t--)
	{
		fin>>x>>y;
		while(y>0)
		{
			r=x%y;
			x=y;
			y=r;
		}
		fout<<x<<endl;
	}
	fin.close();
	fout.close();
	return 0;
}
