#include<iostream>
#include<fstream>
#define DIM 1024
#define FOR(i,a,b) for(i=a;i<=b;i++)
using namespace std;
int D[DIM][DIM],A[DIM],B[DIM],n,m,nr,sol[DIM];
int maxim(int a,int b);
int main()
{
	ifstream fin("cmlsc.in");
	ofstream fout("cmlsc.out");
	int i,j;
	fin>>n>>m;
	FOR(i,1,n)
		fin>>A[i];
	FOR(j,1,m)
		fin>>B[j];
	FOR(i,1,n)
		FOR(j,1,m)
		{
			if(A[i]==B[j])
				D[i][j]=1+D[i-1][j-1];
			else
				D[i][j]=maxim(D[i-1][j],D[i][j-1]);
		}
	for(i=n,j=m;i;)
		if(A[i]==B[j])
			sol[++nr]=A[i],i--,j--;
		else
			if(D[i-1][j]<D[i][j-1])
				j--;
			else
				i--;
	fout<<nr<<"\n";
	for(i=nr;i>=1;i--)
		fout<<sol[i]<<" ";
	return 0;
}
int maxim(int a,int b)
{
	if(a>b)
		return a;
	return b;
}	