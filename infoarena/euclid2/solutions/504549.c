#include<stdio.h>

int cmmdc(int a,int b)
{
	int r;
	while (r=a%b){
		a=b;
		b=r;
	}
	return b;
}

int main()
{
	int n,i,a,b;
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
    scanf("%d",&n);
	for (i=0;i<n;i++){
		scanf("%d%d",&a,&b);
		printf("%d\n",cmmdc(a,b));
	}
	return 0;
}

