#include<fstream.h>
int max(int a,int b)
{
  if(a>b)return a;
  return b;
}

int main()
{
  ifstream f("cmlsc.in");ofstream g("cmlsc.out");
  int p,q,a[1025],b,i,x[1025],y[1025],j;
  f>>p>>q;
  for(i=1;i<=p;i++)f>>a[i];
  f>>b;for(i=1;i<=p;i++)if(b==a[i])x[i]=1;else x[i]=0;
  for(j=2;j<=q;j++)
  {
    f>>b;
    if(b==x[1])y[1]=1;else y[1]=0;
    for(i=2;i<=p;i++)if(b==a[i])y[i]=1+x[i-1];else y[i]=max(y[i-1],x[i]);
    for(i=1;i<=p;i++)x[i]=y[i];
  }
  g<<x[p];
  f.close();g.close();
  return 0;
}