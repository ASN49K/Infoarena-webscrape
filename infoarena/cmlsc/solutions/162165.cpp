#include<fstream.h>
#define dim 1025
int a[dim],b[dim],c[dim],mat[dim][dim],cont;
int main()
{ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,m,i,j;
f>>n>>m;
for(i=1;i<=n;i++) f>>a[i];
for(i=1;i<=m;i++) f>>b[i];
f.close();
for(i=1;i<=n;i++)
 for(j=1;j<=m;j++)
  if(a[i]==b[j])
   mat[i][j]=mat[i-1][j-1]+1;
   else
    {if(mat[i][j-1]>mat[i-1][j]) mat[i][j]=mat[i][j-1];
      else mat[i][j]=mat[i-1][j];
    }
for(i=n,j=m;i;)
 if(a[i]==b[j]) {c[++cont]=a[i];i--;j--;}
  else
   {if(mat[i][j-1]>mat[i-1][j]) j--;
     else i--;
   }
g<<cont<<'\n';
for(i=cont;i>=1;i--) g<<c[i]<<" ";
g<<'\n';
g.close();
return 0;
}