#include<cstdio>
using namespace std;
int max(int a, int b)
{
	if(a>b) return a; return b;
}

int i,j,n,m,a[1025],b[1025],v[1025][1025];
FILE *f=fopen("cmlsc.in","r");
FILE *g=fopen("cmlsc.out","w");
void afisare(int i,int j)
{
	if(i>0&&j>0)
	{
	if(v[i-1][j]==v[i][j]) afisare(i-1,j);
	else if(v[i][j-1]==v[i][j]) afisare(i,j-1);
	else
	{
		afisare(i-1,j-1);
		fprintf(g,"%d ",a[i]);
	}
	}
}
int main()
{

	fscanf(f,"%d %d",&n,&m);
	for(i=1;i<=n;i++)fscanf(f,"%d",&a[i]);
	for(i=1;i<=m;i++)fscanf(f,"%d",&b[i]);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		{
			if(a[i]==b[j])v[i][j]=v[i-1][j-1]+1;
			else 
				v[i][j]=max(v[i-1][j],v[i][j-1]);
		}
	
	fprintf(g,"%d\n",v[n][m]);
	afisare(n,m);
	fclose(f);
	fclose(g);
	return 0;
}