#include<fstream.h>
#define MAX 1025
ofstream g("cmlsc.out");
int x[MAX][MAX],a[MAX],b[MAX],sol[MAX];

int max(int a,int b)
{
  if(a>b)return a;
  return b;
}

void urma2(int i,int j)
{
  int k=0;
  while(i && j)
    if(b[i]==a[j]){sol[++k]=b[i];i--;j--;}
    else if(x[i][j-1]>x[i-1][j])j--;
	 else i--;
  while(k)g<<sol[k--]<<' ';
}

int main()
{
  ifstream f("cmlsc.in");
  int p,q,i,j;
  f>>p>>q;
  for(i=1;i<=p;i++)f>>a[i];
  for(i=1;i<=q;i++)
  {
    f>>b[i];
    for(j=1;j<=p;j++)
      if(b[i]==a[j])x[i][j]=1+x[i-1][j-1];
      else x[i][j]=max(x[i-1][j],x[i][j-1]);
  }
  g<<x[q][p]<<'\n';
  urma2(q,p);
  f.close();g.close();
  return 0;
}