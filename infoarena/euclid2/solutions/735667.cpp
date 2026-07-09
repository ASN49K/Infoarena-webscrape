#include<cstdio>
#include<algorithm>
using namespace std;
//BINARY GCD
int gcd(int a,int b)
{
    if(a>b) swap(a,b);
    if(a==0) return b;
    if(a==b) return a;
    if((a&1)&&(b&1)) return gcd((b-a)>>1,a);
    else if(a&1) return gcd(a,b>>1);
    else if(b&1) return gcd(a>>1,b);
    else return gcd(a>>1,b>>1)<<1;
}
int main()
{
    int a,b,t;
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    scanf("%d",&t);
    for(;t!=0;--t)
    {
        scanf("%d %d",&a,&b);
        printf("%d\n",gcd(a,b));
    }
    return 0;
}
