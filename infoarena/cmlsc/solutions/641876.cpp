#include<fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int a[1025],b[1025],m,n,c[1025][1025],sol[1025];

int main()
{
	fin>>n>>m;
	for(int i=1;i<=n;i++)
		fin>>a[i];
	for(int i=1;i<=m;i++)
		fin>>b[i];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(a[i]==b[j])
				c[i][j]=c[i-1][j-1]+1;
			else
				if(c[i][j-1]>=c[i-1][j])
					c[i][j]=c[i][j-1];
				else
					c[i][j]=c[i-1][j];
	fout<<c[n][m]<<endl;
	int i=n,j=m,k=c[n][m];
	while(i&&j)
	{
		if(a[i]==b[j])
		{
			sol[k]=a[i];
			k--;
			i--;
			j--;
		}
		else
			if(c[i][j-1]>=c[i-1][j])
				j--;
			else
				i--;
	}
	for(int i=1;i<=c[n][m];i++)
		fout<<sol[i]<<" ";
	return 0;
}
