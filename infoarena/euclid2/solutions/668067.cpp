#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	
	//freopen("euclid2.in", "r", stdin);
	//freopen("euclid2.out", "w", stdout);
	
	int t;
	
	scanf("%d", &t);
	
	int a, b, x;
	
	for(int i = 1; i <= t; ++ i){
		scanf("%d %d", &a, &b);
		for(int d = 2; d <= min(a, b); ++ d)
			if(!(a % d) && !(b % d))
				x = d;
		printf("%d\n" , x);
		
		x = 1;
	}
	
	return 0;
}
