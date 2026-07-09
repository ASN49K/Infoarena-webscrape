#include <cstdio>

using namespace std;
int n,m;
int a[1050],b[1050];
int t[1050][1050];
int sir[1050];
int max(int a,int b)
{
    if(a>b) return a;
    return b;
}

int main()
{freopen("cmlsc.in","r",stdin);
freopen("cmlsc.out","w",stdout);
/*

0 if i=0 or j=0
t[i-1][j-1]+1 if a[i]==b[j]
max(t[i-1][j],t[i][j-1]) if a[i]!=b[i]

*/
scanf("%d%d",&n,&m);
for(int i=1;i<=n;i++) scanf("%d",&a[i]);
for(int i=1;i<=m;i++) scanf("%d",&b[i]);
for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            {
                if(a[i]==b[j]) t[i][j]=t[i-1][j-1]+1;
                else
                    {
                        t[i][j]=max(t[i-1][j],t[i][j-1]);
                    }
            }
    }
printf("%d\n",t[n][m]);
int bst=0;
for(int i=n,j=m;i;)
    {
        if(a[i]==b[j]) sir[++bst]=a[i],i--,j--;
        else
            {
                if(t[i-1][j]<t[i][j-1]) j--;
                else i--;
            }
    }
for(int i=bst;i;i--) printf("%d ",sir[i]);
}
