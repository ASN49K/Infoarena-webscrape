#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

int T,a,b;

int main(){

	freopen("euclid2.in", "r", stdin );
	freopen("euclid2.out", "w", stdout );
	
	scanf("%d", &T );
	
	for( int i = 0; i < T; i++ ){
	
		scanf("%d%d", &a, &b );
		
		int rest = 0;
		while( b != 0 ){
			rest = a%b;
			a = b;
			b = rest;
		}
		
		printf("%d\n", a );
	}
	
	return 0;
}