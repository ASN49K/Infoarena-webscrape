#include<iostream>
#include<fstream>
using namespace std;
int t,a,b;

  int cmmdc(int a, int b)
  {
       if(!b) return a;
       return cmmdc(b,a%b);
  }


  int main()
 {
  ifstream f("date.in");
  ofstream g("date.out");
 f>>t;
 for(int i=1;i<=t;i++)
  {f>>a>>b;
  g<<cmmdc(a,b)<<"\n";
  }
  return (0);
  }
