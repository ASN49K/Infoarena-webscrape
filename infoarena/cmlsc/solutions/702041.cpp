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
	int i,rez=0,d[NN],j;
	for(i=n,j=m;i;)
		if(x[i]==y[j])
		{
			d[++rez]=x[i];
			i--;
			j--;
		}
		else
			if(lcs[i-1][j]>lcs[i][j-1])
				i--;
			else
				j--;
			for(int k=rez;k>=1;--k)
				out<<d[k]<<" ";
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

