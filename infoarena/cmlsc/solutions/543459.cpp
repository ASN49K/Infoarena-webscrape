#include <fstream>
#include <iostream>
using namespace std;

#define FIN "cmlsc.in"
#define FOUT "cmlsc.out"
#define N_MAX 1025

ifstream fin(FIN);
ofstream fout(FOUT);
int n,m;
int c[N_MAX][N_MAX],b[N_MAX][N_MAX];
int X[N_MAX],Y[N_MAX],LCS[N_MAX];

void print_lcs(int i,int j) 	
{
	if(i==0 || j==0)
		return;
	if(i > 0 && j >0)
		if( b[i][j] == 1 ){
			print_lcs(i-1,j-1);
			cout << X[i] << " ";
		}
		else if( b[i][j] == 2 ){
			print_lcs(i-1,j); 
		}
		else print_lcs(i,j-1);
}

int lcs_length(int x[N_MAX], int y[N_MAX])
{
	int i,j;
	
	//for(i = 1; i <= n; ++i) 
	//	c[i][0] = 0;
	//for(j = 1; j <= m; ++j)
	//	c[0][j] = 0;
		
	for(i = 1; i <= n; ++i)
		for(j = 1; j <= m; ++j)
			if( x[i] == y[j] )
			{
				c[i][j] = c[i-1][j-1] +1;
				b[i][j] = 1;
			} else if (c[i-1][j]  > c[i][j-1])
				c[i][j] = c[i-1][j], b[i][j] = 2;
				else 
					c[i][j] = c[i][j-1], b[i][j] = 3;
	
	return c[n][m];
}

void readData()
{
	fin >> n >> m;
	for(int i = 1; i <= n; ++i){
		fin >> X[i];
	}
	//cout << endl;
	for(int i = 1; i <=m; ++i){
		fin >> Y[i]; 
	}
	//cout << endl;
}

void print_lcs_norec(int i, int j)
{
	int k = 0;
	while(i != 0 && j != 0)
	{
		if(X[i] == Y[j]) LCS[k++] = X[i],--i,j--;
		else if(c[i-1][j] == c[i][j]) i--;
		else if(c[i][j-1] == c[i][j]) j--; 
	}
	//cout << c[n][m] << endl;
	for(int kk=k-1; kk >= 0; kk-- ) fout << LCS[kk] << " ";
	fout << endl;
}

int main()
{
	readData();

	fout <<  lcs_length(X,Y) << endl;
	
	//print_lcs(n,m);
	//fout << endl;
	print_lcs_norec(n,m);
	
	return 0;
}