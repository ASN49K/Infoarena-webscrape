#include <stdio.h>
int euclid(int a,int b){
	int r;
	while(a%b){
		r=a%b;
		a=b;
		b=r;
	}
	return b;
}
int main(){
	int a,b,sol,t,i;
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		scanf("%d%d",&a,&b);
		sol=euclid(a,b);
		printf("%d\n",sol);
	}
	return 0;
}