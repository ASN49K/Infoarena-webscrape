#include<stdio.h>
int rin(int a,int b)
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
    int i,t,x,y;
    freopen("euclid2.in","rt",stdin);
    freopen("euclid2.out","wt",stdout);
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d%d",&x,&y);
        printf("%d\n",rin(x,y));
    }
    fclose(stdin);
    fclose(stdout);
}
