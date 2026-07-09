#include <cstdio>
#include <cstdlib>
using namespace std;

long gcd (long a, long b) {
	while(b) {
		long tmp=a;
		a=b;
		b=tmp%a;
	}
	return a;
}
int main() {
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	long t;
	scanf("%ld",&t);
	while(t--) {
		long a,b;
		scanf("%ld",&a);
		scanf("%ld",&b);
		printf("%ld\n",gcd(a,b)));
	}
	return 0;
}

