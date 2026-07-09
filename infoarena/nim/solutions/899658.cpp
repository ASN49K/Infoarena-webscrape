#include<cstdio>
int t,n,i,x,rez;
int main()
{
    freopen("nim.in","r",stdin);
    freopen("nim.out","w",stdout);
    scanf("%d",&t);
    while(t)
    {
        scanf("%d",&n);
        rez=0;
        for(i=0;i<n;++i)
        {
            scanf("%d",&x);
            rez^=x;
        }
        if(rez==0)printf("NU\n");
        else printf("DA\n");
        --t;
    }
    return 0;
}
