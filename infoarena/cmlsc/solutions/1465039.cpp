#include<stdio.h>
int a[1050][1050],x[1050],y[1060],sol[1050],n,m,i,j,p,nr;
int max(int a, int b)
{

    if(a>b)
        return a;
    return b;
}
int main()
{

    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
        scanf("%d",&x[i]);
    for(i=1;i<=m;i++)
        scanf("%d",&y[i]);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {

            if(x[i]==y[j])
            {

                a[i][j]=a[i-1][j-1]+1;
            }
            else
                a[i][j]=max(a[i-1][j],a[i][j-1]);
        }
    printf("%d\n",a[n][m]);
    nr=a[n][m];

    while(nr)
    {
        if(x[n]==y[m])
        {
            p++;
            sol[p]=x[n];
            n--;
            m--;nr--;
        }
        else
        {
            if(a[n][m]==a[n-1][m])
                n--;
            else m--;

        }


    }
    for(i=p;i>=1;i--)
        printf("%d ",sol[i]);
    return 0;

}
