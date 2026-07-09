#include<stdio.h>
int main()
{
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	int n,a,b,d,c=0;
	scanf("%d",&n);
	while(c<n){
		scanf("%d%d",&a,&b);
		while(a%b!=0){
			d=a%b;
			a=b;
			b=d;
		}
		printf("%d\n",b);
		c++;
	}

return 0;
}
