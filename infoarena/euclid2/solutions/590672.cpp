#include<stdio.h>
int gcd(int x,int y){
	int z;
	while(y)
	{
		z=x;
		x=y;
		y=z%y;
	}
	return x;
}
int main(){
	int t,i,a,b;
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		scanf("%d%d",&a,&b);
		printf("%d\n",gcd(a,b));
	}
	return 0;
}
