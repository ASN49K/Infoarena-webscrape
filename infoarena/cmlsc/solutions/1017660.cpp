#include <iostream>
#include <cstdio>
using namespace std;

int a[1030],b[1030],lg[1030][1030];
int m,n;

int boundaries(int i,int j)
{
    if ( i<=n && j<=m ) return 1;
    return 0;
}

void drum(int i, int j)
{
    if (!i || !j)
        return;
    if (a[i]==b[j])
    {
        drum(i-1,j-1);
        printf("%d ",a[i]);
    }
    else
    {
        if (lg[i-1][j] >= lg[i][j-1])
            drum(i-1,j);
        else
            drum(i,j-1);
    }
    return;
}

void citire()
{

    scanf("%d%d",&n,&m);
    for (int i=1; i<=n; i++)
         scanf("%d",&a[i]);
    for (int i=1;i<=m;i++)
         scanf("%d",&b[i]);
}

void bordare()
{
    for (int i=0; i<=n+1; i++)
         lg[i][0]=lg[i][m+1]=0;

    for (int i=0; i<=m+1; i++)
         lg[0][i]=lg[0][n+1]=0;
}

int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    citire();
    bordare();

    for (int i=1; i<=n; i++)
         for (int j=1; j<=m; j++)
              if (a[i]==b[j])
                  lg[i][j]=lg[i-1][j-1]+1;
              else lg[i][j]=max(lg[i-1][j],lg[i][j-1]);
    printf("%d\n",lg[n][m]);
    drum(n,m);



    return 0;
}
