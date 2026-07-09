#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int cmmdc(int a, int b)
{
	int aux=0,t=0;
	if(b>a)
	{
		aux=a;
		a=b;
		b=aux;
	}
	while(b)
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
