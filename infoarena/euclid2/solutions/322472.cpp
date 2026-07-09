#include<stdio.h>
int euc(int a,int b)
{
if(b==0) return a;
else return euc(b,a%b);
}
int main()
{
freopen("euclid2.in","r",stdin);
freopen("euclid2.out","w",stdout);
int a,b,N;
scanf("%d",&N);
for(int i=1;i<=N;++i)
{
scanf("%d %d",&a,&b);
printf("%d\n",euc(a,b));
}
return 0;
}
