#include <algorithm>
#include <stdio.h>
#define DIM 1025

using namespace std;

int v1[DIM] ;
int v2[DIM] ;
int best[DIM][DIM] ;

int maax(int A,int B){
	if (A>B) return A;
	return B;
}

void afisare(int x, int y, int nr) {
	if (nr>0) {
		if (v1[x]==v2[y]) {
			afisare(x-1,y-1,nr-1) ;
			printf ("%d " , v1[x]) ;
		}
		else {
			if (best[x-1][y]<best[x][y-1])
				afisare(x,y-1,nr) ;
			else
				afisare(x-1,y,nr) ;
		}
	}
}

int main() {
	freopen ("cmlsc.in","r",stdin) ;
	freopen ("cmlsc.out","w",stdout) ;
	
	int n,m ;
	scanf ("%d%d" , &n , &m ) ;
	
	for (int i=1;i<=n;++i) scanf ("%d" , &v1[i]) ;
	for (int i=1;i<=m;++i) scanf ("%d" , &v2[i]) ;	

	for (int i=1;i<=n;++i) {
		for (int j=1;j<=m;++j) {
			if (v1[i]==v2[j]) best[i][j]=best[i-1][j-1]+1 ;
			else best[i][j]=maax(best[i-1][j],best[i][j-1]) ;
		}
	}
	int rez=best[n][m] ;
	
	printf ("%d\n" , rez) ;
	
	afisare(n,m,rez) ;
	
	return 0 ;
}
