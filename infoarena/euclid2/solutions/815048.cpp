#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int cmmdc(int a,int b)
{
	if(!b)
		return a;
	return cmmdc(b,a%b);
}

int main ()
{
	unsigned long a,b,t;
	fin>>t;
	for(t;t;t--)
	{
		fin>>a>>b;
		fout<<cmmdc(a,b)<<endl;
	}
}
