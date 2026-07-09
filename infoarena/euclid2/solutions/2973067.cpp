#include <bits/stdc++.h>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int t;int a,b;
int dc(int a, int b)
	{
		if(!b) return a;
		return dc(b,a%b);
	}
int main()
	{	fin>>t;
		while(t--){
		fin>>a>>b;fout<<dc(a,b)<<"\n";}
	}
