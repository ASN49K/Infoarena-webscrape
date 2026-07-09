#include<fstream>
#define nmax 1033
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int i,j,n , m ,k, A[nmax][nmax], v[nmax], a[nmax], Drum[nmax], L;
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
		
			 for( j = m , i = n ; j ;)
			 {
				if( v[i] == a[j] )
				{
					Drum[++L] = v[i];
					i--; j--; 
				}
				else
				{
					if(A[i-1][j] > A[i][j-1])
						i--;
					else
						j--;
				}
				 
				
			 }
		for(i = L;	i > 0; i-- )
			fout << Drum [i] << " ";
		
}
int main(){
	read();
	fin.close();
	fout.close();
	return 0;
	
}
