#include<fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
long unsigned T,a,b;
long unsigned d(long unsigned a, long unsigned b)
{
	if(b==0)return a;
	return d(b, a%b);
}
int main()
{
	fin>>T;
	for(long unsigned i=1;i<=T;i++)
	{
		fin>>a>>b;
		fout<<d(a,b)<<endl;
	}
	return 0;
}
