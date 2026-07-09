#include<stdio.h>

int sum,t,n,a,b,x,m;



int sol(int n)
{
	if(n>0) return 1;
	return 0;
}
void read()
{
 
	scanf("%d",&n);
	sum=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&m);
		sum=sum xor m;

	}
	if(sol(sum)==1) printf("DA\n");
	else printf("NU\n");
}


int main()
{
	freopen("nim.in","r",stdin);
	freopen("nim.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
		read();
}