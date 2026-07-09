#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	int a,b,r,t;
	scanf("%d",&t);
	for ( ; t > 0; --t) {
	scanf("%d%d",&a,&b);
	if ( a < b)
		swap(a,b);
	while ( b) {
		
		r = a % b;
		a = b;
		b = r;
	}
	printf("%d\n",a);
}
}
