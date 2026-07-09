#include<cstdio>
using namespace std;
int main()
{
    int t,a,b;
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        scanf("%d %d ",&a,&b);
        if(b>a)
        {
            int c=a;
            a=b;
            b=c;
        }
        while(b)
        {
            int c=a%b;
            a=b;
            b=c;
        }
        printf("%d \n",a);
    }
}
