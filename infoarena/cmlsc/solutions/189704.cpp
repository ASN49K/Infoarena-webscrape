#include<stdio.h>
#define NMax 1025
#define maxim(a, b) ((a > b) ? a : b)

int n,m,i,j,a[NMax],b[NMax];
int d[NMax][NMax];

void citire()
{
 scanf("%d %d",&n,&m);
 for(int i=1;i<=n;i++)
   scanf("%d",&a[i]);
 for(int j=1;j<=m;j++)
   scanf("%d",&b[j]);

}

void solve()
{
 for(i=1;i<=n;i++)
  for(j=1;j<=m;j++)
    if(a[i]==b[j])
      d[i][j]=1+d[i-1][j-1];
     else d[i][j]=maxim(d[i-1][j],d[i][j-1]);

 int bst=0,sir[NMax];
 for(i=n,j=m;i;)
    if(a[i]==b[j])
       sir[++bst]=a[i],--i,--j;
     else if(d[i-1][j]<d[i][j-1])
	     --j;
	    else --i;

 for(i=bst;i>=1;i--)
   printf("%d ",sir[i]);



}

int main()
{
 freopen("cmlsc.in","r",stdin);
 freopen("cmlsc.out","w",stdout);

 citire();
 solve();
 return 0;
}

