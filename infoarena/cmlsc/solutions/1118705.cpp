#include <cstdio>
#define maxim(a, b) ((a > b) ? a : b)
using namespace std;
int a[1050],b[1050],d[1050][1050],sir[1050],bst;
int main()
{freopen("cmlsc.in","r",stdin);
freopen("cmlsc.out","w",stdout);
int n,m;
scanf("%d%d",&m,&n);
for(int i=1;i<=m;i++) scanf("%d",&a[i]);
for(int i=1;i<=n;i++) scanf("%d",&b[i]);
for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
            {
                if(a[i]==b[j]) d[i][j]=1+d[i-1][j-1];
                else d[i][j]=maxim(d[i-1][j],d[i][j-1]);
            }
    }
for(int i=m,j=n;i;)
    {
        if(a[i]==b[j]) sir[++bst]=a[i],i--,j--;
        else
            {
                if(d[i-1][j]<d[i][j-1]) j--;
                else i--;
            }
    }
printf("%d\n",bst);
for(int i=bst;i;i--) printf("%d ",sir[i]);
}
