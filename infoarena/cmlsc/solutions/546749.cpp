#include<fstream>
#define max 257
using namespace std;

ifstream f("cmlsc.in");
ofstream o("cmlsc.out");

int main ()
{
	int i,j,m,n,v[max][max];;
	char a[max],b[max];
	f>>n>>m;
	for (i=1;i<=n;i++)
		f>>a[i];
	for (j=1;j<=m;j++)
		f>>b[j];
	for (i=1;i<=n;i++)
		for (j=0;j<=m;j++)
			if (a[i]==b[j])
				v[i][j]=1+v[i-1][j-1];
			else
				if (v[i-1][j]>v[i][j-1])
					v[i][j]=v[i-1][j];
				else
					v[i][j]=v[i][j-1];
	o<<v[n][m]<<"\n";
	
	char d[max];
	int k;
	for (k=0,i=n,j=m;v[i][j]; )
		if (a[i]==b[j])
		{
			d[k++]=a[j];
			i--;
			j--;
		}
		else
			if (v[i][j]==v[i-1][j])
				i--;
			else
				j--;
	for (int s=k-1;s>=0;s--)
		o<<d[s]<<" ";
	
	
		return 0;
}
