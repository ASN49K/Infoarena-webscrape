#include <stdio.h>
int cmmdc(int a,int b){
	if(a%b==0)
		return b;
	return cmmdc(b,a%b);
}
int main(){
	int a,b;
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	scanf("%d%d",&a,&b);
	printf("%d",cmmdc(a,b));
}