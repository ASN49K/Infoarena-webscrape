#include<fstream.h>
#define endl '\n'

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int v[1026],w[1026],a[1026][1026],sol[1026];

int main(){
	int i,j,n,m,k=0,s;
	fin>>n>>m;
	for(i=1;i<=n;i++)
		fin>>v[i];
	for(i=1;i<=m;i++)
		fin>>w[i];
	for(i=1;i<=n;i++){
		s=0;
		for(j=1;j<=m;j++)
			if(v[i]==w[j]&&!s&&!a[n+1][j]){
				if(a[i-1][j]>a[i][j-1]) a[i][j]=a[i-1][j]+1,sol[++k]=v[i];
			    else a[i][j]=a[i][j-1]+1,sol[++k]=v[i];
				s=1;
				a[n+1][j]=1;
			}
			else 	
				if(a[i-1][j]>a[i][j-1]) a[i][j]=a[i-1][j];
				else a[i][j]=a[i][j-1];
	}	
	fout<<a[n][m]<<endl;
	for(i=1;i<=a[n][m];i++)
		fout<<sol[i]<<" ";
	return 0;
}
