#include <cstdio>
using namespace std;
int n, i, a, b;
int euclid(int x, int y){
	if(!y)
		return x;
	return euclid(y, x % y);
}
int main(){
	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);
	scanf("%d ", &n);
	for(i = 1; i <= n; ++i){
		scanf("%d %d ", &a, &b);
		printf("%d\n", euclid(a, b));
	}
}
