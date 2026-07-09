#include <iostream>
#include <cstdio>

using namespace std;

long t,i,n,v,j,s;
int main()
{
    freopen("nim.in","r",stdin);
    freopen("nim.out","w",stdout);
    scanf("%ld",&t);
    for (i=1;i<=t;i++)
    {
        scanf("%ld",&n);
        s=0;
        for (j=1;j<=n;j++)
        {
            scanf("%ld",&v);
            s=s^v;
        }
        if (s>0) printf("DA\n");
        if (s==0) printf("NU\n");
    }
    return 0;
}
