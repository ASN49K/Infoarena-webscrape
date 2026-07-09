#include<fstream.h>
#include<algorithm>


#define max(a , b ) ((a > b) ?  a:b )

ofstream g ("cmlsc.out");

int a[1050],b[1050],v[1050][1050],n,m;

void reconstit (int i, int j)
{
	if (i>0 && j>0)
	if (a[i]==b[j])
	{
		reconstit(i-1,j-1);
		g<<a[i]<<' ';
	}
	else
		if (v[i][j-1]>v[i-1][j])
			reconstit(i,j-1);
		else
			reconstit (i-1,j);
}


int main()
{
	int i,j;
	ifstream f ("cmlsc.in");
	f>>n>>m;
	for (i=1;i<=n;i++)
		f>>a[i];
	for (i=1;i<=m;i++)
		f>>b[i];
	
	for (i=1;i<=n;i++)
		for (j=1;j<=m;j++)
			if (a[i]==b[j])
				v[i][j]=v[i-1][j-1]+1;
			else 
				v[i][j]=max (v[i-1][j] , v[i][j-1]);
	
		g<<v[n][m]<<'\n';
	reconstit(n,m);
	
	f.close();
	return 0;
}