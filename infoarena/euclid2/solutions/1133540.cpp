#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int cmmdc(int a,int b)
{
	int r;
	r=a%b;
	while(r)
	{
		a=b;
		b=r;
		r=a%b;
	}
	return b;
}

int x,y,t,i;

int main()
{
	fin>>t;
	for(i=1;i<=t;i++)
	{
		fin>>x>>y;
		fout<<cmmdc(x,y)<<"\n";
	}
	return 0;
}