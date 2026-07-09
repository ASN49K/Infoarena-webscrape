#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
struct elem{
	int i = 0, j = 0;
};
int dp[1030][1030], a[1030], b[1030];
elem t[1030][1030];
vector <int> r;
int main(){
	int n, m, i, j, x, y;
	ifstream fin( "cmlsc.in" );
	ofstream fout( "cmlsc.out" );
	fin >> n >> m;
	for( i = 1; i <= n; i++ ){
		fin >> a[i];
	}
	for( i = 1; i <= m; i++ ){
		fin >> b[i];
	}
	for( i = 1; i <= n; i++ ){
		for( j = 1; j <= m; j++ ){
			if( a[i] == b[j] ){
				dp[i][j] = dp[i - 1][j - 1] + 1;
				t[i][j] = { i - 1, j - 1 };
			}
			else if( dp[i - 1][j] > dp[i][j - 1] ){
				dp[i][j] = dp[i - 1][j];
				t[i][j] = { i - 1, j };
			}
			else{
				dp[i][j] = dp[i][j - 1];
				t[i][j] = { i, j - 1 };
			}
			//cout << i << ' ' << j << ' ' << dp[i][j] << ' ' << a[i] << ' ' << b[j] << '\n';
			//cout << dp[i][j] << ' ';
		}
		//cout << '\n';
	}
	i = n;
	j = m;
	while( i > 0 && j > 0 ){
		if( a[i] == b[j] ){
			r.push_back( a[i] );
		}
		x = t[i][j].i;
		y = t[i][j].j;
		i = x;
		j = y;
	}
	//cout << dp[n][m] << '\n';
	fout << r.size() << '\n';
	for( i = r.size() - 1; i >= 0; i-- ){
		fout << r[i] << ' ';
	}
	return 0;
}