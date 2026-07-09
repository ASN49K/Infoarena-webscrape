#include<cstdio>
long int n,a,b,c;
int main()
{
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	scanf("%ld",&n);
	while(n!=0){
		n--;
	scanf("%ld %ld",&a,&b);
	c=a%b;
	while(c!=0){
		a=b;
		b=c;
		c=a%b;
	}
	printf("%ld\n",b);
	}
	return 0;
}