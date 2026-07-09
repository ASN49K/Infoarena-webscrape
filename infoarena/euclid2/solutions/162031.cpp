#include<stdio.h>
/*
int cmmdc(int a,int b){
	if(a%b==0)
		return b;
	return cmmdc(b,a%b);
}
*/
int cmmdc(int a,int b){
	int r=a%b;
	while(r){
		a=b;
		b=r;
		r=a%b;
	}
	return b;
}
int main(){
	int a,b,t;
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&a,&b);
		printf("%d\n",cmmdc(a,b));
	}
	return 0;
}
