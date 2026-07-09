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
int X[N_MAX],Y[N_MAX];

void print_lcs(int i,int j) 	
{
	if (i==0 || j==0)
		return;
	if(i > 0 && j >0)
		if( b[i][j] == 11 ){
			print_lcs(i-1,j-1);
			fout << X[i] << " ";
		}
		else if( b[i][j] == 22 ){
			print_lcs(i-1,j); 
		}
		else if( b[i][j] == 33 )
			print_lcs(i,j-1);
}

int lcs_length(int x[], int y[])
{
	int i,j;
	
	for(i = 1; i <= n; ++i) 
		c[i][0] = 0;
	for(j = 1; j <= m; ++j)
		c[0][j] = 0;
		
	for(i = 1; i <= n; ++i)
		for(j = 1; j <= m; ++j)
			if( x[i] == y[j] )
			{
				c[i][j] = c[i-1][j-1] +1;
				b[i][j] = 11;
			} else if (c[i-1][j]  >= c[i][j-1])
				c[i][j] = c[i-1][j], b[i][j] = 22;
				else 
					c[i][j] = c[i][j-1], b[i][j] = 33;
	
	return c[n][m];
}

void readData()
{
	fin >> n >> m;
	//cout << n << " " << m << endl;
	for(int i = 1; i <= n; ++i){
		fin >> X[i]; //cout << X[i] << ' ';
	}
	cout << endl;
	for(int i = 1; i <=m; ++i){
		fin >> Y[i]; //cout << Y[i] << ' ';
	}
	cout << endl;
}

int main()
{
	readData();
	
	//lcs(b,a);	
	
	int leng = lcs_length(X,Y);
	//cout <<  leng << endl;
	fout <<  leng << endl;
	print_lcs(n,m);
	fout << endl;
	//cout << endl;
	
	return 0;
}