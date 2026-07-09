#include<fstream>
#include<cstring>
#include<algorithm>
using namespace std;
ifstream fin("euclid.in");
ofstream fout("euclid.out");
int i,t,z,x,y;
int euclid(int x,int y)
{
	while(x!=0 && y!=0)
	{
		int r=x%y;
		x=y;
		y=r;
	}
	return x;
}
int main()
{
	fin>>t;
	for(i=1;i<=t;i++)
	{
		fin>>x>>y;
		z=euclid(x,y);
		fout<<z<<"\n";
	}
	return 0;
}
