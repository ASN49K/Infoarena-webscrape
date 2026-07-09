#include<fstream.h>
#define MAX 1025
int n,m,a[1025],b[1025],sc[MAX][MAX];
ofstream fout("cmlsc.out");


void citire()
{
	ifstream fin("cmlsc.in");
	int i;
	fin>>n>>m;
	for(i=1;i<=n;i++)
		fin>>a[i];
	for(i=1;i<=m;i++)
		fin>>b[i];
	fin.close();
}


int max(int x, int y)
{
	if(x>y) return x;
	return y;
}



void sol()
{
	int i,j,sir[MAX],nr=0;
	for(i=n, j=m;i;)
		if(a[i]==b[j])
			sir[++nr]=a[i], i--, j--;
		 else
			 if(sc[i-1][j]<sc[i][j-1])
				 j--;
				else i--;
	for(i=nr;i>0;i--)
		fout<<sir[i]<<' ';
}




void numara()
{
	int i,j;
	for (i=0;i<=MAX;i++)
		sc[0][i]=0, sc[i][0]=0;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(a[i]==b[j])
				sc[i][j]=sc[i-1][j-1]+1;
			 else
				 sc[i][j]=max(sc[i-1][j],sc[i][j-1]);


	fout<<sc[n][m]<<'\n';
	sol();
}


int main()
{
	citire();
	numara();
	fout.close();
	return 0;
}
