#include <bits/stdc++.h>

using namespace std ;
 
ifstream fin ("cmlsc.in") ;
ofstream fout ("cmlsc.out") ;

const int MAX = 1030 ; 

int dp [MAX][MAX] ;
pair <short int, short int> last [MAX][MAX] ;
int A [MAX] ; 
int B [MAX] ; 

void rec (int xx, int yy) {
	// cout << xx << ' ' << yy << '\n' ; 
	if (! (xx >= 1 and yy >= 1)) {
		return ; 
	}
	rec (last [xx][yy].first, last [xx][yy].second) ; 
	if (A [xx] == B [yy])
		fout << A [xx] << ' ' ; 
}

int main(int argc, char const *argv[])
{
	// return 0 ; 
	int n, m ; 
	fin >> n >> m ; 
	for (int i = 1 ; i <= n ; ++ i) {
		fin >> A [i] ;
	}
	for (int i = 1 ; i <= m ; ++ i) {
		fin >> B [i] ;
	}	
	for (int i = 1 ; i <= n ; ++ i) {
		for (int j = 1 ; j <= m ; ++ j) {
			if (A [i] == B [j]) {
				dp [i][j] = dp [i - 1][j - 1] + 1 ; 
				last [i][j] = {i - 1, j - 1} ; 
			}
			else {
				if (dp [i - 1][j] > dp [i][j - 1]) {
					last [i][j] = {i - 1, j} ; 
				}
				else {
					last [i][j] = {i, j - 1} ; 
				}
				dp [i][j] = max (dp [i - 1][j], dp [i][j - 1]) ; 
			}
		}
	}
	// return 0 ;
	fout << dp [n][m] << '\n' ; 
	rec (n, m) ; 
	return 0;
}