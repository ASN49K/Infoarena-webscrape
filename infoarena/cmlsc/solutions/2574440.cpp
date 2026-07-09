#include <fstream>

#define nmax 1026
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");


int main(){
	int n , m, *sir1, *sir2, *res, i, j, maxi = 0;
	f >> n >> m;
	sir1 = new int[ n+1 ]();
	sir2 = new int[ m+1 ]();
	res = new int[ max(n, m) ]();
	short int dp[nmax][nmax]={ 0 };
    for( i = 1; i <= n; i++ ){
    	f >> sir1[i];
    }
    for( j = 1; j <= m; j++ ){
    	f >> sir2[j];
    }
    for ( i = 1; i <= n; i++)
    	for( j = 1; j <= m; j++){

    		if( sir1[i] != sir2[j] ){
    			dp[i][j] = max( dp[i-1][j], dp[i][j-1] );
    		}
    		else {
    			dp[i][j] = 1 + dp[i-1][j-1];
    		}
    	
    	}
    for ( i = n, j = m; i; ){
    	if( sir1[i] == sir2[j] ){
    		res[++maxi] = sir1[i];
    		--i;
    		--j;
    	}
    	else if( dp[i-1][j] < dp[i][j-1] ){
    		--j;
    	}
    	else {
    		--i;
    	}
    }
    g << maxi <<"\n";
    for( i = maxi; i ; --i)
    	g << res[i]<<" ";

    

}