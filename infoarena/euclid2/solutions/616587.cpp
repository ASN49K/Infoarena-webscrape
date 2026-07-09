#include <fstream>
#include <iostream>
using namespace std;

int CMMDC(int a,int b)
{
	int r;
	while (b)
	{
		r=b;
		b=a%b;
		a=r;

	}
	return a;
}

int main()
{
	ifstream fin("Euclid2.in");
	ofstream fout("Euclid2.out");
	int n,a,b,cmmdc;
	
	fin>>n;
	
	for(int i=0;i<n;i++)
	{
		fin>>a>>b;
		cmmdc=CMMDC(a,b);
		fout<<cmmdc<<"\n";
	}
	

	return 0;
}