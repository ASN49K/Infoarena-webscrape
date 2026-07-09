#include<fstream.h>
int a[1025],b[1025],k[1025][1025],d[1025];
int n,m,i,j,aux,max=0,x=1,y=1;
int main ()
{
	ifstream f("cmlsc.in");
	ofstream g("cmlsc.out");
	f>>n>>m;
   for(i=1;i<=n;i++)
   f>>a[i];
    for(i=1;i<=n;i++)
   f>>b[i];
  for(i=1;i<=n;i++)
   for(j=1;j<=m;j++)
   if(a[i]==b[j])
{
	k[i][j]=k[i-1][j-1]+1;
    if(k[i][j]>max)
{
	max=k[i][j];
	x=i;
	y=j;
	}
}
else
      if(k[i-1][j]>k[i][j-1]) 
	  k[i][j]=k[i-1][j];
else 
	  k[i][j]=k[i][j-1];
     aux=max;
while(max!=0)
	
   if(b[x]==a[y])
{
	d[max]=a[x];x--;y--;max--;}
else
    if(k[x-1][y]>k[x][y-1])
	x--;
else 
	y--;
g<<aux<<'\n';
for(i=1;i<=aux;i++)
g<<d[i]<<" ";
return 0;

}