#include<fstream>
using namespace std;
int euclid(int a, int b)
{
	int r=a%b;
	while(r)
	{
		a=b;
		b=r;
		r=a%b;
	}
	return b;
}
int main()
{
	ifstream fin("euclid2.in");
	ofstream fout("euclid2.out");
	int t,x,y;
	fin>>t;
	for(;t;--t)
	{
		fin>>x>>y;
		fout<<euclid(x,y)<<"\n";
	}
	return 0;
}