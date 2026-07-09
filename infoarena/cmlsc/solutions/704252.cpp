#include<fstream.h>
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");	
int d[100],lcs[100][100],n,m,i,j,k,h,x[100],y[100];

int main()
{
	fin>>n>>m;
	for(i=1;i<=n;i++)
		fin>>x[i];
	for(i=1;i<=m;i++)
		fin>>y[i];
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
			if(x[i]==y[j])
				lcs[i][j]=1+lcs[i-1][j-1];
			else
				if(lcs[i-1][j]>lcs[i][j-1])
					lcs[i][j]=lcs[i-1][j];
				else
					lcs[i][j]=lcs[i][j-1];
	}
	fout<<lcs[n][m]<<'\n';
	for(i=0,k=n,h=m;lcs[k][h];)
		if(x[k]==y[h])
		{
			d[i++]=x[k];
			k--;
			h--;
		}
		else
			if(lcs[k][h]==lcs[k-1][h])
				k--;
			else
				h--;
	for(k=i-1;k>=0;k--)
		fout<<d[k]<<' ';
}