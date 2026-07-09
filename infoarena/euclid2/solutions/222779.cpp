#include<stdio.h>
int n;
int cmmdc(int a,int b){
	int r=a%b;
	while (r){
		a=b;
		b=r;
		r=a%b;
	}
	return b;
}
int main(){
	int i,a,b;
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	scanf("%d",&n);
	for (i=1;i<=n;++i){
		scanf("%d%d",&a,&b);
		printf("%d\n",cmmdc(a,b));
	}
	return 0;
}
		
