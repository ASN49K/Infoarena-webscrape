#include<fstream>
using namespace std;

long long int cmmdc(long long int a,long long int b)
{
	long long int r;
	while(a!=0)
	{
		r=b%a;
		b=a;
		a=r;
	}
	return b;
}

int main()
{
	ifstream fin("euclid2.in");
	ofstream fout("euclid2.out");
	long long int t,a,b,i,v[100001];
	fin>>t;
	for(i=1;i<=t;i++)
	{
		fin>>a;
		fin>>b;
		v[i]=cmmdc(a,b);	
	}
	for(i=1;i<=t;i++)
		fout<<v[i]<<endl;
	return 0;
}
