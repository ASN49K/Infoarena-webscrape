#include<stdio.h>
int main()
{
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	int t;long a,b,c;
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		scanf("%ld%ld",&a,&b);
		while(b){
			c=a%b;a=b;b=c;
		}
		printf("%ld\n",a);
	}
	return 0;
}