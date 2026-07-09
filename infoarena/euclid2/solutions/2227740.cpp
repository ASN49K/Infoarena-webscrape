///SIDE NOTE : NEVER EVER USE STREAMS ON INFOARENA
#include <cstdio>

using namespace std;

int gcd(int a,int b)
{
    int r;
    while(b!=0) {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}

int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);

    int t,i,a,b;

    scanf("%d",&t);
    for(i=1;i<=t;i++) {
        scanf("%d %d",&a,&b);
        printf("%d\n",gcd(a,b));
    }

    return 0;
}
