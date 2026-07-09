#include<cstdio>
using namespace std;
long cmmdc(long d,long i)
 {long r,aux;
if(d<i){aux=d;d=i;i=r;}
	 r=d%i;
	 while(r!=0)
	 {
		 d=i;
		 i=r;
		 r=d%i;
	 }
	 return i;
 }
 long a,b,n,i,x;
int main()
{
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	scanf("%ld",&n);
	for(i=0;i<n;i++)
	 {
	   scanf("\n%ld %ld",a,b);
	   x=cmmdc(a,b);
	   printf("%ld\n",x);
	 }
return 0;}
