#include <cstdio>
using namespace std;
#define NM 1026
int d[NM][NM];
int n,m;
int a[NM],b[NM],v[NM];
/****************/
inline int max(int x,int y)
{if (x>y) return x;
 return y;
}
/****************/
int main()
{freopen("cmlsc.in","r",stdin);
 freopen("cmlsc.out","w",stdout);
 scanf("%d %d",&n,&m);
 int i,j,k=0;
 for (i=1;i<=n;i++) scanf("%d",&a[i]);
 for (i=1;i<=m;i++) scanf("%d",&b[i]);
 for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
                {d[i][j]=d[i-1][j];
                 d[i][j]=max(d[i][j],d[i][j-1]);
                 if (a[i]==b[j])
                        d[i][j]=max(d[i][j],d[i-1][j-1]+1);
                }
 printf("%d\n",d[n][m]);
 i=n;j=m;
 while (i>0&&j>0)
        {if (a[i]==b[j])
                {v[++k]=a[i];i--;j--;}
         else
                {if (d[i-1][j]>d[i][j-1]) i--;
                 else j--;
                }
        }
 for (i=k;i>=1;i--) printf("%d ",v[i]);
 return 0;
}
 
