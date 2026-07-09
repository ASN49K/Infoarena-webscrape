#include<stdio.h>


int v[1030][1030], a[1030] ,b[1030],c[1030],i,j,n,m,max=0,k=0,x,y;

int main()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
 
	 scanf("%d %d",&n,&m);
 
 for(i=1;i<=n;i++)
  scanf("%d",&a[i]);
 
 for(i=1;i<=m;i++)
  scanf("%d",&b[i]);
 
 
for(i=1;i<=n;i++)
 for(j=1;j<=m;j++)
 
   if(a[i]==b[j]) { v[i][j]=v[i-1][j-1]+1;
 
            if(v[i][j]>=max) { max=v[i][j]; x=i; y=j;}
          }
 
     else if(v[i][j-1]>v[i-1][j]) v[i][j]=v[i][j-1];
 
             else v[i][j]=v[i-1][j];


   i=x; j=y;
 
while(v[i][j])
 
 if(a[i]==b[j]) { c[++k]=a[i]; i--;j--;}
     else if(v[i-1][j]==v[i][j]) i--;
      else j--;

 printf("%d\n",k);
 
for(i=k;i>=1;i--)
printf("%d ",c[i]);

return 0;
}