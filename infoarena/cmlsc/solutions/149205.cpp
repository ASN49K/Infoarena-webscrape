#include<fstream.h>
#define dim 1024
int A[dim],B[dim];
int v[dim],a,b,w[dim];
int main()
{ifstream f("cmlsc.in");
f>>a>>b;
//char x,ok;
int i,ok,j,jj;
for(i=1;i<=a;i++) f>>A[i];
/* {f>>x;
  A[i]=(int)x;
 }*/
for(i=1;i<=b;i++) f>>B[i];
/* {f>>x;
  B[i]=(int)x;
 }*/
f.close();
i=0;j=1;
while(i<a)
{i++;ok=0;
for(jj=j;jj<=b;jj++)
 if(A[i]==B[jj])
  {ok=1;
   j=jj+1;
   v[i]=v[i-1]+1;
   break;}
if(!ok)v[i]=v[i-1];
ok=1;
}

i=0;j=1;
while(i<b)
{i++;ok=0;
for(jj=j;jj<=a;jj++)
 if(B[i]==A[jj])
  {ok=1;
   j=jj+1;
   w[i]=w[i-1]+1;
   break;}
if(!ok)w[i]=w[i-1];
ok=1;
}
if(v[a]>w[b])
{
ofstream g("cmlsc.out");
g<<v[a]<<'\n';
for(i=1;i<=a;i++)
 if(v[i]!=v[i-1])g<<A[i]<<" ";
g<<'\n';
g.close(); }
else
{
ofstream g("cmlsc.out");
g<<w[b]<<'\n';
for(i=1;i<=b;i++)
 if(w[i]!=w[i-1])g<<B[i]<<" ";
g<<'\n';
g.close(); }
return 0;
}