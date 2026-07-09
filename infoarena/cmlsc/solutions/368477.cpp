#include<fstream.h>

int i,j,n,m,k,v[1025],d[1025][1025],b[1025],a[1025];

int main()
{
 ifstream f("cmlsc.in");
 ofstream g("cmlsc.out");
 f>>m>>n;
 for(i=1;i<=m;i++)f>>a[i];
 for(i=1;i<=n;i++)f>>b[i];
 for(i=1;i<=m;i++)for(j=1;j<=n;j++)if(a[i]==b[j])d[i][j]=d[i-1][j-1]+1;
				   else if(d[i][j-1]>d[i-1][j])d[i][j]=d[i][j-1];
					else d[i][j]=d[i-1][j];
 i=m;j=n;
 k=1;
 while(i>0&&j>0)
  if(a[i]==b[j])
   {
    v[k++]=a[i];
    i--;
    j--;
    }
  else if(d[i][j-1]<d[i-1][j])j--;
       else i--;
  g<<k-1<<'\n';

  for(i=k-1;i;i--)g<<v[i]<<' ';
  return 0;
  }

