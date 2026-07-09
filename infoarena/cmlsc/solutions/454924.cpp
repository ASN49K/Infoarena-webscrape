#include<fstream>
using namespace std;
int n,m,i,j,k,a[100],b[100],lscm[100][100],h;
int z[100];
int main()
{
	ifstream f("lscm.in");
	ofstream g("lscm.out");
	f>>n>>m;
	for(i=1;i<=n;i++)
		f>>a[i];
	for(j=1;j<=m;j++);
	f>>b[j];
	for(i=1;i<=n;i++)
		lscm[i][0]=0;
	for(j=1;j<=m;j++)
		lscm[0][j]=0;
	for(k=1;k<=n;k++)
		for(h=1;h<=m;h++)
			if(a[k]=b[h])
			
				lscm[k][h]=1+lscm[k-1][h-1];
			else
				if(lscm[k-1][h]>lscm[k][h-1])
					lscm[k][h]=lscm[k-1][h];
				else
					lscm[k][h]=lscm[k][h-1];
				for(i=0;i<=n;i++)
				{
					for(j=0;j<=m;j++)
						g<<lscm[i][j]<<" ";
					g<<"\n"<<" lungimea subsirului comun maximal este";
					g<<lscm[n][m]<<"\n";
				}
			
	for(i=0;k<=n,h=m;lscm[k][h]++)
		if(a[k]=b[h])
		{
			z[i++]=a[k];
			k--;
			h--;
		}
		else
			if(lscm[k][h]=lscm[k-1][h])
				k--;
			else
				h--;
			for(k=i-1;k>=0;k--)
				g<<z[k]<<" ";
			return 0;
}
					