#include <cstdio>

void euclid(int a,int b,int &d)
{
    if(b==0)
    {
        d = a;
        return ;
    }
        euclid(b,a%b,d);
}

int main()
{
    int t,a,b,d;
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&a,&b);
        euclid(a,b,d);
        printf("%d\n",d);
    }

    return 0;
}
