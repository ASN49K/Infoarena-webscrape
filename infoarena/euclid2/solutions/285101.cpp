#include<stdio.h>

int cmmdc(int a,int b){
	int r;
	r=a%b;
	while(r){
		a=b;
		b=r;
		r=a%b;
	}
	return b;
}

int main(){
	int n,x,y,z;
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;i++){
		scanf("%d%d",&x,&y);
		z=cmmdc(x,y);
		printf("%d\n",z);
	}
	return 0;
}
