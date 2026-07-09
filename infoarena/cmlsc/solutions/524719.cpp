#include<iostream>
#include<fstream>
#include<string.h>
#define NMax 201
#define Max(a, b) ((a>b)?a:b)

using namespace std;

int x[NMax],y[NMax],l[NMax][NMax],n,m;

void Citire()
{
    ifstream fin("cmlsc.in");

    fin>>n>>m;
	for(int i=0;i<n;++i)
        fin>>x[i];
    for(int j=0;j<m;++j)
    {
        fin>>y[j];
    }

fin.close();
}
void Dinamic()
{
	short i,j;
	for(i=n-1;i>=0;i--)

		for(j=m-1;j>=0;j--)

			if(x[i]==y[j])
				l[i][j]=1+l[i+1][j+1];
			else
				l[i][j]=Max(l[i+1][j],l[i][j+1]);
}
void Afisare()
{
ofstream fout("cmlsc.out");
	int d[NMax];
	int i=0,j=0,max,poz=0,ix,iy,k;
	for(k=l[0][0];k>0;k--)
	{
		//caut poz de inceput a unui subsir de lungime i care incepe cu cea mai mare cifra
		max=-1;
		for(ix=i;ix<n;ix++)
			for(iy=j;iy<m;iy++)
				if(l[ix][iy]==k&&x[ix]==y[iy]&& max<x[ix])
				{
					max=x[ix];
					i=ix;
					j=iy;
				}
		d[poz++]=max;
	}
	fout<<poz<<'\n';
	for(k=0;k<poz;k++)
		fout<<d[k]<<' ';
fout.close();
}
int main()
{
	Citire();
	Dinamic();
	Afisare();
	return 0;
}
