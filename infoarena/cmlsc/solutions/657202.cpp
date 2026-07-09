//cel mai lung subsir comun, O(M*N), 05.01.2012
#include<iostream>
#include<fstream>
using namespace std;
const int lmax=1025;
int m,n,a[lmax],b[lmax],c[lmax][lmax];

void citire()
{
	ifstream fin ("cmlsc.in");
	fin>>m>>n;
	for (int i=1;i<=m;++i)
		fin>>a[i];
	for (int i=1;i<=n;++i)
		fin>>b[i];
	fin.close();
}
void calculare()
{
	for (int i=1;i<=m;++i)
		for (int j=1;j<=m;++j)
			if (a[i]==b[j])
				c[i][j]=c[i-1][j-1]+1;
			else 
				c[i][j]= ( c[i-1][j]>c[i][j-1] ? c[i-1][j] : c[i][j-1] );
}
int rez[lmax],k=0;
void trace()
{
	int i=m,j=n;
	while (c[i][j]!=0)
	{
		if (a[i]==b[j])
		{
			rez[k++]=a[i];
			--i;--j;
		}
		else 
			if (c[i-1][j]>c[i][j-1])
				--i;
			else 
				--j;
	}		
}
void scrie()
{
	ofstream fout("cmlsc.out");
	fout<<c[m][n]<<endl; //colt dr jos tabel
	for (int i=k-1;i>=0;--i)
		fout<<rez[i]<<' ';
	fout.close();
}
int main ()
{
	citire();
	calculare();
	trace();
	scrie();
}