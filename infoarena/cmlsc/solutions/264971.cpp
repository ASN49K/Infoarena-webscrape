#include<stdio.h>
#include<string.h>
#define dim 1024
int a[dim][dim],n,m;
int v[dim];
/*void read()
{
     char x[dim],i;
     gets(x);
     m=strlen(x);
     for(i=2;i<=m+1;i++)
     a[0][i]=x[i-2]-'0';
     gets(x);
     n=strlen(x);
     for(i=2;i<=n+1;i++)
     a[i][0]=x[i-2]-'0';
}
*/
void read()
{
     scanf("%d%d",&n,&m);
     int i,k;
     for(i=2;i<=n+1;i++)
     scanf("%d",&a[i][0]);
     for(i=2;i<=m+1;i++)
     scanf("%d",&a[0][i]);
}
int max(int x,int y)
{
    if(x>y)
    return x;
    return y;
}
void print()
{
     int i,k;
     for(i=0;i<=n;i++,printf("\n"))
     for(k=0;k<=m;k++) printf("%d ",a[i][k]);
}
int find()
{
    
    int x,i,k;
   // x=a[n][m];
  //  v[x]=max(a[n][0],a[0][m]);
    //for(i=n,k=m;i>=2 || k>=2;i--,k--)
    for(i=n;i>=2;i--)
    for(k=m;k>=2;k--)
    {
                     x=a[i][k];
                             if(a[i][0]==a[0][k])
                           // if(a[i-1][k-1]==x-1)
                             {
                                           v[x]=max(a[i][0],v[x]);
                                           v[x]=max(a[0][k],v[x]);
                                           }
                         //    printf("%d %dx\n",x,v[x]);
                             
}
for(i=1;i<=a[n][m];i++)
printf("%d ",v[i]);
}
void solve()
{
    // print();
     int i,k;
     n++;
     m++;
     for(i=2;i<=n;i++)
     for(k=2;k<=m;k++)
     {
                      if(a[0][k]==a[i][0])
                      {
                                          a[i][k]=a[i-1][k-1]+1;
                                          continue;
                                          }
                      a[i][k]=max(a[i-1][k],a[i][k-1]);
                      }
//print();
printf("%d\n",a[n][m]);
find();
}

int main ()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    read();
    solve();
return 0;
}
