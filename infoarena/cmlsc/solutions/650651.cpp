//cel mai lung subsir comun
#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n, m, a[1031],b[1031],d[1031][1031],v[1031],nr;
void citire(){
	f>>n>>m;
	for(int i=1;i<=n;i++)
		f>>a[i];
	for(int i=1;i<=n;i++)
		f>>b[i];
}
void completare(){
	int i,j;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(a[i]==b[j])
				d[i][j]=1+d[i-1][j];
			else
				d[i][j]=max(d[i-1][j],d[i][j-1]);
}
void sol(){
	int i,j;
	i=n;
	j=m;
	nr=0;
	while(i>0 && j>0 && d[i][j]>0){
		if(a[i]==b[j]){
			nr++;
			v[nr]=a[i];
			i--;
			j--;
		}
		else
			if(d[i][j-1]<=d[i-1][j])
				i--;
			else
				j--;
	}
}
int main (){
	
	citire();
	completare();
	sol();
	g<<d[n][m]<<'\n';
	for(int i=nr;i>=1;i--)
		g<<v[i]<<" ";
	
}