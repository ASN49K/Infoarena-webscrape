#include<stdio.h>
int n,a1,b1;
int alg_euclid(int a,int b);
int main()
{
	int i,j,k;
	freopen("royfloyd.in","r",stdin);
	freopen("royfloyd.out","w",stdout);
	scanf("%d",&n);
	for(;n;--n){
		scanf("%d %d",&a1,&b1);
		printf("%d\n",alg_euclid(a1,b1));
	}	
	fcloseall();
	return 0;
}
int alg_euclid(int a,int b)
{
	if(!b)
		return a;
	return alg_euclid(b,a%b);
}
