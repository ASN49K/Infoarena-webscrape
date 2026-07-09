#include<fstream>
#include<cstring>
#include<algorithm>
#define NN 201
typedef  char Byte;
using namespace std;
ofstream fout("codul.out");
Byte n,m,x[NN],y[NN],lcs[NN][NN];
void citire();
void dinamic();
void afis();
int main()
{
	citire();
	dinamic();
	afis();
	return 0;
}
void citire()
{
	ifstream fin("codul.in");
	fin.getline(x,NN);
	n=strlen(x);
	fin.getline(y,NN);
	m=strlen(y);
}
void dinamic()
{
	int k,h;
	for(k=1;k<=n;k++)
		for(h=1;h<=m;h++)
			if(x[k]==y[h])
				lcs[k][h]=1+lcs[k-1][h-1];
			else
				lcs[k][h]=max(lcs[k-1][h],lcs[k][h-1]);
}
void afis()
{
	Byte d[NN];
	int i,rez=0,j;
			for(i=n,j=m;i;)
		if(x[i]==y[j])
{
				d[++rez]=x[i];
			--i;
		--j;
		}
			else
				if(lcs[i-1][j]<lcs[i][j-1])
			--j;
			else
		--i;
			for(int k=rez;k;--k)
			fout<<d[k];
}
