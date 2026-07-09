#include<cstdio>
using namespace std;

int f(int x, int y){
	if(y == 0)
		return x;
	else return f(y, x%y);
}

int main(){
	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);
	int n; int a, b, i;
	scanf("%d", &n);
	for(i = 0; i < n; i++){
		scanf("%d%d", &a, &b);
		printf("%d\n", f(a, b));
	}

return 0;
}
