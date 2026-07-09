#include <iostream>
#include <fstream>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int cmmdc(int a,int b)
{ int r;
    while(b) {r=a%b;
             a=b;
             b=r;}
             return a;
}

int main()
{ int n ,a, b;
  f>>n;
  while(n)
  {
      f>>a>>b;
      g<<cmmdc(a,b)<<"\n";
      n--;
  }
    return 0;
}
