#include <stdio.h>

using namespace std;

int cmmdc(int a, int b)
{
    if(!b) return a;
    return cmmdc(b,a%b);
}

int main()
{int t,a,b,i;
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    scanf("%d", &t);
    for(i=1;i<=t;i++)
    {
        scanf("%d%d",&a,&b);
        printf("%d\n",cmmdc(a,b));
    }
    return 0;
}
