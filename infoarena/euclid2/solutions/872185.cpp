#include <iostream>
#include <fstream>
 using namespace std;
  int cmmdc(int a,int b)
  {  if (!b) return a;
    return cmmdc(b,a%b);
    }
  int main(void)
   { ifstream f("euclid2.in");
     ofstream g("euclid2.out");
     int a,b,t,i;
    f>>t;
    for(i=1;i<=t;i++)
     {   f>>a>>b;
    g<<cmmdc(a,b)<<"\n";
      }
      f.close();
    return 0;
    }