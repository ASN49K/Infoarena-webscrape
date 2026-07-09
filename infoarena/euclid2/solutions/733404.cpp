#include<stdio.h>
using namespace std;
int div(int a, int b) {
	int c;
	while(b) {
		c=b;
		b=a%b;
		a=c;
	}
	return a;
}
int main() {
	freopen ("euclid2.in","r",stdin);
	freopen ("euclid2.out","w",stdout);
	int t,a,b;
	scanf("%d",&t);
	for(;t;t--) {
		scanf("%d %d",&a,&b);
		printf("%d\n", div(a,b));
	}
	return 0;
}
