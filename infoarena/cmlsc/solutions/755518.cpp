#include<fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int m,n,i,j;
int a[1030],b[1030],t[1030],max,k;

int main()
{
	fin>>m>>n;
	for(i=1;i<=m;i++)
		fin>>a[i];
	for(i=1;i<=n;i++)
		fin>>b[i];
	
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
			if(a[i]==b[j])
				k++;
	fout<<k<<'\n';
	int x = k;
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
			if(a[i] == b[j])
				t[k--] = a[i];
	for(i=x;i>=1;i--)
			fout<<t[i]<<' ';
	return 0;
}