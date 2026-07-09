#include<iostream>
#include<fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int t;
long long a[100000],b[100000];
void formare()
{
	int i;
	for(i=1;i<=t;i++)
	{
		fin>>a[i];
		fin>>b[i];
	}
}
void euclid()
{
	int i,x,y,r,c;
	for(i=1;i<=t;i++)
	{
		x=a[i];
		y=b[i];
		while(y>0)
		{
			c=x/y;
			r=x%y;
			x=y;
			y=r;
		}
		fout<<x<<endl;
	}
}
int main()
{
	fin>>t;
	formare();
	euclid();
	fin.close();
	fout.close();
	return 0;
}
