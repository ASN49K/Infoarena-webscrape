#include <algorithm>
#include <stdio.h>

using namespace std;

int cmmdc(int a,int b) {
	int c;
	while (b) {
		c=a%b ;
		a=b ;
		b=c ;
	} 
	return a ;
}

int main() {
	int n, x, y;
	freopen ("euclid2.in","r",stdin) ;
	freopen ("euclid2.out","w",stdout) ;

	scanf ("%d" , &n) ;
	for (int i=1 ; i<=n ; ++i) {
		scanf ("%d%d", &x , &y)  ;
		printf ("%d\n" , cmmdc(x,y)) ;
	}
	
	return 0;
}
