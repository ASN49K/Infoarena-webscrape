#include <fstream.h>
int a[1024][1024];
int main ()
{int n,m,i,j,x[1024],y[1024],v[2100],k;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
f>>n;
f>>m;
for(i=1; i<=n; i++)
   f>>x[i];
for(i=1; i<=m; i++)
   f>>y[i];
for(i=1; i<=n; i++)
   for(j=1; j<=m; j++)
      if(x[i]==y[j]) a[i][j]=a[i-1][j-1]+1;
      else if(a[i][j-1]>a[i-1][j]) a[i][j]=a[i][j-1];
	   else a[i][j]=a[i-1][j];
i=n;
j=m;
k=0;
while(i && j)
  { if(x[i]==y[j]) { v[++k]=x[i];
		    j--;
		    i--;}
    else if(a[i][j]==a[i-1][j]) i--;
	 else if(a[i][j]==a[i][j-1]) j--;
	 }
g<<k<<"\n";
for(i=k; i>=1; i--) g<<v[i]<<" ";
f.close();
g.close();
return 0;
}
