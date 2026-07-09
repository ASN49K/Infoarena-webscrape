#include<fstream.h>
#define max 1024

int sol[max][max],a[max],b[max],n,m,i,j,vect[max],k=0;

int maxim(int x,int y)
{
	if(x>y)
		return x;
	return y;
}

int main()
{
	ifstream f("cmlsc.in");
	ofstream g("cmlsc.out");

	f>>n>>m;

	for(i=1;i<=n;i++)
		f>>a[i];
	for(i=1;i<=m;i++)
		f>>b[i];

	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(a[i]==b[j])
				sol[i][j]=sol[i-1][j-1]+1;
			else
				sol[i][j]=maxim(sol[i-1][j],sol[i][j-1]);

	i=n;j=m;
	while(i>=1&&j>=1)
		if(a[i]==b[j])
			{
			vect[++k]=a[i];
			i--;
			j--;
			}
		else
			if(sol[i][j-1]>sol[i-1][j])
				j--;
			else
				i--;

	g<<sol[n][m]<<"\n";
	for(i=k;i>=1;i--)
		g<<vect[i]<<" ";



	return 0;
}
