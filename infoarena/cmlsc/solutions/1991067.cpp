#include<bits/stdc++.h>
using namespace std;
ifstream fin("cmlsc.in");ofstream fout("cmlsc.out");
int main(){
	int n,m;char v1[100010],v2[100010],v[100100];
	fin>>n>>m; int count=0; memset(v,0,100100);
	for (int it(1);it<=n;it++) fin>>v1[it];
		for (int it(1);it<=m;it++) fin>>v2[it]; 
	for (int it(1);it<=max(n,m);it++)	
			for (int ir(1);ir<=min(n,m);ir++) if(v1[it]==v2[ir]) count++,v[it]=v1[it];
		fout<<count<<endl;
	for(int i(1);i<=max(n,m);i++) fout<<v[i]<<" ";		 
	return 0;
}
