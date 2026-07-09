#include <fstream>
#include <algorithm>
#include <vector>
#include <cstring>

#define NMAX 1026
#define get_max(a,b) ((a)>(b)?(a):(b))

using namespace std;

ifstream in ( "cmlsc.in" );
ofstream out ( "cmlsc.out" );

int DP[NMAX][NMAX] , N , M , A[NMAX] , B[NMAX] ;
vector < int > Sol;

int main ( void )
{
	int i , j ;
	in >> N >> M ;
	for ( i = 1 ; i <= N ; ++i )
		for ( j = 1 ; j <= M ; ++j )
			if ( A[i] == B[j] )
				DP[i][j] = DP[i-1][j-1] + 1 ;
			else DP[i][j] = get_max ( DP[i][j-1] , DP[i-1][j] );
	out << DP[N][M] << "\n";
	for ( i = N , j = M ; i ; )
		if ( A[i] == B[j] ) Sol.push_back(A[i]) , --i  , --j;
	else
		if ( DP[i][j-1] > DP[i-1][j] ) --j;
	else --i;
	for ( vector < int > ::iterator it = Sol.begin () ; it != Sol.end() ; ++it ) out << *it << " ";		
	in.close();
	out.close();
	return 0;
}