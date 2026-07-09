#include<fstream.h>
using namespace std;
int a,b;
int cmmdc()
{ int c;
  while(b!=0)
  { c=a%b;
    a=b;
	b=c;
  }
}
int main()
{ int t,i; 
  ifstream f("euclid2.in");
  ofstream g("euclid2.out");
  f>>t;
  for(i=1;i<=t;i++)
  { f>>a>>b; cmmdc(); g<<a<<'\n'; }
  f.close(); g.close();
  return 0;
}
