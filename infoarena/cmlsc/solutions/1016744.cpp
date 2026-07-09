#include <stdio.h>

using namespace std;
int m,n,i,j,k,a[1025],b[1025],c[1025][1025],sol[1025];

int max(int x,int y)
{
  if (x>y) return x;
       else return y;
};

int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d %d",&m,&n);
    for (i=1;i<=m;i++)
    {
      scanf("%d",&a[i]);

    };
    for (j=1;j<=n;j++)
    {
      scanf("%d",&b[j]);
      for (i=1;i<=m;i++)
       {
         if (b[j]==a[i]){c[i][j]=c[i-1][j-1]+1;k=k+1;sol[k]=b[j];}
                           else {c[i][j]=max(c[i-1][j],c[i][j-1]);};
       };
    };
    printf("%d\n",c[m][n]);
    for (i=1;i<=k;i++) printf("%d ",sol[i]);
    return 0;
}
