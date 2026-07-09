#include<stdio.h>
#define maxn 1030
using namespace std;

int n,m;
int x[maxn],y[maxn];
int s[maxn][maxn],step[maxn][maxn];

void read()
{
    int i;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++) scanf("%d",&x[i]);
    for(i=1;i<=m;i++) scanf("%d",&y[i]);
}

void solve()
{
    int i,j;

    for(i=1;i<=n;i++)
     for(j=1;j<=m;j++)
      if(x[i]==y[j])
      {
          s[i][j]=s[i-1][j-1]+1;
          step[i][j]=1;
      }
      else
       if(s[i-1][j]>=s[i][j-1])
       {
           s[i][j]=s[i-1][j];
           step[i][j]=2;
       }
       else
       {
           s[i][j]=s[i][j-1];
           step[i][j]=3;
       }
}

void print(int i,int j)
{
    if(step[i][j]==0) return;

    if(step[i][j]==1)
    {
        print(i-1,j-1);
        printf("%d ",x[i]);
    }
    else
     if(step[i][j]==2)
      print(i-1,j);
     else print(i,j-1);
}

int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);

    read();
    solve();
    printf("%d\n",s[n][m]);
    print(n,m);

    fclose(stdin);
    fclose(stdout);
    return 0;
}
