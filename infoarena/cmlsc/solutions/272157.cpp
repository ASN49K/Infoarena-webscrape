#include <fstream>
#include <algorithm>  
using namespace std;

const char in[]="cmlsc.in";
const char out[]="cmlsc.out";

int n,m,a[1500],b[1500],c[1030][1030];

void citire()
{
	ifstream fin(in);
	fin>>n>>m;
	for(int i=1;i<=n;i++)
		fin>>a[i];
	for(int i=1;i<=n;i++)
		fin>>b[i];
}

int main()
{
	citire();
	int s=0,c[1500];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(a[i]==b[j])
				c[i][j]=1+c[i-1][j-1];
			else
				if(c[i-1][j]>c[i][j-1])
					c[i][j]=c[i-1][j];
				else
					c[i][j]=c[i][j-1];
	ofstream fout(out);
	fout<<c[n][m];
	int i=n;
	int j=m;
	while(i && j)
	{
		if(a[i]==b[j])
		{
			c[++s]=a[i];
			i--;
			j--;
		}
		else
			if(c[i-1][j]>c[i][j-1])
				i--;
			else
				j--;
	}
	for(int i=1;i<=s;i++)
		fout<<c[i]<<' ';
	fout<<'\n';
	return 0;
}