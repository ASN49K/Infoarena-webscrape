#include <algorithm>
#include <stdio.h>

using namespace std ;
int c ;

int divi(int a,int b) {
	while (b) {
		c=a%b ;
		a=b ; 
		b=c ;
	}
	c=a ;
	return c ; 
}

int main() {
	freopen ("euclid2.in" , "r" , stdin ) ;
	freopen ("euclid2.out" , "w" , stdout ) ;
	
	int n , x , y ;
	scanf ("%d" , &n ) ;
	for (int i=1 ; i<=n ; ++i) {
		scanf ("%d%d" , &x , &y) ;
		printf ("%d\n" , divi(x,y) ) ; 
	}
	
	return 0 ;
}
