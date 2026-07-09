#include <stdio.h>

int euclid(int a,int b){
	return b==0?a:euclid(b,a%b);
}

int main(){
	int t,a,b;
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&a,&b);
		printf("%d\n",euclid(a,b));
	}
	return 0;
}