#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    int T,i;
    long long a,b,r;
    scanf("%d",&T);
    for (i=1;i<=T;i++)
        {
            scanf("%lld %lld", &a, &b);
            while (b)
            {
                r=a%b;
                a=b;
                b=r;
            }
            printf("%lld\n",a);
        }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
