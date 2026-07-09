#include<stdio.h>
int a[1050],b[1050],s[1050][1050],m,n,i,j;
void citire()
{scanf("%d%d",&n,&m);
for(i=1;i<=n;i++)
    scanf("%d",&b[i]);
for(i=1;i<=m;i++)
   scanf("%d",&a[i]);}
void rez()
{int k=1;
    for(i=1;i<=m;i++)
    for(j=1;j<=n;j++)
        if(a[i]==b[j])
          s[i][j]=1+s[i-1][j-1];
        else
           if(s[i-1][j]>s[i][j-1])
               s[i][j]=s[i-1][j];
           else s[i][j]=s[i][j-1];
    printf("%d\n",s[m][n]);
for(i=1;i<=m;i++)
    for(j=1;j<=n;j++)
        if(s[i][j]==k)
       { printf("%d ",a[i]);
       k++; i++; j++;} printf("\n");      
}
           
int main()
{ freopen("cmlsc.in","r",stdin);
  freopen("cmlsc.out","w",stdout);
citire();
rez();

return 0;}
  