#include<stdio.h>
int t,a,r,b,Cmmdc();
void read(), solve();
int main()
{
	read();
	solve();
	return 0;
}
void read()
{
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	scanf("%d",&t);
}
void solve()
{
	for(;t;t--)printf("%d\n",Cmmdc());
}
int Cmmdc()
{
	scanf("%d%d",&a,&b);
	while(b){r=a%b;a=b;b=r;}
	return a;
}

