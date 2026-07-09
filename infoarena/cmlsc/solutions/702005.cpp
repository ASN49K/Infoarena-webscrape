#include<fstream>
#define nmax 1025
using namespace std;
ifstream fin("cmlsc.in");ofstream fout("cmlsc.out");
int n,m,a[nmax],b[nmax],s[nmax];
void citire()
{
	fin>>m>>n;int i;for(i=1;i<=m;i++)	fin>>a[i];	for(i=1;i<=n;i++)	fin>>b[i];
}
void subsir()
{
	int i,j,x=1,k=1;
	for(i=1;i<=m;i++)
	{
		j=x;
		while(j<=n)
		{
			if(a[i]==b[j])	
			{x=j;s[k]=a[i];k++;}
			j++;
		}
	}
	fout<<k-1<<'\n';
	for(i=1;i<k;i++)	fout<<s[i]<<' ';
}
int main()
{
	citire();
	subsir();
	return 0;
}