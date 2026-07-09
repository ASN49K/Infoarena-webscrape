#include<fstream.h>
int v[260][260], a[1030] ,b[1030],c[1030],i,j,n,m,max=0,k=0,x,y;
int main()
{
 ifstream f("cmlsc.in");
 ofstream g("cmlsc.out");

f>>n>>m;

 for(i=1;i<=n;i++)
  f>>a[i];

 for(i=1;i<=m;i++)
  f>>b[i];


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

for(i=k;i>=1;i--)
 g<<c[i]<<" ";

f.close();
g.close();
return 0;
}