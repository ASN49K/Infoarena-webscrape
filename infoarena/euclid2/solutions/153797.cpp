#include <stdio.h>
int a,b,t;

int cmmdc(int a, int b){
	if(b==0)
		return a;
	return cmmdc(b,a%b);
}

int main(){
	int i;
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		scanf("%d%d",&a,&b);
		printf("%d\n",cmmdc(a,b));
	}
	fclose(stdout);
	return 0;
}