#include <cstdio>

using namespace std;

int euclid(int a,int b)
{
    int r;
    while(b!=0)
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
    int t,a,b;
    scanf("%d",&t);
    for(int i=1;i<=t;++i)
    {
        scanf("%d%d",&a,&b);
        printf("%d\n",euclid(a,b));
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
