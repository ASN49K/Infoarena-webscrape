#include <iostream>
#include <fstream>
#define dim 1025
using namespace std;

int a[dim][dim], n, m;
int x[dim], y[dim];
int afis[dim];

int maxim(int a, int b)
{
	if (a>b) return a;
	else return b;
}

int prel(int &p)
{
	int i=n;
	for (int j=m; j>0; j--)
		for (int k=i; k>0; k--)
			if (a[k][j]==maxim(a[k][j-1], a[k-1][j])+1){
				p++;
				afis[p]=x[k];
				i=k-1;
				break;
			}
}

int main()
{
	ifstream fin("cmlsc.in");
	ofstream fout("cmlsc.out");
	fin>>n>>m;
	for (int i=1; i<=n; i++) fin>>x[i];
	for (int i=1; i<=m; i++) fin>>y[i];
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++){
			if (x[i]==y[j])
				a[i][j]=a[i-1][j-1]+1;
			else a[i][j]=maxim(a[i-1][j], a[i][j-1]);
		}
	int p=0;
	prel(p);
	fout<<p<<endl;
	for (int i=p; i>=1; i--) fout<<afis[i]<<" ";
	fin.close();
	fout.close();
	return 0;
}
