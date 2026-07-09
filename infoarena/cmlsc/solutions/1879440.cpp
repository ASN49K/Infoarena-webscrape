#include <fstream>
#include <cstdio>

using namespace std;

ofstream cout("cmlsc.out");
int n,m,j,i,k;
short int a[1030],b[1030],c[1030][1030],sir[1030];
int main()
{
    FILE*cin=freopen("cmlsc.in","r",stdin);

    scanf("%d%d",&n,&m);

    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);

    for(i=1;i<=m;i++)
        scanf("%d",&b[i]);

    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
          if(a[i]==b[j])
                c[i][j]=c[i-1][j-1]+1;
          else
            c[i][j]=max(c[i-1][j],c[i][j-1]);
   cout<<c[n][m]<<'\n';
   for(i=n,j=m;i,j;)
        if(a[i]==b[j])
            sir[++k]=a[i],i--,j--;
        else
            if(c[i-1][j]>c[i][j-1])
                i--;
            else
                j--;
    for(;k;--k)
        cout<<sir[k]<<' ';
    return 0;
}
