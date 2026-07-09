#include <fstream>
#define InFile "euclid2.in"
#define OutFile "euclid2.out"
using namespace std;
int euclid(int,int);
ifstream fin(InFile);
ofstream fout(OutFile);
int main()
{
	int a,b,n;
	fin>>n;
	for(int i = 0;i < n;i++)
	{
		fin>>a>>b;
		fout<<euclid(a,b)<<'\n';
	}
	return 0;
}
int euclid(int x,int y)
{
	if(!y) return x;
	return euclid(y,x%y); 
}
