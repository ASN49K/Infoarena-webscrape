#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int cmmdc(int a,int b)
{
	int r;
	while(b!=0)
	{
		r=a%b;
		a=b;
		b=r;
	}
	
	return a;
}

int main(){
	int i,n;
	fin>>n;
	for( ; n; -- n)
	{
		int x,y;
		fin>>x>>y;
		fout<<cmmdc(x,y)<<'\n';
	}
	
	return 0;
}
