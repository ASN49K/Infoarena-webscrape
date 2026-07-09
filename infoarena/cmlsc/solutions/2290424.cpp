#include <fstream>
#define maxim(a,b) a>b ? a:b 
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int a[1300][1300],b[1300],c[1300],tazic[1300],n,m,p=1;

void afisare()
{
	for(int i=0;i<=n;i++)
		{
			for(int j=0;j<=m;j++)
				fout<<a[i][j];
			fout<<'\n';
		}
}


void coloreaza()
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(b[i]==c[j]) a[i][j]=a[i-1][j-1]+1;
				else a[i][j]=max(a[i-1][j],a[i][j-1]);
}

void backcolor(int i,int j)
{
	if(!(i==0 || j==0))
		if(b[i]==c[j]) 
			{
				tazic[p]=b[i];	
				p++;
				backcolor(i-1,j-1);
			}	
		else if(a[i-1][j]<=a[i][j-1]) backcolor(i,j-1);
			 else backcolor(i-1,j);
}

int main()
{
	fin>>n>>m;
	for(int i=1;i<=n;i++)
		fin>>b[i];
	for(int i=1;i<=m;i++)
		fin>>c[i];
	
	coloreaza();
	backcolor(n,m);

	fout<<a[n][m]<<'\n';
	
	for(int i=a[n][m];i>=1;i--)
		fout<<tazic[i]<<" ";
}














