#include<fstream>
using namespace std;

int i,j,n,m,a[1025],b[1025],d[1025][1025],c[1025],rez=0;
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
				d[i][j]=d[i-1][j-1]+1;
			else
				if(d[i-1][j]>d[i][j-1])
					d[i][j]=d[i-1][j];
				else
					d[i][j]=d[i][j-1];
				for(i=n,j=m;i;)
					if(a[i]==b[j])
						c[++rez]=a[i],i--,j--;
					else
						if(d[i-1][j]<d[i][j-1])
							j--;
						else
							i--;
						g<<rez<<"\n";
						for(i=rez;i>=1;i--)
							g<<c[i]<<" ";
				return 0;
}