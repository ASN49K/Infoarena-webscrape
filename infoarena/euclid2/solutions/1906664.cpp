#include <bits/stdc++.h>
using namespace std;

int shit(int a,int b)
{
    int r;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}

void cit()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
}
int a,b,n;
int main()
{
    cit();
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d %d",&a,&b);
        printf("%d\n",shit(a,b));

    }
    return 0;
}
