#include<fstream.h>
int v[1025],d,s[1025][1025],i,j,n,m,x[1025],y[1025],k,e;
int main()
{ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
f>>n>>m;
for(i=1;i<=n;i++)
      f>>x[i];
for(i=1;i<=m;i++)
      f>>y[i];
for(i=0;i<=n;i++)
      s[i][0]=0;
for(j=0;j<=m;j++)
      s[0][j]=0;
for(i=1;i<=n;i++)
for(j=1;j<=m;j++)
      {s[i][j]=0;
      s[i][j]=s[i-1][j-1]+(x[i]==y[j])?1:0;
      if(s[i][j]<s[i-1][j])
             s[i][j]=s[i-1][j];
      if(s[i][j]<s[i][j-1])
             s[i][j]=s[i][j-1];}
g<<s[n][m]<<"\n";
k=s[n][m];
for(i=n;i>=1;i--)
for(j=m;j>=1;j--)
if(s[i][j]==k)
      v[k]=y[j],d=i-1,e=j-1;
for(i=k-1;i>=1;i--)
      {while(s[d-1][e]==i)
             d--;
      while(s[d][e-1]==i)
             e--;
      v[i]=x[d],d--,e--;}
for(i=1;i<=k;i++)
      g<<v[i]<<" ";             
g<<"\n";
f.close();
g.close();
return 0;}
