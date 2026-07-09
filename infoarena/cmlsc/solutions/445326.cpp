#include<fstream.h>

int a1[1025],a2[1025];
int m[1025][1025],c[1025];
int n1,n2,i,j,aux,max=0,x=1,y=1;

int main ()
{
	ifstream f("cmlsc.in");
	ofstream g("cmlsc.out");
	f>>n1>>n2;
	
for(i=1;i<=n1;i++)
f>>a1[i];

for(i=1;i<=n2;i++)
f>>a2[i];

for(i=1;i<=n1;i++)
   for(j=1;j<=n2;j++)

if(a2[j]==a1[i])
{
	m[i][j]=m[i-1][j-1]+1;
	if(m[i][j]>max)
		{
			max=m[i][j];x=i;y=j;
		}
}
else

if(m[i-1][j]>m[i][j-1])
	m[i][j]=m[i-1][j];
else m[i][j]=m[i][j-1];  	
	   
   aux=max;

while(max!=0)
if(a1[x]==a2[y])
{c[max]=a1[x];x--;y--;max--;}
else
if(m[x-1][y]>m[x][y-1])  x--;
else y--;
g<<aux<<'\n';
for(i=1;i<=aux;i++)
g<<c[i]<<" ";


return 0;
}