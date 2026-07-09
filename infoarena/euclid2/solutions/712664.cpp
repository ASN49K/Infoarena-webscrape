#include <iostream>
#include <stdio.h>
using namespace std;

int T,a,b;

int cmmdc(int x,int y)
{
     if (!y)
        return x;
    return cmmdc(y,x%y);
}

int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    scanf ("%d",&T);
    for (int i=0;i<T;++i)
    {
        scanf("%d%d",&a,&b);
        printf("%d\n",cmmdc(a,b));
    }
    return 0;
}
