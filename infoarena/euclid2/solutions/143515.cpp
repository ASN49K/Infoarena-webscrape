#include <stdio.h>
int a,b;

int cmmdc(int a, int b){
	if(a==b)
		return a;
	if(a>b)
		return cmmdc(a-b,b);
	else
		return cmmdc(a,b-a);
}

int main(){
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	scanf("%d%d",&a,&b);
	printf("%d\n",cmmdc(a,b));
	fclose(stdout);
	return 0;
}