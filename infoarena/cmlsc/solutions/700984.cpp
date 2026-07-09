#include<fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int i,j,v[1030][1030],vn[1030],vm[1030];
void afisare(int a,int b)
{
	if(v[a][b]!=0)
	{
		if(vn[a]==vm[b])
		{
			afisare(a-1,b-1);
			g<<vn[a]<<' ';
		}
		else
		{
			if(v[a-1][b]>v[a][b-1])
			{
				afisare(a-1,b);
			}
			else
			{
				afisare(a,b-1);
			}
		}
	
	}
}
int m,n;
int main()
{
	f>>m>>n;
	for(i=1;i<=m;i++)
	{
		f>>vm[i];
	}
	for(i=1;i<=n;i++)
	{
		f>>vn[i];
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(vn[i]==vm[j])
			{
				v[i][j]=v[i-1][j-1]+1;
			}
			else
			{
				if(v[i-1][j]>v[i][j-1])
				{
					v[i][j]=v[i-1][j];
				}
				else
				{
					v[i][j]=v[i][j-1];
				}
			}
		}
	}i--;j--;
	g<<v[i][j]<<'\n';
	afisare(i,j);
}