#include <cstdio>

using namespace std;

int a[1025],b[1025],v[1025][1025],sol[1025];

int max1(int a,int b)
{
    if (a>b)
    return a;
    return b;
}

int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    int n,m;
    scanf("%d %d",&n,&m);
    for (int i=1;i<=n;i++)
        scanf("%d ",&a[i]);
    for (int i=1;i<=m;i++)
        scanf("%d ",&b[i]);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        {
            if (a[i]==b[j])
                v[i][j]=v[i-1][j-1]+1;
            else
                v[i][j]=max1(v[i-1][j],v[i][j-1]);
        }
    int max2=-1300,i1,j1;
    int i,j;
    for (int i1=1;i1<=n;i1++)
    {
        for (int j1=1;j1<=m;j1++)
        if (v[i1][j1]>=max2)
        {
            max2=v[i1][j1];
            i=i1;
            j=j1;
        }
    }
    /*for (int j1=1;j1<=n;j1++)
    {
        for (int i1=i;i1<=m;i1++)
        printf("%d ",v[j1][i1]);
        printf("\n");
    }*/
    int k=0;
    while (i>0 && j>0)
    {
        if (v[i-1][j]==v[i][j])
            i--;
        else
        {
            if (v[i][j-1]==v[i][j])
            j--;
            else
            {
                if (v[i-1][j-1]==v[i][j]-1)
                {
                    sol[++k]=a[i];
                    i--;
                    j--;
                }
            }
        }

    }
    printf("%d\n",max2);
    for (int i=k;i>=1;i--)
        printf("%d ",sol[i]);
}
