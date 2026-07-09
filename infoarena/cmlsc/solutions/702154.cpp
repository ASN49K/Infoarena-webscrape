#include<fstream>
#include<iostream>
using namespace std;
#define NN 1024
ofstream out("cmlsc.out");
int x[NN],y[NN],n,m,lcs[NN][NN];
void citire();
void dinamic();
int main()
{
	
	citire();
	dinamic();
	out<<lcs[n][m];
	out<<'\n';
	int i,j,i1,i2,d[NN],poz=0;;
	for(i=lcs[n][m];i>=1;--i)
	{
		
			for(i1=1;i1<=n;i1++)
				for(i2=1;i2<=m;i2++)
					if(lcs[i1][i2]==i&&x[i1]==y[i2])
						d[++poz]=x[i1];
	}
	for(j=poz;j;--j)
		out<<d[j]<<" ";
	return 0;
}
void citire()
{
	ifstream in("cmlsc.in");
	in>>n>>m;
	int i,j;
	for(i=1;i<=n;i++)
		in>>x[i];
	for(j=1;j<=m;j++)
		in>>y[j];
}
void dinamic()
{
	int h,k;
	for(h=1;h<=n;h++)
		for(k=1;k<=m;k++)
			if(x[h]==y[k])
				lcs[h][k]=1+lcs[h-1][k-1];
			else
				lcs[h][k]=max(lcs[h-1][k],lcs[h][k-1]);
}

