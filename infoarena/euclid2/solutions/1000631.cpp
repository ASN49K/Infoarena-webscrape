#include<cstdio>
using namespace std;
int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    int a,b,n,i,c;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d %d",&a,&b);
        while(b!=0)
        {
            c=a%b;
            a=b;
            b=c;
        }
        printf("%d\n",a);
    }
    return 0;
}
