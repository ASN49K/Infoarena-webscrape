#include<iostream>
#include<fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int m,n,a[1024],b[1024],lcs[1024][1024];
void afiseaza(int i,int j);
void citire()
{
	f>>m>>n;
	for(int i=1;i<=m;i++)
		f>>a[i];
	for(int i=1;i<=n;i++)
		f>>b[i];
}
void parcurgere()
{
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			if(a[i]==b[j])
				lcs[i][j]=lcs[i-1][j-1]+1;
			else if(lcs[i-1][j]>lcs[i][j-1])
				lcs[i][j]=lcs[i-1][j];
			else lcs[i][j]=lcs[i][j-1];
	g<<lcs[n][m]<<"\n";
	afiseaza(n,m);
}
void afiseaza(int i, int j)
{
	if(lcs[i][j])
		if(a[i]==b[j])
		{
			afiseaza(i-1,j-1);
			g<<a[i]<<" ";
		}
		else 
			if(lcs[i][j]==lcs[i-1][j])
				afiseaza(i-1,j);
		else afiseaza(i,j-1);
}
int main()
{
	citire();
	parcurgere();
}
