#include <fstream>
#include <iostream>
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");


int a[1026],b[1026],c[1026],n,m,k=0,poz,p[1026],L[1026],best[1026],maxim=0,nr=1;

void afis(int x)
{if(p[x]>0) afis(p[x]);
 cout<<c[x]<<" ";}
void cit()
{int i,j,t=1;
 f>>n>>m;
 for(i=1;i<=n;i++) f>>a[i];
 for(i=1;i<=m;i++) f>>b[i];
 if(n<m) for(i=1;i<=m;i++)
         {for(j=t;j<=n;j++)
          if(b[i]==a[j]) {c[++k]=a[t]; t=j+1; j=n;}}
 else  for(i=1;i<=n;i++)
         {for(j=t;j<=m;j++)
          if(a[i]==b[j]) {c[++k]=b[j]; t=j+1; j=n;}}        }
int sir(int x)
{int p=0,u=nr,m=(p+u)/2;
 while(p<=u)
 {if(c[L[m]]<x && c[L[m+1]]>=x) return m;
  else if(c[L[m+1]]<x) {p=m+1; m=(p+u)/2;}
  else {u=m-1; m=(p+u)/2;}}
 return nr;}
int main()
{int i;
 cit();
 best[1]=L[1]=1; maxim=0;
 for(i=1;i<=k;i++)
 {poz=sir(c[i]);
  p[i]=L[poz];
  best[i]=poz+1;
  L[poz+1]=i;
  if(nr<poz+1) nr=poz+1;}
 for(i=1;i<=k;i++) if(best[i]>maxim) {maxim=best[i]; poz=i;}
 afis(poz);


      return 0;
}
