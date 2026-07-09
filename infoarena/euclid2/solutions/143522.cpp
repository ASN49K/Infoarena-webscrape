#include <stdio.h>
int a,b;

int cmmdc(int a, int b){
	while(a!=b){
		if(a>b)
			a=a-b;
		else
			b=b-a;
	}
	return a;
}

int main(){
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	scanf("%d%d",&a,&b);
	printf("%d\n",cmmdc(a,b));
	fclose(stdout);
	return 0;
}