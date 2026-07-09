#include<cstdio>

int f(int x, int y);

int n,a,b,i;
int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d%d",&a,&b);
        printf("%d\n",f(a,b));
    }
    return 0;
}

int f(int x, int y)
{
    if(y==0) return x;
    else f(y,x%y);
}
