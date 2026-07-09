#include <fstream.h>

int c[1025][1025],m,n;
short a[1025],b[1025],v[1025];

void max(int i,int j,int &lmax,int &cmax)
{
	int m=c[i-1][j];
	lmax=i-1,cmax=j;
	if(m<c[i][j-1]) m=c[i][j-1],lmax=i,cmax=j-1;
	if(m<c[i-1][j-1]) m=c[i-1][j-1],lmax=i-1,cmax=j-1;
}
	

int main()
{
	ifstream in("cmlsc.in");
	ofstream out("cmlsc.out");
	int i,j,lmax,cmax,mx;
	in >>m>>n;
	
	for(i=1;i<=m;i++) in >>b[i];
	
	for(i=1;i<=n;i++) in >>a[i];
	
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
		{
			max(i,j,lmax,cmax);
			c[i][j]=c[lmax][cmax]+(a[j]==b[i]);
		}
	/*for(i=0;i<=m;i++)
	{
		for(j=0;j<=n;j++)
		for(j=0;j<=n;j++)
			out <<c[i][j]<<" ";
		out <<"\n";
	}*/
	out <<c[m][n];
	//int ind=c[m][n];
	i=m;
	j=n;
	while(i>0 || j>0)
	{
		if(a[j]==b[i]) v[c[i][j]]=a[j];
		max(j,i,lmax,cmax);
		i=lmax;
		j=cmax;
	}
	
	out <<"\n";
	for(i=1;i<=c[m][n];i++) out <<v[i]<<" ";
	in.close();
	out.close();
	return 0;
}