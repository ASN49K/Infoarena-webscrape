#include <iostream>

int lnko(int a,int b) {
	if (!b) return a;
	else return lnko(b,a%b);
}
int main(void) {
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	int n,a,b;
	scanf("%d",&n);
	for (int i=0;i<n;i++){
		scanf("%d %d",&a,&b);
		printf("%d\n",lnko(a,b));
	}
}
