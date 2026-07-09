#include<fstream>
using namespace std;

long long int cmmdc(long long int a,long long int b)
{
	if(!b)
		return a;
	return cmmdc(b,a%b);
}

int main()
{
	ifstream fin("euclid2.in");
	ofstream fout("euclid2.out");
	long long int t,a,b,i;
	fin>>t;
	for(i=1;i<=t;i++)
	{
		fin>>a;
		fin>>b;
		fout<<cmmdc(a,b)<<endl;
	}
	return 0;
}
