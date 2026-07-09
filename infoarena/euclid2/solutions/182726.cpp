#include<stdio.h>
long n,a1,b1;
long alg_euclid(long a,long b);
int main()
{
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	scanf("%d",&n);
	for(;n;--n){
		scanf("%d %d",&a1,&b1);
		printf("%d\n",alg_euclid(a1,b1));
	}	
	fcloseall();
	return 0;
}
long alg_euclid(long a,long b)
{
	if(!b)
		return a;
	return alg_euclid(b,a%b);
}
