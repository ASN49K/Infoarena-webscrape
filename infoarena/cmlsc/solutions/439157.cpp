#include<fstream.h>
int n,m,k=0,x[1000],y[1000],c[1000],a[1000][1000];
int max(int f, int g)
{
if(f>=g) return f;
   else return g;
}
void umple()
{
int i,j;
for(i=1;i<=n;i++)
for(j=1;j<=m;j++)
{a[i][j]=0;
 if(x[i]==y[j]) {a[i][j]=1+max(a[i][j-1],a[i-1][j]);
		 k++;
		 if(c[k-1]!=i) c[k]=i;
		 }
	      else  a[i][j]=max(a[i][j-1],a[i-1][j]);
}
}
int main()
{
int i,j;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
in>>n;
in>>m;
for(i=1;i<=n;i++)
in>>x[i];
for(j=1;j<=m;j++)
in>>y[j];
umple();
out<<a[n][m]<<"\n";
for(i=1;i<=k;i++)
out<<x[c[i]]<<" ";
in.close();
out.close();
return 0;
}