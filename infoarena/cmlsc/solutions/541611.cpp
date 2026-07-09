#include<fstream.h>
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int a[1030],b[1030],c[1030][1030],d[1030];
int main()
{
	int i,j,k,m,n;
	fin>>m;
	fin>>n;
	for(i=1;i<=m;i++)
		fin>>a[i];
	for(i=1;i<=n;i++)
		fin>>b[i];
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
			if(a[i]==b[j])
				c[i][j]=c[i-1][j-1]+1;
			else
				if(c[i-1][j]<c[i][j-1])
					c[i][j]=c[i][j-1];
				else
					c[i][j]=c[i-1][j];
			
	fout<<c[m][n]<<'\n';
	i=m;j=n;
	k=0;
	while(i>=1)
	{
		if(a[i]==b[j])
		{	k++;
			d[k]=a[i];
			i--;
			j--;
		}
		else
			if(c[i-1][j]<c[i][j-1])
				j--;
			else
				i--;
	}
	for(i=k;i>=1;i--)
		fout<<d[i]<<' ';
		
	
return 0;
}

