#include<stdio.h>
#define DIM 101
int n,m,a[DIM],b[DIM],sol[DIM],v[DIM][DIM],q;
void read ()
{
    int i;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;++i)
        scanf("%d",&a[i]);
    for(i=1;i<=m;++i)
        scanf("%d",&b[i]);
}
int max (int x,int y)
{
    if(x<y)
        return y;
    return x;
}
void solve ()
{
    int i,j;
    for(i=1;i<=n;++i)
        for(j=1;j<=m;++j)
            if(a[i]==b[j])
                v[i][j]=v[i-1][j-1]+1;
            else
                v[i][j]=max ( v[i-1][j], v[i][j-1]);
    for(i=n,j=m;i&&j;)
    {
        if(a[i]==b[j])
        {
            sol[++q]=a[i];
            --i;
            --j;
        }
        else if(v[i-1][j]<v[i][j-1])
            --j;
        else
            --i;
    }
}
void show ()
{
    int i;
    printf("%d\n",q);
    for(i=q;i;--i)
        printf("%d ",sol[i]);
}
int main ()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    read ();
    solve ();
    show ();
    return 0;
}
