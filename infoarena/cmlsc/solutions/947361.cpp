#include <cstdio>

using namespace std;
int a[1025],b[1025],r[1025][1025],i,j,n,m,sol[1024],Max;
int max (int a, int b)
{
    if(a>b) return a;
    return b;
}
void drum()
{ int q,w,x;
   Max=r[n][m]; printf("%d\n",Max); x=0; q=n; w=m;
    while (x<Max)
    {
        if (a[q]==b[w]) {sol[++x]=a[q]; q--; w--;}
        else
        {
            if (r[q][w-1]>=r[q-1][w]) w--;
            else q--;
        }
    }
    for (i=Max; i>=1; i--) printf("%d ",sol[i]);
}
void problema()
{
    int i;
    if(a[1]==b[1]) r[1][1]=1;
    else r[1][1]=0;
    for(i=2;i<=m;i++)
{
    if(b[i]==a[1]) r[1][i]=1;
    else r[1][i]=r[1][i-1];
}
    for(i=2;i<=n;i++)
    {
      if(a[i]==b[1]) r[i][1]=1;
      else r[i][1]=r[i-1][1];
    }
for(i=2;i<=n;i++)

{
    for(j=2;j<=m;j++)
       if(a[i]==b[j]) r[i][j]=r[i-1][j-1]+1;
       else r[i][j]=max(r[i-1][j],r[i][j-1]);
}
}
int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
    scanf("%d",&a[i]);
    for(i=1;i<=m;i++)
    scanf("%d",&b[i]);
problema();
drum();

    return 0;
}
