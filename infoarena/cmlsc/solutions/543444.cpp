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

/*
void lcs(int a[], int b[])
{
	int ret[N_MAX],t[N_MAX],max,x,y,c,i,k;
	
	//while(1)
	{
		//int c;					//counter for identification of max length subsequece in array
		int prevPoz = 0;		//index position of previous identified common character in sequence
		k = -1;
		//c = max = 0;
		//int x = (n < m) ? n : m;	
		//int y = (n < m) ? m : n;
		//cout << "n=" << n << endl << "m=" << m; 
		c = 0;
		///*
		if(m < n)
		for(int i = 1; i <= m; ++i)				
		{
			for(int j = 1; j <= n; ++j)
			{
				//cout << a[i] << "- " << b[j] << endl;
				if( a[i] == b[j] && j > prevPoz){		//actual position has to be bigger than the last before 
					c++, prevPoz = j, ret[++k] = a[i];
					break;
				}
			}
			//if(c > max)
			//	,c = 0;
		}
		else
		
			for(int j = 1; j <= m; ++j)			
				{
				for(int i = 1; i <= n; ++i)
				{
					//cout << a[i] << "- " << b[j] << ";";
					if( b[j] == a[i] && i > prevPoz){		//actual position has to be bigger than the last before 
						c++, prevPoz = i, t[++k] = a[i];
						break;
					}
				}
				if(c > max)
					max = c;
				}
	}
	
	cout << "max = " << c << endl;
	for(i = 0; i <= k; ++i)
		cout << ret[i] << " ";
	
	//return 0; 
}
*/

void print_lcs(int i,int j) 	//void print_lcs(int b[][],X[][], i,j)
{
	if (i==0 || j==0)
		return;
	if(i > 0 && j >0)
		if( b[i][j] == 11 ){
			print_lcs(i-1,j-1);
			//cout << X[i] << " ";
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