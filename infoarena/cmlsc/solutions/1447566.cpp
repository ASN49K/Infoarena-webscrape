#include <algorithm>
#include <stdio.h>
#define DIM 1025

using namespace std;

int n , m , sol ;
int v1[DIM] ;
int v2[DIM] ;
int d[DIM][DIM] ;
int s[DIM] ;

int maxim(int A,int B) {
	if (A>B) return A ;
	return B ;
}

int main() {
	freopen ("cmlsc.in" , "r" , stdin) ;
	freopen ("cmlsc.out" , "w" , stdout) ;
	
	scanf ("%d%d" , &n , &m ) ;
	for (int i=1 ; i<=n ; ++i) {
		scanf ("%d" , &v1[i]) ;
	}
	for (int i=1 ; i<=m ; ++i) {
		scanf ("%d" , &v2[i]) ;
	}		
	for (int i=1 ; i<=n ; ++i) {
		for (int j=1 ; j<=m ; ++j) {
			if (v1[i]==v2[j]) {
				d[i][j] = d[i-1][j-1] + 1 ;
			}
			else {
				d[i][j]=maxim(d[i-1][j],d[i][j-1]) ;
			}
		}
	}
	int x=n , y=m ;
	while (x && y) {
		if (v1[x]==v2[y]) {
			s[++sol]=v1[x] ;
			x-- ;
			y-- ;
		}
		else {
			if ( d[x-1][y] < d[x][y-1] )
				y-- ;
			else
				x-- ;
		}
	}	
	printf ("%d\n" , sol ) ;
	
	for (int i=sol ; i>0 ; --i) {
		printf ("%d " , s[i]) ;
	}	
		
	return 0 ;
}
