#include<stdio.h>
#define dim 1024
int a[dim],b[dim],v[dim][dim],nr[dim],x,n,m,i,k,;
void read()
{
     scanf("%d%d",&n,&m);
     for(i=1;i<=n;i++)
              scanf("%d",&a[i]);
     for(k=1;k<=m;k++)
     scanf("%d",&b[k]);
     
}
int max(int x,int y)
{
    if(x>y)
    return x;
    return y;
}
void fill()
{
     for(i=1;i<=n;i++)
     for(k=1;k<=m;k++)
     {
                      if(a[i]==b[k])
                      v[i][k]=v[i-1][k-1]+1;
                      else
                      v[i][k]=max(v[i-1][k],v[i][k-1]);
                      }
}
void find ()
{
     for(i=n,k=m;i>=1 && k>=1;)
    {
                      if(a[i]==b[k])
                      {
                                    nr[x++]=a[i];
                                    i--;
                                    k--;
                                    continue;
                                    }
                      if(v[i-1][k]>v[i][k-1])
                      i--;
                      else
                      k--;
                      }
printf("%d\n",--x);
for(i=x;i>=1;i--)
printf("%d ",nr[i]);
}
void afis()
{
     for(i=1;i<=n;i++,printf("\n"))
     for(k=1;k<=m;k++)
     printf("%d ",v[i][k]);
     printf("\n");
}
void solve()
{
     freopen("cmlsc.in","r",stdin);
     freopen("cmlsc.out","w",stdout);
     
     read();
     fill();
     find();
}
int main ()
{
    x=1;
    solve();
return 0;
}
