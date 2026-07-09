#include<stdio.h>
int a[1026][1026],v[1026],x[1026];
int n,m;

void read()
{
scanf("%d%d",&n,&m);
int i;
for (i=1;i<=n;i++)
     scanf("%d",&v[i]);
for (i=1;i<=m;i++)
    {
     scanf("%d",&x[i]);
    }
}

inline int max(int a,int b)
{
if (a>b)
    return a;
return b;
}

void cmlsc()
{
int i,j;
for (i=1;i<=n;i++)
     for (j=1;j<=m;j++)
         {
          if (v[i]==x[j])
              a[i][j]=a[i-1][j-1]+1;
          else a[i][j]=max(a[i-1][j],a[i][j-1]);
         }
}

void rec(int i,int j)
{
if (a[i][j]==0)
    return ;
if (v[i]==x[j])
   {
    rec(i-1,j-1);
    printf("%d ",v[i]);
   }
else
     if (a[i-1][j]>a[i][j-1])
        {
         rec(i-1,j);
        }
    else rec(i,j-1);
}

int main()
{
freopen("cmlsc.in","r",stdin);
freopen("cmlsc.out","w",stdout);
read();
cmlsc();
printf("%d\n",a[n][m]);
rec(n,m);
return 0;
}

