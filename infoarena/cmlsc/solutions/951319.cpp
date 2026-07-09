#include <cstdio>

using namespace std;
int l[100][100],a[100],b[100],n,m,i,j,MMax,contor,final[100];
int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d%d",&n,&m);

    for (i=1; i<=n; i++)
        scanf("%d",&a[i]);
    for (j=1; j<=m; j++)
        scanf("%d",&b[j]);


    for (i=1; i<=n; i++)
        if (a[i]==b[1] || l[i-1][1]==1) l[i][1]=1;
    for (i=1; i<=m; i++)
        if (a[1]==b[i] || l[1][i-1]==1) l[1][i]=1;


    for (i=2; i<=n; i++)
        for (j=2; j<=m; j++)
            if (a[i]==b[j]) l[i][j]=l[i-1][j-1]+1;
            else
            {
                if(l[i-1][j]>l[i][j-1])
                    MMax=l[i-1][j];
                else MMax=l[i][j-1];
                l[i][j]=MMax;
            }


    printf("%d\n",l[n][m]);

    i=n;
    j=m;
    while (l[i][j]!=0)
    {
        if (a[i]==b[j])
        {
            contor=contor+1;
            final[contor]=a[i];
            i=i-1;
            j=j-1;
        }
        else
        {
            if (l[i-1][j]>l[i][j-1]) i=i-1;
            else j=j-1;
        }
    }


    for (i=contor; i>=1; i--)
        printf("%d ",final[i]);

    return 0;
}
