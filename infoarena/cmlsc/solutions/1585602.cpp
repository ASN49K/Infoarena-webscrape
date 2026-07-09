#include <cstdio>
#include <algorithm>
using namespace std;
int n,m,v[1025][1025],a[1025],b[1025],i,j,r[1025],ct;
int main()
{freopen("cmlsc.in","r",stdin);
 freopen("cmlsc.out","w",stdout);
 scanf("%d%d",&n,&m);
 for(i=1;i<=n;i++)
    {scanf("%d",&a[i]);
    }
 for(i=1;i<=m;i++)
    {scanf("%d",&b[i]);
    }
 for(i=1;i<=n;i++)
    {for(j=1;j<=m;j++)
        {if(b[j]==a[i])v[i][j]=v[i-1][j-1]+1;
         else v[i][j]=max(v[i-1][j],v[i][j-1]);
        }
    }
 i=n;j=m;
 while(i>=1&&j>=1)
    {if(a[i]==b[j]){ct++;r[ct]=a[i];i--;j--;}
         else if(v[i][j-1]>v[i-1][j])j--;
         else i--;
    }
    printf("%d\n",ct);
 for(i=ct;i>=1;i--)
    printf("%d ",r[i]);

}
