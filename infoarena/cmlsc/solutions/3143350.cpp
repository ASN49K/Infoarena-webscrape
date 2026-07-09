#include<iostream>
#include<fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n, m, v1[100001], v2[100001];
int sol[100001];
void LCS(int *str1, int *str2,int n ,int m)
{
	int tabel[n+1][m+1];
	for(int i=0; i<=n; i++)
		for(int j=0; j<=m; j++)
		{
			if( i==0 || j==0 )	tabel[i][j]=0;
			else if( str1[i-1]==str2[j-1] )	tabel[i][j]=1+tabel[i-1][j-1];
			else tabel[i][j] = max( tabel[i][j-1], tabel[i-1][j] );
		}
	int i=n, j=m, index=tabel[n][m];
	while( i>0 && j>0 )
	{
	 	if( str1[i-1]==str2[j-1] )	
	 		{ sol[index-1] = str1[i-1];
	 	i--; j--; index--; }
	 	else if(tabel[i-1][j] > tabel[i][j-1]) i--;
	 	else j--;
	}
	fout << tabel[n][m]<<endl;
	for(int k=0; k<tabel[n][m]; k++)
	{
		fout << sol[k]<< " ";
	}

}
int main()
{
	fin>>n>>m;
	for(int i=0; i<n; i++)
		fin>>v1[i];
	for(int j=0; j<m; j++)
		fin>>v2[j];
	LCS(v1, v2, n , m);
}