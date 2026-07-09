#include <iostream>
#include <fstream>

using namespace std;
int cmmdc(int x,int y){
  int z;
      while(y){
      z=x%y;
      x=y;
      y=z;
      }
    return x;
}
int main()
{int t,a,b;
   ifstream f("euclid2.in");
   ofstream g("euclid2.out");
      f>>t;
      while(t){
      f>>a>>b;
      g<<cmmdc(a,b)<<"\n";
      t--;
      }
    f.close();
    g.close();
    return 0;
}
