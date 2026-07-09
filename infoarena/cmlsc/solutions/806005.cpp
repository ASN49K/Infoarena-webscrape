#include<cstdio>
using namespace std;
#define maxim(a,b) ((a>b)?a:b)
int A[1100],B[1100],n,m,i,D[1100][1100],j,sir[1100],bst,max;
void read();void solve();
int main()
{
    read();
    solve();
    return 0;
}
void read()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++) scanf("%d",&A[i]);
    for(i=1;i<=m;i++) scanf("%d",&B[i]);
}
void solve()
{
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(A[i]==B[j]) {D[i][j]=1+D[i-1][j-1];sir[++bst]=A[i];}
            else D[i][j]=maxim(D[i-1][j],D[i][j-1]);
        }
    }
    max=D[1][1];
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(D[i][j]>max) max=D[i][j];
        }
    }
    printf("%d\n",max);
    for(i=1;i<=bst;i++) printf("%d ",sir[i]);
}
