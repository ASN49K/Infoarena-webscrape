#include <iostream.h>
#include <fstream.h>

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int a[300],k, n,m, b[300], c[300][300], v[300];



void main()
{int i,j;
fin>>n>>m;
for (i=1;i<=n;i++) fin>>a[i];
for (i=1;i<=m;i++) fin>>b[i];

for (i=1;i<=n;i++)
 for (j=1;j<=m;j++)
  if (a[i]==b[j])
   c[i][j]=c[i-1][j-1]+1;
   else
    {c[i][j]=c[i-1][j];
     if (c[i][j]<c[i][j-1])
	c[i][j]=c[i][j-1];
    }

fout<<c[n][m]<<endl;

i=n;j=m;
k=c[n][m];

while (i>0 && j>0)
 if(a[i]==b[j])
   {v[k]=a[i];
    k--;
    i--; j--;
    }
   else
    if(c[i][j]==c[i][j-1]) j--;
      else i--;


for (i=1;i<=c[n][m];i++)
fout<<v[i]<<" ";

fout.close();
}
