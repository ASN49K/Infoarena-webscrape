#include<stdio.h>
#define maxim(a,b) ((a>b)? a : b)
#define nmax 1024
int n,m,a[nmax],b[nmax],d[nmax][nmax],sir[nmax],bst;
int main()
{
int i,j;
freopen("cmlsc.in","r",stdin);
freopen("cmlsc.out","w",stdout);

scanf("%d%d",&m,&n);
for (i=1;i<=m;i++) 
    scanf("%d",&a[i]);
for (i=1;i<=n;i++)
    scanf("%d",&b[i]);
for (i=1;i<=m;i++)
    for (j=1;j<=n;j++)
        if (a[i]==b[j])
           d[i][j]=d[i-1][j-1]+1;
           else
               d[i][j]=maxim(d[i-1][j],d[i][j-1]);
for (i=m,j=n;i;)
    if(a[i]==b[j])
        {
        sir[++bst]=a[i];
        --i;
        --j;
        }
        else if(d[i-1][j]<d[i][j-1])
             --j;
             else
             --i;
printf("%d\n",bst);
for (i=bst;i;--i)
    printf("%d ",sir[i]);
return 0;
}
           
