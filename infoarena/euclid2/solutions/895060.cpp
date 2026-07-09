#include<stdio.h>

int a,b,t;

int cmmdc(int a,int b){
	if(b==0)
		return a;
	if(a>b)
		return cmmdc(b,a%b);
	else
		return cmmdc(a,b%a);
}

int main(){
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		scanf("%d%d",&a,&b);
		printf("%d\n",cmmdc(a,b));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
