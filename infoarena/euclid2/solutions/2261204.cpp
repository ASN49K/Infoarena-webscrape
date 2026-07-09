#include<bits/stdc++.h>
#define LL long long 
using namespace std;

int gcd(int a, int b) {
	if(!b) return a;
	return gcd(b , a % b);
}

int main () {
	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);
	int test;
	scanf("%d", &test);
	while(test--) {
		int a , b;
		scanf("%d %d", &a , &b);
		printf("%d\n", gcd(a , b));
	}
}