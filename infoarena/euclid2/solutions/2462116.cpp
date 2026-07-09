#include <bits/stdc++.h>

using namespace std;
ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");
int cmmdc (int a,int b)
{
	int rest;
	while(b!=0)
	{
		rest=a%b;
		a=b;
		b=rest;
	}
	return a;
}
int main ()
{
	int t,a,b;
	fin>>t;
	while(t--)
	{
		fin>>a>>b;
		fout<<cmmdc(a,b)<<"\n";
	}
	return 0;
}
