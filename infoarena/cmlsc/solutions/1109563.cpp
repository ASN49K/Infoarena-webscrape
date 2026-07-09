#include<stdio.h>
using namespace std;
int x[1025],y[1025],a[1025][1025],n,m,sir[1025],l;
int max(int a,int b)
{
    if(a>b)
    return a;
    return b;
}
int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    scanf("%d %d", &n, &m);
    int i,j;
    for(i=1;i<=n;i++)
    scanf("%d", &x[i]);
    for(i=1;i<=m;i++)
    scanf("%d", &y[i]);
    for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
    if(x[i]==y[j])
    a[i][j]=a[i-1][j-1]+1;
    else
    a[i][j]=max(a[i-1][j],a[i][j-1]);
    i=n;
    j=m;
    for (i = n, j = m; i; )
    {
        if(x[i]==y[j])
        {
            l++;
            sir[l]=x[i];
            i--;
            j--;
        }
         else if (a[i-1][j] < a[i][j-1])
            --j;
        else
            --i;
    }
    printf("%d\n",l);
    for(i=l;i>=1;i--)
    printf("%d ",sir[i]);
    return 0;
}
