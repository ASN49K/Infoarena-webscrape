#include<stdio.h>
int main()
{
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	int t;long a,b;
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		scanf("%ld%ld",&a,&b);
		while(a!=b){
			if(a>b) a=a-b;
			else b=b-a;
		}
		printf("%ld",a);printf("\n");
	}
	return 0;
}