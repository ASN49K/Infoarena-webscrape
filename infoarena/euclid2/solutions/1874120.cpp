#include <bits/stdc++.h>
using namespace std;
int q,a,b,c;
int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    scanf("%d",&q);
    while(q)
    {
        q--;
        scanf("%d%d",&a,&b);
        while(b)
        {
            c=a%b;
            a=b;
            b=c;
        }
        printf("%d\n",a);
    }
    return 0;
}
