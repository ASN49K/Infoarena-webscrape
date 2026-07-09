#include<fstream>
using namespace std;
int n,m,i,j,a[1025],b[1025],c[1025][1025],maxim,sir[1025];
int main()
{
	ifstream f("cmlsc.in");
	ofstream g("cmlsc.out");
	f>>n>>m;
	for(i=1;i<=n;i++)
		f>>a[i];
	for(j=1;j<=m;j++)
		f>>b[j];
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(a[i]==b[j])
				c[i][j]=c[i-1][j-1]+1;
			else
				c[i][j]=max(c[i-1][j],c[i][j-1]);
			g<<c[n][m]<<"\n";
			maxim=c[n][m];
			i=n,j=m;
			while(maxim)
			{
				if(a[i]==b[j]&&c[i][j]==maxim)
				{
					sir[maxim]=a[i];
					maxim--;
				}
				else
					if(c[i][j]>c[j][i])
						i--;
					else
						j--;
			}
			for(i=1;i<=c[n][m];i++)
				g<<sir[i]<<" ";
			return 0;
}