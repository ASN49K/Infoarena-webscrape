#include <cstdio>
using namespace std;
int x,y,t;
int cmmdc(int a,int b)
{
    int r=0;
    while(b)
    {
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
    scanf("%d",&t);
    while(t)
    {
        t--;
        scanf("%d %d",&x,&y);
        printf("%d\n",cmmdc(x,y));
    }
    return 0;
}
