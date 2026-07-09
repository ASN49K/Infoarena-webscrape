#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int s[1025][1025],a[1025],b[1025],c[1025];
int main ()
{
	int m,n,i,j,x;
	fin>>n>>m;
	for (i=1;i<=n;i++) fin>>a[i];
	for (i=1;i<=m;i++) fin>>b[i];
	for (i=1;i<=n;i++)
		for (j=1;j<=m;j++)
		{
			if (a[i]==b[j]) s[i][j]=s[i-1][j-1]+1;
			else
			{
				if (s[i-1][j]>s[i][j-1]) s[i][j]=s[i-1][j];
				else s[i][j]=s[i][j-1];
			}
		}
	fout<<s[n][m]<<"\n";
	i=n;j=m;x=1;
	while (s[i][j])
	{
		if (a[i]==b[j]) {c[x++]=a[i]; i--;j--;}
		else if (s[i-1][j]>s[i][j-1]) i--;
		else j--;
	}
	for (i=x-1;i>=1;i--) fout<<c[i]<<" ";
}