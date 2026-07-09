#include<fstream.h>
int euclid(int a,int b)
{
 int r;
 r=a%b;
 while(r)
 {
  a=b;
  b=r;
  r=a%b;
 }
 return b;
}

int main()
{
 ifstream f("euclid2.in");
 ofstream g("euclid2.out");
 int i,n,x,y,s;
 f>>n;
 for(i=1;i<=n;i++)
 { 
  f>>x>>y;;
  s=euclid(x,y);
  g<<s<<'\n';
 } 
  f.close();
  g.close();
  return 0;
 
}