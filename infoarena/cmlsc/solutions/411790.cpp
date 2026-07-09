#include<fstream.h>
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int a[1026],b[1026],i,j,M[1026][1026],n,m;
int main()
{
	f>>m>>n;
	for(i=1;i<=m;i++)
	    f>>a[i];
	for(i=1;i<=n;i++)
		f>>b[i];
	for (i=m;i>=1;i--)
		for(j=n;j>=1;j--)
			if(a[i]==b[j])
				M[i][j]=1+M[i+1][j+1];
			else 
				if (M[i][j+1]>M[i+1][j])
					M[i][j]=M[i][j+1];
				else 
					M[i][j]=M[i+1][j];
	g<<M[1][1]<<'\n';
	i=j=1;
	while(M[i][j]!=0)
		if(a[i]==b[j])
		{ g<<a[i]<<' ';
		i++;
		j++;}
		else 
			if (M[i+1][j]>M[i][j+1]) i++;
				else j++;
			g<<'\n';
		f.close();
		g.close();
		return 0;
}
			