#include <iostream>
#include<cstdio>
using namespace std;

int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    int n,i,cmmdc,r,b;
    scanf("%d", &n);
    for(i=1;i<=n;i++)
    {
        scanf("%d%d", &cmmdc, &b);
        while(b!=0)
        {
            r=cmmdc%b;
            cmmdc=b;
            b=r;
        }
        printf("%d\n", cmmdc);
    }
    return 0;
}
