#include <cstdio>

using namespace std;

#define MAX(a,b) ((a)>(b)?(a):(b))

int i,j,a[1050],b[1050],sol[1050][1050],n,m;

void recon(int n,int m) {
	if(n == 0 || m == 0 )
		return;
	
	//if(sol[ n ][ m ] == 1 + sol[ n-1 ][ m-1 ]) {
	if(a[ n ] == b[ m ] ) {
		recon(n-1,m-1);
		printf("%d ",a[n]);
		return;
	}
	
	if(sol[ n ][ m ] == sol[ n-1 ][ m ]) {
		recon(n-1,m);
		return;
	}
	
	if(sol[ n ][ m ] == sol[ n ][ m-1 ]) {
		recon(n,m-1);
		return;
	}
}

int main() {
	
	//freopen("cmlsc.in","r",stdin);
	//freopen("cmlsc.out","w",stdout);
	
	scanf("%d %d",&n,&m);
	
	for( i = 1 ; i <= n ; i++ )
		scanf("%d",&a[i]);
	
	for( i = 1 ; i <= m ; i++ )
		scanf("%d",&b[i]);
	
	for( i = 1 ; i <= n ; i++ )
		for( j = 1 ; j <= m ; j++ )
			if( a[ i ] == b[ j ] ) sol[ i ][ j ] = 1 + sol[ i-1 ][ j-1 ];
			else sol[ i ][ j ] = MAX( sol[ i-1 ][ j ] , sol[ i ][ j-1 ] );
	
	printf("%d\n",sol[ n ][ m ]);
	
	recon(n,m);
		
	return 0;
}