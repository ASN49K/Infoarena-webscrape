#include<bits/stdc++.h>
using namespace std;
int n,m,lsol,sol[2000],mat[1500][1500],a[2000],b[2000];
int main(){ifstream fin("cmlsc.in");fin>>n>>m;//Pa pricolu :D Ionita Serghei :D 
	for(int i(0);i<n;fin>>a[++i]);for(int i(0);i<m;fin>>b[++i]);
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(a[i]==b[j]) mat[i][j]=1+mat[i-1][j-1];else mat[i][j]=max(mat[i-1][j],mat[i][j-1]);
    int i=n,j=m;while(i!=0)	if(a[i]==b[j]) sol[++lsol]=a[i],i--,j--; else if(mat[i-1][j]<mat[i][j-1]) j--;else i--;
 	ofstream fout("cmlsc.out");fout<<lsol<<endl; for(int i=lsol;i>=1;i--) fout<<sol[i]<<" ";return 0;}
