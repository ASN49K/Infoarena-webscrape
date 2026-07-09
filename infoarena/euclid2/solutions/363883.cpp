#include <stdio.h>

int a,b,n;

int cmmdc(int x,int y){
	if(!y)return x;
	else return cmmdc(x,x%y);
}
int main(){
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	
	scanf("%u",&n);
	while(n>0){
		n--;
		scanf("%u %u",&a,&b);
		printf("%u\n",cmmdc(a,b));
	}

	return 0;
}