#include<iostream>
#include<fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int main()
{
	int t,x,y,r;
	long long a[100000],b[100000];
	fin>>t;
	while(t--)
	{
		fin>>a[t]>>b[t];
		x=a[t];
		y=b[t];
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
