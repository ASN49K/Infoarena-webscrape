#include<fstream>
#define nmax 1033
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int i,j,n , m ,k, A[nmax][nmax], v[nmax], a[nmax], Drum[nmax];
void read()
{
	int i , j , k;
	fin >> n >> m;
	for( i = 1; i <= n; i++ )
		fin >> v[i];
	for( i = 1; i <= m; i++ )
		fin >> a[i];
	for( i = 1; i <= n; i++ ) 
		for( j = 1; j <= m ; j++)
		{
			if(v[i] == a[j] )
			{
				A[i][j] = A[i-1][j-1] + 1;
			}
			else
				A[i][j] = max( A[i-1][j] , A[i][j-1]);
			
		}
		fout<< A[n][m] << '\n' ;
		i = 1;
		j = 1; 
		k = 1; 
		for ( i = 1; i <= A[n][m] ;i++)
		{
			//fout<< i <<" ";
			 for( j= 1; j <= n ; j++)
			 {
				 
				 for( k = 1; k <= m ; k++)
				 {
					// fout<< A[j][k] << " " ;
					 if(i - A[j][k] == 0)
					 {
						fout << v[j] <<" ";
						j =  n+1;
						break; 
					 }
					
				 }
				 
				
			 }
			
		}
}
int main(){
	read();
	fin.close();
	fout.close();
	return 0;
	
}
