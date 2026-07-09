#include<stdio.h>
#define nmax 257

int n,i,j,k, a[nmax][nmax], b[nmax][nmax];

int bf(int v)
{
int i,p,u;
int c[40];
p=u=1;
c[p]=v;
viz[v]=1;
while(p<=u)
{
x=c[p];
for(i=1;i<=n;i++)
  {
  if(a[x][i]==1 && viz[i]==0){
				u++;
				c[u]=i;
				viz[i]=viz[p]+1;
				if(i==B) return viz[i];
				}
  p++;
  }

}


int main()
{
 freopen("autobaza.in","r",stdin);
 freopen("autobaza.out","w",stdout);

 scanf("%d", &n);
 for(i=1;i<=n;i++)
   {
   for(j=1;j<=n;j++)
     c[i][j]=inf;
   c[i][i]=0;
   }

 for(i=1;i<=n;i++)
   {
   scanf("%d %d %d", &i,&j,&dr);
   d[i][j]=dr;
   t[i][j]=tj-ti;
   scanf("%d %d", &t[i], &t[j]);
   }



 for(k=1;k<=n;k++)
     for(i=1;i<=n;i++)
	  for(j=1;j<=n;j++)
	      if(a[i][k]+a[k][j]<a[i][j])
			       {
				a[i][j]=a[i][k]+a[k][j];
				}




return 0;
}