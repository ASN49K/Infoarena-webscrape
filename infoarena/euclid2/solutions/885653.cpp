#include<iostream>
#include<fstream>
using namespace std;
long long dc,a,b,n,i;
int cmmdc(long long a,long long b)
{ while(a!=b)
{ if (a>=b) a-=b;
else b-=a;}
return a;
}
int main()
{ ifstream f("euclid2.in");
  ofstream g("euclid2.out");
  f>>n; i=0;
  while(i!=n)
  { f>>a>>b;
  dc=cmmdc(a,b);
  g<<dc<<'\n';
  i=i+1;
  }
  f.close();
  g.close();
  return 0;
}