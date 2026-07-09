#include<iostream>
#include<fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int main()
{
	int t,i,x,y;
	long long a[100000],b[100000];
	fin>>t;
	for(i=1;i<=t;i++)
	{
		fin>>a[i];
		fin>>b[i];
	}
	for(i=1;i<=t;i++)
	{
		x=a[i];
		y=b[i];
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
