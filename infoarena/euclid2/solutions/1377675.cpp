#include<fstream>
#include<cstring>
#include<algorithm>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int t,x,y;
int euclid(int x,int y)
{
	if(y==0)
		return x;
	else
		return euclid(y,x%y);
}
int main()
{
	fin>>t;
	while(t)
	{
		t--;
		fin>>x>>y;
		fout<<euclid(x,y)<<"\n";
	}
	return 0;
}
