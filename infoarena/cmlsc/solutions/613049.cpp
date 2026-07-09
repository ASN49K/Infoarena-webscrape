#include <stdio.h>

using namespace std;

int a[260][260];
int A[260];
int B[260];
int n;
int m;


int max(int a, int b)
{
    if(a>b)
        return a;
    return b;
}

void citire()
{
    scanf("%d %d",&n,&m);
    for(int i=1 ; i<=n ;i++)
    {
        scanf("%d",&A[i]);
    }
    for(int i=1 ; i<=m ;i++)
    {
        scanf("%d",&B[i]);
    }

}

void rez()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            a[i][j]=max(a[i-1][j],a[i][j-1]);
            if(A[i]==B[j])
            {
                a[i][j]++;
                j++;
                for(;j<=m;j++)
                    a[i][j]=max(a[i-1][j],a[i][j-1]);
            }
        }
    }
    printf("%d\n",a[n][m]);
}

void afis(int i, int j)
{
    if(a[i-1][j]==a[i][j-1] && a[i-1][j]==0 && a[i][j]==1)
    {
        printf("%d ",A[i]);
        return;
    }
    if(a[i-1][j]<a[i][j] && a[i][j-1]<a[i][j])
    {
        if(a[i][j-1]>a[i-1][j])
        {
            afis(i,j-1);
        }
        else
        {
            afis(i-1,j);
        }
        printf("%d ",A[i]);
        return;
    }
    if(a[i][j-1]>a[i-1][j])
    {
        afis(i,j-1);
    }
    else
    {
        afis(i-1,j);
    }
}



int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    citire();
    rez();
    afis(n,m);
    return 0;
}
