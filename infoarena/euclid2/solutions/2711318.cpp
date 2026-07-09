#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int t,a,b;

  int cmmdc(int a, int b)
  {
       if(!b) return a;
       return cmmdc(b,a%b);
  }


  int main()
 {
  ifstream f("euclid2.in");
  ofstream g("euclid2.out");
 f>>t;
 for(int i=0; i<t-1; i++)
  {f>>a>>b;
  g<<cmmdc(a,b)<<"\n";
  }
  return (0);
  }
