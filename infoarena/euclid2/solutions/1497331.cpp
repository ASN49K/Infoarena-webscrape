#include <cstdio>

using namespace std;

int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    int a,b,r,t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        scanf("%d%d",&a,&b);
        while (1==1)
        {
            r=a%b;
            if(r==0) break;
            a=b;
            b=r;
        }
        printf("%d\n",b);
    }
    return 0;
}
