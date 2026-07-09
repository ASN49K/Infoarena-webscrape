#include <cstdio>

using namespace std;

int cmmmdc(int a,int b)
{
    while(b>0)
        {
            int r=a%b;
            a=b;
            b=r;
        }
    return a;
}
int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    int a,b,T;
    scanf("%d\n",&T);
    for(int i=1;i<=T;i++)
    {
        scanf("%d %d",&a, &b);
        int s=cmmmdc(a,b);
        printf("%d\n",s);
    }
    return 0;
}
