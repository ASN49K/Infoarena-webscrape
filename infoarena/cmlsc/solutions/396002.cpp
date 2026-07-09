#include<fstream.h>
#define endl '\n'

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int v[1025],w[1025],a[1025][1025],sol[1025];

int main(){
	int i,j,n,m,k=0;
	fin>>n>>m;
	for(i=1;i<=n;i++)
		fin>>v[i];
	for(i=1;i<=m;i++)
		fin>>w[i];
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(v[i]==w[j])
				if(a[i-1][j]>a[i][j-1]) a[i][j]=a[i-1][j]+1,sol[++k]=v[i];
			    else a[i][j]=a[i][j-1]+1,sol[++k]=v[i];
			else 	
				if(a[i-1][j]>a[i][j-1]) a[i][j]=a[i-1][j];
				else a[i][j]=a[i][j-1];
	fout<<a[n][m]<<endl;
	for(i=1;i<=a[n][m];i++)
		fout<<sol[i]<<" ";
	return 0;
}
