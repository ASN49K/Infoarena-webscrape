#include<cstdio>
#define MAX 1024
using namespace std;

int max (int a,int b)
{   if (a>=b) return a;
    else      return b;
}
int main ()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    int n,m,v1[MAX],v2[MAX],a[MAX][MAX],rez[MAX];
    int i,j,l,c,nr=0;
    scanf("%d",&n);
    scanf("%d",&m);
    for (i= 1 ; i<= n ; i ++)
        scanf("%d",&v1[i]);
        
    for (i= 1 ; i<= m ; i ++)
        scanf("%d",&v2[i]);
        
    for (i=0;i<MAX;i++)
        for (j=0;j<MAX;j++)
            a[i][j]=0;
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
            if (v1[i]==v2[j])
               a[i][j]=a[i-1][j-1]+1;          
            else
               a[i][j]=max(a[i][j-1],max(a[i-1][j-1],a[i-1][j])); 
    i=n;j=m;
    printf ("%d\n",a[i][j]);
    while (a[i][j]!=0)
    {
    if (v1[i]==v2[j])
       {nr++; rez[nr]=v1[i];}
    if (a[i-1][j]>=a[i][j-1])
       i--;
    else
       j--;    
    }
    for (i=nr;i>=1;i--)
        printf ("%d ",rez[i]);
}
