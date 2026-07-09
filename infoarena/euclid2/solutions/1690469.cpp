#include<bits/stdc++.h>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int gcd(int a,int b)
{
	if(!b) return a;
	return gcd(b,a%b);
}
long long x,y;
int n;
int main()
{
	fin>>n;
	for(;n;n--)
	{
		fin>>x>>y;
		fout<<gcd(x,y)<<endl;
	}
	
	
	return 0;
}
