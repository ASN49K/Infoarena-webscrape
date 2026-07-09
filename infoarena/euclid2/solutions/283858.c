#include<stdio.h>

long t;
long long int a,b,i;

long long int cmmdc(long long int a, long long int b)
{

if(b==0)return a;
else return cmmdc(b,a%b);
}


int main(void){

freopen("euclid2.in","r",stdin);
freopen("euclid2.out","w",stdout);

scanf("%ld",&t);

for(i=1; i<t+1; i++){scanf("%lld %lld",&a,&b); printf("%lld\n",cmmdc(a,b));}

return 0;
}