#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int cmmdc(int a, int b)
{
	int t=0;
	while(b!=0)
	{
		t=b;
		b=a % b;
		a=t;
	}
	return a;
}
int main()
{
	int a,b,n;
	fin>>n;
	for(;n;n--)
	{
		fin>>a;
		fin>>b;
		fout<<cmmdc(a,b)<<endl;
	}
	fin.close();
	fout.close();
}
