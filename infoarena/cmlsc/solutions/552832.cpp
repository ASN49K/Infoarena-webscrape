#include<fstream>
using namespace std;
ofstream g("cmlsc.out");

int i,j,n,m,a[1025],b[1025],l[1025][1025],d[1025];
void det()
{
	int i,j;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(a[i]==b[j])
				l[i][j]=l[i-1][j-1]+1;
			else
				l[i][j]=max(l[i-1][j],l[i][j-1]);
}
void afis()
{
	int i,j,t=0;
	i=1,j=1;
	while(i<=n&&j<=m)
		if(a[i]==b[j])
			d[++t]=a[i],i++,j++;
		else
			if(l[i][j+1]<l[i+1][j])
				i++;
			else
				j++;
			for(i=1;i<=t;i++)
				g<<d[i]<<" ";
}
int main()
{
	ifstream f("cmlsc.in");
	f>>n>>m;
	for(i=1;i<=n;i++)
		f>>a[i];
	for(j=1;j<=m;j++)
		f>>b[j];
	det();
	g<<l[n][m]<<"\n";
	afis();
	return 0;
}