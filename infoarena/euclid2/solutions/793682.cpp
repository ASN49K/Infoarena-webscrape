#include <cstdio>
using namespace std;
long a,b,x,i,n;
int main()
{
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	scanf("%ld",&n);
	for(i=1;i<=n;i++){scanf("%ld %ld",&a,&b);while(b){x=b;b=a%b;a=x;}printf("%ld\n",a);}
return 0;
}