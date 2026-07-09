#include<stdio.h>
long cmmdc(long a, long b)
{long r;
while(b!=0)
	{
	r=a%b;
	a=b;
	b=r;
	}
return a;
}
int main()
{
long n,m,t;
FILE* in=fopen("euclid2.in","r");
FILE* out=fopen("euclid2.out","w");
fscanf(in,"%ld",&t);
for(long i=0;i<t;i++)
   {fscanf(in,"%ld%ld",&n,&m);
   fprintf(out,"%ld\n",cmmdc(n,m));
   }
return 0;
}