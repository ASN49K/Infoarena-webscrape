#include <cstdio>

using namespace std;

long long int euclid(long long int a,long long int b)
{
    if(b==0) return a;
    else return euclid(b,a%b);
}

int main()
{freopen("euclid2.in","r",stdin);
freopen("euclid2.out","w",stdout);
long int n;
long long int a,b;
scanf("%ld",&n);
for(int i=1;i<=n;i++)
    {
        scanf("%lld%lld",&a,&b);
        printf("%lld\n",euclid(a,b));
    }
return 0;
}
