#include<cstdio>
using namespace std;
int euclid(int a,int b)
{
    int s;
    while(b)
    {
        s=b;
        b=a%b;
        a=s;
    }
    return a;
}
int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    int t,x,y;
    scanf("%d",&t);
    for(int i=1; i<=t; ++i)
    {
        scanf("%d%d",&x,&y);
        printf("%d \n",euclid(x,y));
    }
    return 0;
}
