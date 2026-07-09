#include <iostream>
#include <fstream>
 
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int main(){
	int x,n,m,i,j,v[3000],k,b[3000];
	fin>>n>>m;
	for (i=1;i<=n;i++){
	fin>>x;
	v[x]=1;
	}
	for (j=1;j<=m;j++){
		fin>>x;
		if (v[x]==1) {k++;b[k]=x;}
	}
	fout<<k<<"\n";
	for (i=1;i<=k;i++)
	fout<<b[i]<<" ";
	return 0;
}
