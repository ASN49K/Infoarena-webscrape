#include <iostream>
#include <fstream>

using namespace std;

int v1[10005] , v2[10005] , M[10005][10005] , afis[10005] , k;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int main()
{
    int m , n;
    fin >> n >> m;

    for( int i = 1 ; i <= n ; ++i )
		fin >> v1[i];

	for( int j = 1 ; j <= m ; ++j )
		fin >> v2[j];

	for( int i = 1 ; i <= n ; ++i )
		for( int j = 1 ; j <= m ; ++j )
			if(v1[i] == v2[j])
				M[i][j] = 1 + M[i-1][j-1];
			else
				M[i][j] = max( M[i-1][j] , M[i][j-1] );

	for( int i = n , j = m ; i && j ; )
		if( v1[i] == v2[j] )
			afis[k+1] = v1[i], --i , --j , ++k;
		else if( M[i-1][j] < M[i][j-1] )
			--j;
		else
			--i;

	fout << k << '\n';

	for( int i = k ; i ; --i )
		fout << afis[i] << " ";
}
