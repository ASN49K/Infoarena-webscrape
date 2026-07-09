#include<fstream.h>
#define nmax 1030
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int a[nmax],b[nmax],v[nmax][nmax],i,j,n,m,sir[nmax],nr;
int main()
{
	fin>>n>>m;
	for (i=1;i<=n;i++)
		fin>>a[i];
	for (i=1;i<=m;i++)
		fin>>b[i];
	for (i=1;i<=n;i++)
		for (j=1;j<=m;j++)
			v[i][j]=0;
	for (i=1;i<=n;i++)
		for (j=1;j<=m;j++)
			if (a[i]==b[j])
				v[i][j]=1+v[i-1][j-1];
				else
					if (v[i-1][j]>v[i][j-1]) v[i][j]=v[i-1][j];
				else
					v[i][j]=v[i][j-1];

	
	i=n;j=m;
		while (j)
		if (a[i]==b[j])
		{nr++; sir[nr]=a[i];i--;j--;}
		else
			if (v[i-1][j]<v[i][j-1]) j--;
		else i--;
			
	fout<<nr<<'\n';
	for (i=nr;i>=1;i--)
		fout<<sir[i]<<' ';
	
			
		
		
		
	fout.close();
	return 0;
}