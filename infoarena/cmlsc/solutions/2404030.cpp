#include <algorithm>
#include <fstream>
#include <vector>
using namespace std;

ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");

const int Dim = 1025;
int A[Dim],B[Dim],D[Dim][Dim];
vector < int > V;

int main() {
	
	int n,m;
	fin >> n >> m;
	for ( int i = 1; i <= n; ++i)
		fin >> A[i];
	for ( int i = 1; i <= m; ++i)
		fin >> B[i];
	for ( int i = 1; i <= n; ++i)
		for ( int j = 1; j <= m; ++j) {
			
			if ( A[i] == B[j] )
				D[i][j] = D[i-1][j-1] + 1;
			else
				D[i][j] = max(D[i-1][j], D[i][j-1]);
		}
		fout << D[n][m] << "\n";
		int i = n,j = m;
		while ( i >= 1 and j >= 1 ){
			if ( A[i] == B[j])
				V.push_back(A[i]),--i,--j;
			else
				if ( D[i][j] == D[i-1][j] )
					i = i-1;
			else
				if ( D[i][j] == D[i][j-1])
						j--;
		}
	reverse(V.begin(),V.end());
	for ( const int & x : V)
		fout << x << " ";
}	
