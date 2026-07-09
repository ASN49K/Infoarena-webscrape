/// Craciun Catalin
///  CMLSC
///   www.infoarena.ro/problema/cmlsc
#include <fstream>
#include <iostream>

#define NMax 1025

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int n,m;
int A[NMax], B[NMax];
int L[NMax][NMax];

inline int maxim(int a, int b)
{
	if (a<b)
		return b;
	return a;
}

void citire()
{
	f>>n>>m;
	for (int i=1;i<=n;i++)
		f>>A[i];
	for (int i=1;i<=m;i++)
		f>>B[i];
	f.close();
}

void afisaux()
{
	for (int i=0;i<=n;i++)
	{
		for (int j=0;j<=m;j++)
			cout<<L[i][j]<<' ';
		cout<<endl;
	}
}

void programareDinamica()
{
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			if (A[i]==B[j])
				L[i][j]=L[i-1][j-1]+1;
			else
				L[i][j]=maxim(L[i-1][j], L[i][j-1]); 
				
	afisaux();
	g<<L[n][m]<<'\n';
}

void afisare()
{
	int x=n,y=m;
	int V[NMax];
	int poz=1;

	while (x && y)
		if (A[x]==B[y])
			V[poz++]=A[x], x--, y--;
		else if (L[x][y]==L[x][y-1])
				y--;
		else
			x--;
			
	for (int i=poz-1;i>1;i--)
		g<<V[i]<<' ';
	g<<V[1]<<'\n';
	
	g.close();
}

int main()
{
	citire();
	programareDinamica();
	afisare();
	
	return 0;
}
