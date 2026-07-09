#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

short int a[1024][1024];
int x[1025];
int y[1025];
int s[1025];
int si=0;
int n,m;

int main()
{
	fin>>n>>m;
	for(int i=1;i<=n;i++)
		fin>>x[i];
	for(int i=1;i<=m;i++)
		fin>>y[i];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(x[i]==y[j])
				a[i][j]=a[i-1][j-1]+1;
			else
				if(a[i][j-1]>=a[i-1][j]) a[i][j]=a[i][j-1];
				else a[i][j]=a[i-1][j];
	fout<<a[n][m]<<"\n";
	int i=n,j=m;
	while(i>0&&j>0)
		{
			if(x[i]==y[j])
				s[++si] = x[i],i--,j--;
			else if(a[i][j-1]>=a[i-1][j])j--;
				else i--;
		}
	for(int i=si;i>=1;i--)
		fout<<s[i]<<" ";
	return 0;
}
