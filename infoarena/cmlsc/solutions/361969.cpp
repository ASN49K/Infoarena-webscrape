#include<fstream.h>
ifstream intrare("cmlsc.in");
ofstream iesire("cmlsc.out");
unsigned a[1025][1025],v1[1025],v2[1025],sir[1025];
int max(int nr1,int nr2)
{
	if(nr1>nr2) return nr1;
	return nr2;
}
int main()
{
	int m,n,i,j,nr=0;
	intrare>>m>>n;
	for(i=1;i<=m;i++) intrare>>v1[i];
	for(i=1;i<=n;i++) intrare>>v2[i];
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
		{
			if(v1[i]==v2[j]) a[i][j]=a[i-1][j-1]+1;
			else a[i][j]=max(a[i-1][j], a[i][j-1]);
		}
	i=m;j=n;
	while(i||j)
	{
		if(v1[i]==v2[j])
		{
			sir[nr++]=v1[i];
			i--;j--;
		}
		else if(a[i-1][j]<a[i][j-1]) j--;
		else i--;
	}
	iesire<<nr<<"\n";
	for(i=nr-1;i>=0;i--) iesire<<sir[i]<<" ";
	iesire<<"\n";
	return 0;
}
