#include <stdio.h>
int main(){
	int a,b,r;
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	scanf("%d%d",&a,&b);
	while(a%b){
		r=a%b;
		a=b;
		b=r;
	}
	printf("%d",b);
}