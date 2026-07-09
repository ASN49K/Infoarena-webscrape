#include <fstream>
#include <algorithm>  
using namespace std;

#define N 1030

const char in[]="cmlsc.in";
const char out[]="cmlsc.out";

int n,m,a[N],b[N],c[N][N];

void citire()
{
	ifstream fin(in);
	fin>>n>>m;
	for(int i=1;i<=n;i++)
		fin>>a[i];
	for(int i=1;i<=n;i++)
		fin>>b[i];
}

int maxim(int a,int b)
{
	if(a>b)
		return a;
	return b;
}

int main()
{
	citire();
	int s=0,sol[N];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			if(a[i]==b[j])
				c[i][j]=1+c[i-1][j-1];
			else
				c[i][j]=maxim(c[i-1][j],c[i][j-1]);
		}
	ofstream fout(out);
	//fout<<c[n][m]<<'\n';
	int i=n;
	int j=m;
	s=0;
	while(i && j)
	{
		if(a[i]==b[j])
		{
			sol[++s]=a[i];
			i--;
			j--;
		}
		else
			if(c[i-1][j] < c[i][j-1])
				j--;
			else
				i--;
	}
	fout<<s<<'\n';
	for(int i=s;i>=1;i--)
		fout<<sol[i]<<' ';
	fout<<'\n';
	return 0;
}