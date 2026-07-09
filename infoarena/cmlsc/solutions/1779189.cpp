#include <stdio.h>
#define Nmax 1024
#define maxim(a,b) ((a>b)?a:b)
using namespace std;

int a[Nmax],b[Nmax],d[Nmax][Nmax],sir[Nmax],best,m,n;

int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d%d",&m,&n);

    for(int i=1;i<=m;i++)
        scanf("%d",&a[i]);
    for(int j=1;j<=n;j++)
        scanf("%d",&b[j]);

        for(int i=1;i<=m;i++)
          for(int j=1;j<=n;j++)
            if(a[i]==b[j])
              d[i][j]=1+d[i-1][j-1];
            else
              d[i][j]=maxim(d[i-1][j],d[i][j-1]);

        for(int i=m,j=n;i>0;)
          if(a[i]==b[j])
            sir[++best]=a[i],i--,j--;
          else
            if(d[i-1][j]<d[i][j-1])
              j--;
            else
              i--;
        printf("%d\n",best);
        for(int i=best;i>0;--i)
            printf("%d ",sir[i]);



}
